#include <stdio.h>
#include <string.h>
#include "syntax.tab.h"


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
			printf("T1 is BASIC but T2 is not\n")
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
                        printf("T1 is ARRAY but T2 is not\n")
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
                        printf("T1 is STRUCTURE but T2 is not\n")
                }
                return false;
	}
}
//函数参数一致性
bool equal_Param(FieldList p1,FieldList p2){
	while(p1 != NULL && p2 != NULL){
		if(!equal_Type(p1, p2)){
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
			printf("nowNode is %s and curNode is %s\n",nowNode->nodeName, curNode->nodeName);
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
                return;
	if(Use_This_Rule(node, 1, "TYPE")){
		if(DEBUG_FLAG)  printf("Specifier := TYPE \n");
		return analyseType(node->firstChild);
	}
	else if(Use_Thit_Rule(node, 1, "StructSpecifier")){
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
                return;
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
		VarDec(node->firstChild, ntype);
	}
	else if(Use_This_Rule(node, 3, "VarDec", "COMMA", "ExtDecList")){
		if(DEBUG_FLAG)  printf("ExtDecList := VarDec COMMA ExtDecList \n");
		VarDec(node->firstChild, ntype);
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
void DefList(struct Node*node, int num){
	if(DEBUG_FLAG){
                printf("Go in DefList analyse\n");
        }
        //判断节点是否为空
        if(node == NULL)
                return;
	Def(node->firstChild);
	DefList(node->firstChild->bro);
}
void Def(struct Node*node){
	if(DEBUG_FLAG){
                printf("Go in Def analyse\n");
        }
        //判断节点是否为空
        if(node == NULL)
                return;
	if(Use_This_Rule(node, 3, "Specifier", "DecList", "SEMI")){
		if(DEBUG_FLAG)	printf("Def := Specifier DecList SEMI\n");
		Type type = Specifier(node->firstChild);
		DecList(node->firstChild->bro, type);
	}
	else{
                printf("Error!No This analyse!\n");
        }
}
void DecList(struct Node*node, Type ntype){
	if(DEBUG_FLAG){
                printf("Go in DecList analyse\n");
        }
        //判断节点是否为空
        if(node == NULL)
                return;
	if(Use_This_Rule(node, 1, "Dec")){
		if(DEBUG_FLAG)	printf("DecList := Dec\n");
		Dec(node->firstChild, ntype);
	}
	else if(Use_This_Rule(node, 3, "Dec", "COMMA", "DecList")){
		if(DEBUG_FLAG)	printf("DecList := Dec COMMA DecList\n");
		Dec(node->firstChild, ntype);
		DecList(node->firstChild->bro->bro);
	}
	else{
                printf("Error!No This analyse!\n");
        }
}
void Dec(struct Node*node, Type ntype){
	if(DEBUG_FLAG){
                printf("Go in Dec analyse\n");
        }
        //判断节点是否为空
        if(node == NULL)
                return;
        if(Use_This_Rule(node, 1, "VarDec")){
                if(DEBUG_FLAG)  printf("Dec := VarDec\n");
                VarDec(node->firstChild, ntype);
        }
        else if(Use_This_Rule(node, 3, "VarDec", "ASSIGNOP", "Exp")){
                if(DEBUG_FLAG)  printf("Dec := VarDec ASSIGNOP Exp\n");
                FieldList newField = VarDec(node->firstChild, ntype);
                Type newType = Exp(node->firstChild->bro->bro);
        }
        else{
                printf("Error!No This analyse!\n");
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
		structType->name = node->firstChild->bro->Valstr;
		structType->kind = STRUCTURE;
		structType->inform.structure = ;
		structType->possition = BOTH;
		DefList(node->firstChild->bro->bro->bro);
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
FieldList VarList(struct Node* node, Type ntype);
