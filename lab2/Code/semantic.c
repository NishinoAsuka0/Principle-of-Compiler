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
void ExtDecList(struct Node*node, Type ntype);
void CompSt(struct Node *node, Type ntype);
void Stmt(struct Node *node, Type ntype);
Type StructSpecifier(struct Node* node);
