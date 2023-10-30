#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "semantic.h"

bool equal_string(char*a1, char*a2){
	if(strcmp(a1,a2) == 0){
		if(DEBUG_FLAG){
			printf("equal string a1:%s and a2:%s \n", a1, a2);
		}
		return true;
	}
	if(DEBUG_FLAG){
		printf("not equal string a1:%s and a2:%s \n", a1, a2);
        }
	return false;
}
//类型一致性
bool equal_Type(Type T1, Type T2){
	if(T1 == NULL && T2 == NULL){
		return true;	// 都为空一致
	}
	if((T1 == NULL && T2 != NULL) || (T1 != NULL && T2 == NULL)){
		return false;
	}
	if(T1->kind == BASIC){
		if(T2->kind == BASIC && (T1->inform.basic == T2->inform.basic)){
			if(DEBUG_FLAG){
				printf("T1 and T2 are both BASIC");
			}
			return true; // 基本类型相同
		}
		if(DEBUG_FLAG){
			printf("T1 is BASIC but T2 is not\n");
		}
		return false;// 基本类型不同
	}
	if(T1->kind == ARRAY){ // 逐个比对数组元素类型
		if(T2->kind == ARRAY){
			if(DEBUG_FLAG){
                                printf("T1 and T2 are both ARRAY");
                        }
			return equal_Type(T1->inform.array.type, T2->inform.array.type);
		}
		if(DEBUG_FLAG){
                        printf("T1 is ARRAY but T2 is not\n");
                }
		return false;
	}
	if(T1->kind == STRUCTURE){
		if(T2->kind == STRUCTURE){
			if(DEBUG_FLAG){
                                printf("T1 and T2 are both STRUCTURE");
                        }
			return equal_string(T1->inform.structure->name, T2->inform.structure->name);
		}
		if(DEBUG_FLAG){
                        printf("T1 is STRUCTURE but T2 is not\n");
                }
                return false;
	}
}
//函数参数一致性
bool equal_Param(FieldList p1,FieldList p2){
	while(p1 != NULL && p2 != NULL){
		if(!equal_Type(p1->type, p2->type)){
			if(DEBUG_FLAG){
				printf("%s is not equal type with %s\n", p1->name, p2->name);
			}
			return false;
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	if(p1 == NULL && p2 == NULL){
		return true;	// 检查结束，参数类型一致
	}
	return false;
}
// 语义分析入口函数
void semantic_check_start(struct Node* Root){
	initHashTable();
	// 遍历语法树中的ExtDefList节点
	ExtDefList(Root->firstChild);
}
// 判断是否使用了指定的产生式
bool Use_This_Rule(struct Node* node, int index, ...){
	va_list stringlist;
	va_start(stringlist, index);
	bool if_this = true;
	struct Node* curNode = node->firstChild;
	for(int i = 0; i < index; i++, curNode = curNode->bro){
		if(curNode = NULL){
			if_this = false;
			break;
		}
		char* nowstr = va_arg(stringlist, char*);
		if(DEBUG_FLAG){
			printf("nowNode is %s and curNode is %s\n",nowstr, curNode->nodeName);
		}
		if(!equal_string(nowstr, curNode->nodeName)){
			if_this = false;
			break;
		}
	}
	va_end(stringlist);
	if(curNode != NULL)
		if_this = false;
	return if_this;

}
//全局语法单元遍历
void ExtDefList(struct Node *node){
	if(DEBUG_FLAG){
		printf("Go in ExtDefList analyse\n");
	}
	if(node == NULL)
		return;
	// 遍历第一个节点
	ExtDef(node->firstChild);
	// 遍历兄弟节点
	ExtDefList(node->firstChild->bro);

}
void ExtDef(struct Node* node)//局部语句块遍历
{
	if(DEBUG_FLAG){
                printf("Go in ExtDef analyse\n");
        }
	//判断节点是否为空
	if(node == NULL)
		return;
	Type type = Specifier(node->firstChild);
	if(Use_This_Rule(node, 3, "Specifier", "ExtDecList", "SEMI")){
		if(DEBUG_FLAG)	printf("ExtDef := Specifier ExtDecList SEMI \n");
		ExtDecList(node->firstChild->bro, type);
	}
	else if(Use_This_Rule(node, 2, "Specifier", "SEMI")){
		if(DEBUG_FLAG)	printf("ExtDef := Specifier SEMI \n");
	}
	else if(Use_This_Rule(node, 3, "Specifier", "FunDec", "CompSt")){
		if(DEBUG_FLAG)	printf("ExtDef := Specifier FunDec CompSt\n");
		type->possition = RIGHT;	//函数返回值均为右值
		FunDec(node->firstChild->bro, type);
		CompSt(node->firstChild->bro->bro, type);
	}
	else{
		printf("Error! No this analyse!\n");
	}
}

Type Specifier(struct Node*node){
	if(DEBUG_FLAG){
                printf("Go in Specifier analyse\n");
        }
        //判断节点是否为空
        if(node == NULL)
                return	NULL;
	if(Use_This_Rule(node, 1, "TYPE")){
		if(DEBUG_FLAG)  printf("Specifier := TYPE \n");
		return analyseType(node->firstChild);
	}
	else if(Use_This_Rule(node, 1, "StructSpecifier")){
		if(DEBUG_FLAG)  printf("Specifier := StructSpecifier \n");
		return StructSpecifier(node->firstChild);
	}
	else{
                printf("Error! No this analyse!\n");
        }

}
Type analyseType(struct Node*node){
	if(DEBUG_FLAG){
                printf("Go in Type analyse\n");
        }
        //判断节点是否为空
        if(node == NULL)
                return NULL;
	Type newType = (Type)malloc(sizeof(struct Type_));
	if(equal_string(node->Valstr, "FLOAT")){
		if(DEBUG_FLAG)	printf("This type is FLOAT!\n");
		newType->kind = BASIC;
		newType->inform.basic = 0;
		newType->possition = BOTH;
	}
	else if(equal_string(node->Valstr, "INT")){
		if(DEBUG_FLAG)  printf("This type is FLOAT!\n");
                newType->kind = BASIC;
                newType->inform.basic = 1;
                newType->possition = BOTH;
	}
	else{
                printf("Error! No this analyse!\n");
        }
	return newType;
}
void ExtDecList(struct Node*node, Type ntype){
	if(DEBUG_FLAG){
		printf("Go in ExtDecList analyse\n");
	}
	//判断节点是否为空
        if(node == NULL)
                return;
	if(Use_This_Rule(node, 1, "VarDec")){
		if(DEBUG_FLAG)	printf("ExtDecList := VarDec \n");
		if(ntype->kind == STRUCTURE)
			VarDec(node->firstChild, ntype, 1);
		else
			VarDec(node->firstChild, ntype, 0);
	}
	else if(Use_This_Rule(node, 3, "VarDec", "COMMA", "ExtDecList")){
		if(DEBUG_FLAG)  printf("ExtDecList := VarDec COMMA ExtDecList \n");
		if(ntype->kind == STRUCTURE)    
                        VarDec(node->firstChild, ntype, 1);
                else
                        VarDec(node->firstChild, ntype, 0);
		ExtDecList(node->firstChild->bro->bro, ntype);
	}
	else{
		printf("Error!No this analyse!\n");
	}
}
void CompSt(struct Node *node, Type ntype){
	if(DEBUG_FLAG){
                printf("Go in CompSt analyse\n");
        }
        //判断节点是否为空
        if(node == NULL)
                return;
	if(Use_This_Rule(node, 4, "LC", "DefList", "StmtList", "RC")){
                if(DEBUG_FLAG)  printf("CompSt := LC DefList StmtList RC\n");
                DefList(node->firstChild->bro, 0);
		StmtList(node->firstChild->bro->bro, ntype);
        }
	else{
		printf("Error!No This analyse!\n");
	}
}
void DefList(struct Node*node, int ifstruct){
	if(DEBUG_FLAG){
                printf("Go in DefList analyse\n");
        }
        //判断节点是否为空
        if(node == NULL)
                return;
	Def(node->firstChild. ifstruct);
	DefList(node->firstChild->bro, ifstruct);
}
void Def(struct Node*node, int ifstruct){
	if(DEBUG_FLAG){
                printf("Go in Def analyse\n");
        }
        //判断节点是否为空
        if(node == NULL)
                return;
	if(Use_This_Rule(node, 3, "Specifier", "DecList", "SEMI")){
		if(DEBUG_FLAG)	printf("Def := Specifier DecList SEMI\n");
		Type type = Specifier(node->firstChild);
		DecList(node->firstChild->bro, type, ifstruct);
	}
	else{
                printf("Error!No This analyse!\n");
        }
}
FieldList DecList(struct Node*node, Type ntype,int ifstruct){
	if(DEBUG_FLAG){
                printf("Go in DecList analyse\n");
        }
        //判断节点是否为空
        if(node == NULL)
                return;
	if(Use_This_Rule(node, 1, "Dec")){
		if(DEBUG_FLAG)	printf("DecList := Dec\n");
		FieldList newField;
	       	newField = Dec(node->firstChild, ntype, ifstruct);
		return newField;
	}
	else if(Use_This_Rule(node, 3, "Dec", "COMMA", "DecList")){
		if(DEBUG_FLAG)	printf("DecList := Dec COMMA DecList\n");
		FieldList newField;
		newField = Dec(node->firstChild, ntype, ifstruct);
		FieldList f;
		for(f = newField; f->next!=NULL; f = f->next);
		f->next = DecList(node->firstChild->bro->bro, ntype, ifstruct);
		return newField;
	}
	else{
                printf("Error!No This analyse!\n");
        	return NULL;
	}
}
FieldList Dec(struct Node*node, Type ntype, int ifstruct){
	if(DEBUG_FLAG){
                printf("Go in Dec analyse\n");
        }
        //判断节点是否为空
        if(node == NULL)
                return;
        if(Use_This_Rule(node, 1, "VarDec")){
                if(DEBUG_FLAG)  printf("Dec := VarDec\n");
                return VarDec(node->firstChild, ntype, ifstruct);
        }
        else if(Use_This_Rule(node, 3, "VarDec", "ASSIGNOP", "Exp")){
                if(DEBUG_FLAG)  printf("Dec := VarDec ASSIGNOP Exp\n");
                FieldList newField = VarDec(node->firstChild, ntype, ifstruct);
                Type ExpType = Exp(node->firstChild->bro->bro);
		//错误类型5
		if(!equal_Type(ntype, ExpType)){
			printError(5, node->lineNum, "left and right type is not equal!");
			return NULL;
		}
		//错误类型15
		if(ifstruct){
			printError(15, node->firstChild->bro->lineNum, "定义时对域进行初始化");
			return NULL;
		}
		return newField;
        }
        else{
                printf("Error!No This analyse!\n");
        	return NULL;
	}
}
void StmtList(struct Node*node, Type ntype){
	if(DEBUG_FLAG){
                printf("Go in StmtList analyse\n");
        }
        //判断节点是否为空
        if(node == NULL)
                return;
	Stmt(node->firstChild, ntype);
	StmtList(node->firstChild->bro, ntype);
}
void Stmt(struct Node *node, Type ntype){
	if(DEBUG_FLAG){
                printf("Go in Stmt analyse\n");
        }
        //判断节点是否为空
        if(node == NULL)
                return;
	struct Node* child = node->firstChild;
	while(child!=NULL){
		if(equal_string("Exp", child->nodeName)){
			if(DEBUG_FLAG)  printf("Go in Stmt's Exp\n");
			Exp(node);
		}
		else if(equal_string("CompSt", child->nodeName)){
			if(DEBUG_FLAG)  printf("Stmt := CompSt\n");
			CompSt(child, ntype);
		}
		else if(equal_string("RETURN", child->nodeName)){
			if(DEBUG_FLAG)  printf("Stmt := RETURN Exp SEMI\n");
			Type expType = Exp(child->firstChild);
			expType->possition = RIGHT;
			//错误类型8
			if(!equal_Type(expType, ntype)){
				printError(8, child->lineNum, "RETURN type is wrong!");
			}
		}
		else if(equal_string("WHILE", child->nodeName)){
			if(DEBUG_FLAG)  printf("Stmt := WHILE LP Exp RP Stmt\n");
			Exp(child->firstChild->bro);
			Stmt(child->firstChild->bro->bro->bro, ntype);
		}	
		child = child->bro;
	}
}
Type StructSpecifier(struct Node* node){
	if(DEBUG_FLAG){
                printf("Go in StructSpecifier analyse\n");
        }
        //判断节点是否为空
        if(node == NULL)
                return;
	//是结构体定义且名字存在
	if(Use_This_Rule(node, 5, "STRUCT", "OptTag", "LC", "DefList", "RC")){
		if(DEBUG_FLAG)	printf("StructSpecifier := STRUCT OptTag LC DefList RC\n");
		Type structType = (Type)malloc(sizeof(struct Type_));
		char* nodename = node->firstChild->bro->firstChild->Valstr;
		structType->inform.structure->name = nodename;
		structType->kind = STRUCTURE;
		structType->inform.structure->next = NULL;
		structType->possition = BOTH;
		bool canInsert = true;
		//错误类型16
		if(find(nodename)){
			printError(16, node->firstChild->bro->lineNum, "结构体的名字与定义过的结构体或变量的名字重复");
			return NULL;
		}
		DefList(node->firstChild->bro->bro->bro, 1);
		if(canInsert){
			if(DEBUF_FLAG)	printf("insert struct and the name is %s\n", nodename);
			insert(nodename, structType);
		}
		return structType;
	}
	else if(Use_This_Rule(node, 4, "STRUCT", "LC", "DefList", "RC")){
                if(DEBUG_FLAG)  printf("StructSpecifier := STRUCT OptTag(= NULL) LC DefList RC\n");
                Type structType = (Type)malloc(sizeof(struct Type_));
                char* nodename = NULL;
                structType->inform.structure->name = nodename;
                structType->kind = STRUCTURE;
                structType->inform.structure->next = NULL;
                structType->possition = BOTH;
                bool canInsert = true;
                DefList(node->firstChild->bro->bro->bro, 1);
                if(canInsert){
                        if(DEBUF_FLAG)  printf("insert struct and the name is %s\n", nodename);
                        insert(nodename, structType);
                }
                return structType;
        }
	else if(Use_This_Rule(node, 2, "STRUCT", "Tag")){
		if(DEBUG_FLAG)	printf("StructSpecifier := STRUCT Tag\n");
		Type Tagtype = Type_get(node->firstChild->bro->firstChild);
		if(Tagtype == NULL){
			printError(17, node->firstChild->bro->lineNum, "直接使用未定义过的结构体来定义变量");
			return NULL;
		}
		return Tagtype;
	}
	else{
                printf("Error!No this analyse!\n");
		return NULL;
        }
}

Function FunDec(struct Node*node, Type ntype){
	if(DEBUG_FLAG){
                printf("Go in FunDec analyse\n");
        }
        //判断节点是否为空
        if(node == NULL)
                return;
	Function newfunc = (Function)malloc(sizeof(struct Function_));
	struct Node* child = node->firstChild;
	newfunc->name = child->Valstr;
	newfunc->line = child->lineNum;
	newfunc->type = ntype;
	//错误类型4
	if(findFunc(newfunc) != 0){
		printError(4, child->lineNum, child->Valstr);
		return NULL;
	}
	if(Use_This_Rule(node, 4, "ID", "LP", "VarList", "RP")){
		if(DEBUG_FLAG)  printf("FunDec := ID LP VarList RP \n");
		FieldList nextField = VarList(node->firstChild->bro->bro, ntype);
		newfunc->next = nextField;
	}
	else if(Use_This_Rule(node, 3, "ID", "LP", "RP")){
		if(DEBUG_FLAG)  printf("FunDec := ID LP RP \n");
		newfunc->next = NULL;
	}
	else{
		printf("Error!No this analyse!\n");
	}
	return newfunc;
}
FieldList VarList(struct Node* node, Type ntype){
	if(DEBUG_FLAG){
                printf("Go in VarList analyse\n");
        }
        //判断节点是否为空
        if(node == NULL)
                return;
	if(Use_This_Rule(node, 3, "ParamDec", "COMMA", "VarList")){
		if(DEBUG_FLAG)	printf("VarList := ParamDec COMMA VarList\n");
		FieldList newField = ParamDec(node->firstChild);
		FieldList f;
		for(f = newField; f->next != NULL; f = f->next);
		f->next = VarList(node->firstChild->bro->bro, ntype);
		return newField;
	}
	else if(Use_This_Rule(node, 1, "ParamDec")){
		if(DEBUG_FLAG)	printf("VarList := ParamDec\n");
		FieldList newField = ParamDec(node->firstChild);
		newField->next = NULL;
		return newField;
	}
	else{
                printf("Error!No this analyse!\n");
        	return NULL;
	}
}
FieldList ParamDec(struct Node*node){
	if(DEBUG_FLAG){
                printf("Go in ParamDec analyse\n");
        }
        //判断节点是否为空
        if(node == NULL)
                return;
	if(Use_This_Rule(node, 2, "Specifier", "VarDec")){
		if(DEBUG_FLAG)	printf("ParamDec := Specifier VarDec\n");
		FieldList newField;
		Type newType = Specifier(node->firstChild);
		newField = VarDec(node->firstChild->bro, newType, 0);
		return newField;
	}
	else if(Use_This_Rule(node, 1, "Specifier")){
		if(DEBUG_FLAG)  printf("ParamDec := Specifier VarDec\n");
                Type newType = Specifier(node->firstChild);
		FieldList newField = (FieldList)malloc(sizeof(struct FieldList_));
		newField->type = newType;
		newField->next = NULL;
		return newField;
	}
	else{
                printf("Error!No this analyse!\n");
                return NULL;
        }
}

FieldList VarDec(struct Node*node, Type ntype, int ifstruct){
	if(DEBUG_FLAG){
                printf("Go in VarDec analyse\n");
        }
        //判断节点是否为空
        if(node == NULL)
                return;
	if(Use_This_Rule(node, 1, "ID")){
		if(DEBUG_FLAG)	printf("VarDec := ID\n");
		FieldList newField = (FieldList)malloc(sizeof(struct FieldList_));
                newField->type = ntype;
                newField->name = node->firstChild->Valstr;
                newField->next = NULL;
		//错误类型3
		if((ifstruct == 0) && find(node->firstChild->Valstr)){
			printError(3, node->firstChild->lineNum, "变量出现重复定义，或变量与前面定义过的结构体名字重复");
			return newField;
		}
		//错误类型15
		if(ifstruct && find(node->firstChild->Valstr)){
			printError(15, node->firstChild->lineNum, "结构体中域名重复定义");
			return newField;
		}
		insert(newField->name, ntype);
		return newField;
	}
	else if(Use_This_Rule(node, 4, "VarDec", "LB", "INT", "RB")){
		if(DEBUG_FLAG)	printf("VarDec := VarDec LB INT RB\n");
		Type newArrayType = (Type)malloc(sizeof(struct Type_));
		newArrayType->kind = ARRAY;
		newArrayType->array.type = ntype;
		newArrayType->array.size = node->firstChild->bro->bro->Valint;
		return VarDec(node->firstChild, newArrayType);
	}
	else{
                printf("Error!No this analyse!\n");
                return NULL;
        }

}
Type Exp(struct Node*node){
	struct Node*Children = node->firstChild;
	if(equal_string(Children->nodeName, "ID")){
		//错误类型1
		if(Children->bro == NULL){
			if(DEBUG_FLAG)	printf("Exp := ID\n");
			if(find(Children->Valstr) == 0){
				printError(1, Children->lineNum, Children->Valstr);
				return NULL;
			}
			else{
				Type nodeType = Type_get(Children);
				return nodeType;
			}
		}
		//错误类型2
		else if(Use_This_Rule(node, 4, "ID", "LP", "Args", "RP")){
			if(DEBUG_FLAG)  printf("Exp := ID LP Args RP\n");
			Type typeFunc = Type_get(Children);
			if(typeFunc == NULL){
				printError(2, Children->lineNum, Children->Valstr);
				return NULL;
			}
			//错误类型11
			if(typeFunc->kind != FUNCTION){
				printError(11, Children->lineNum, "对普通变量使用“(…)”或“()”操作符");
				return NULL;
			}
			FieldList param = Args(Children->bro->bro);
			//错误类型9
			if(!equal_Param(param, typeFunc->inform.function->next)){
				printError(9, Children->bro->bro->lineNum, "The Args are not equal");
				return NULL;
			}
			return typeFunc;
		}
		else if(Use_This_Rule(node, 3, "ID", "LP", "RP")){
			if(DEBUG_FLAG)  printf("Exp := ID LP RP\n");
                        Type typeFunc = Type_get(Children);
			//错误类型2
                        if(typeFunc == NULL){
                                printError(2, Children->lineNum, Children->Valstr);
                                return NULL;
                        }
			//错误类型11
			if(typeFunc->kind != FUNCTION){
                                printError(11, Children->lineNum, "对普通变量使用“(…)”或“()”操作符");
                                return NULL;
                        }
			//错误类型9
			if(typeFunc->inform.function->next!=NULL){
				printError(9, Children->bro->bro->lineNum, "The Args are not equal");
				return NULL;
			}
			return typeFunc;
		}
	}
	else if(Use_This_Rule(node, 3, "Exp", "ASSIGNOP", "Exp")){
		if(DEBUG_FLAG)	printf("Exp := Exp ASSIGNOP Exp\n");
		Type LeftExp = Exp(Children);
		Type RightExp = Exp(Children->bro->bro);
		//错误类型5
		if(!equal_Type(LeftExp, RightExp)){
			printError(5, Children->bro->lineNum, "left and right type is not equal!");
			return NULL;
		}
		//错误类型6
		if(LeftExp != NULL && LeftExp->possition == RIGHT){// 右值
			printError(6, Children->bro->lineNum, "left possition is RIGHT but need to be LEFT or BOTH!");
			return NULL;
		}
		if(LeftExp == NULL)	return RightExp;
		return LeftExp;
	}
	else if(equal_string(Children->nodeName, "MINUS")){
		if(DEBUG_FLAG)	printf("Exp := MINUS Exp\n");
		Type ExpType = Exp(Children->bro);
		//错误类型7
		if(ExpType->kind != BASIC){
			printError(7, Children->lineNum, "the expType after MINUS is wrong!");
		}
		return ExpType;	
	}
	else if(Use_This_Rule(node, 3, "Exp", "AND", "Exp")||Use_This_Rule(node, 3, "Exp", "OR", "Exp")||Use_This_Rule(node, 3, "Exp", "RELOP", "Exp")){
		if(DEBUG_FLAG)	printf("Exp := Exp AND/OR/RELOP Exp\n");
		Type LeftExp = Exp(Children);
                Type RightExp = Exp(Children->bro->bro);
		//错误类型7
                if(!equal_Type(LeftExp, RightExp)){
                        printError(7, Children->bro->lineNum, "left and right type is not equal!");
                        return NULL;
                }
		Type newType = (Type)malloc(sizeof(struct Type_));
		newType->kind = BASIC;
		newType->inform.basic = 1;
		newType->possition = RIGHT;
		return newType;
	}
	else if(Use_This_Rule(node, 3, "Exp", "PLUS", "Exp")||Use_This_Rule(node, 3, "Exp", "MINUS", "Exp")||Use_This_Rule(node, 3, "Exp", "STAR", "Exp")||Use_This_Rule(node, 3, "Exp", "DIV", "Exp")){
                if(DEBUG_FLAG)  printf("Exp := Exp PLUS/MINUS/STAR/DIV Exp\n");
                Type LeftExp = Exp(Children);
                Type RightExp = Exp(Children->bro->bro);
		//错误类型7
                if(!equal_Type(LeftExp, RightExp)){
                        printError(7, Children->bro->lineNum, "left and right type is not equal!");
                        return NULL;
                }
                if(LeftExp == NULL)     return RightExp;
		return LeftExp;
	}
	else if(Use_This_Rule(node, 4, "Exp", "LB", "Exp", "RB")){
		if(DEBUG_FLAG)  printf("Exp := Exp LB Exp RB\n");
		Type ArrayType = Exp(Children);
		Type indexType = Exp(Children->bro->bro);
		//错误类型10
		if(ArrayType->kind != ARRAY){
			printError(10, Children->lineNum, "对非数组型变量使用“[…]”（数组访问）操作符");
			return NULL;
		}
		//错误类型12
		if(indexType->kind != BASIC || indexType->inform.basic != 1){
			printError(12, Children->lineNum, "数组访问操作符“[…]”中出现非整数");
			return NULL;
		}
		return ArrayType->inform.array.type;
	}
	else if(Use_This_Rule(node, 3, "Exp", "DOT", "ID")){
		if(DEBUG_FLAG)  printf("Exp := Exp DOT ID\n");
		Type LeftType = Exp(Children);
		//错误类型13
		if(LeftType->kind != STRUCTURE){
			printError(13, Children->lineNum, "对非结构体型变量使用“.”操作符");
			return NULL;
		}
		Type idType = Struct_Type_get(LeftType, Children->bro->bro->Valstr);
		//错误类型14
		if(idType == NULL){
			printError(14, Children->bro->bro->lineNum, "访问结构体中未定义过的域");
			return NULL;
		}
		return idType;
	}

}
Type Type_get(struct Node*node){
	if(equal_string(node->nodeName, "ID")){
		int HashNum = time33_hash(node->Valstr);
		HashNode curNode = gTable[HashNum];
		while(curNode != NULL){
			if(strcmp(curNode->name, name) == 0){
				return curNode->type;
			}
			curNode = curNode->next;
		}
	}
	return NULL;
}
bool findFunc(Function func){
	int HashNum = time33_hash(func->name);
	HashNode curNode = gTable[HashNum];
	while(curNode != NULL){
		if(strcmp(curNode->name, name) == 0){
			return true;
		}
		curNode = curNode->next;
	}
	return false;
}
Type Struct_Type_get(Type structType, char* name){
	FieldList nowField = structType->inform.structure->next;
	while(nowField != NULL){
		if(equal_string(nowField->name, name)){
			return nowField->type;
		}
		nowField = nowField->next;
	}
	return NULL;
}
