#include <stdio.h>
#include <string.h>
#include "hash.h"


bool equal_string(char*a1, char*a2);
//类型一致性
bool equal_Type(Type T1, Type T2);
//函数参数一致性
bool equal_Param(FieldList p1,FieldList p2);
// 语义分析入口函数
void semantic_check_start(struct Node* Root);
//全局语法单元遍历
void ExtDefList(struct Node *node);
void ExtDef(struct Node* node);
// 判断是否使用了指定的产生式
bool Use_This_Rule(struct Node* node, int index, ...);
//局部语句块遍历
void CompSt(struct Node *node, Type ntype);
void Stmt(struct Node *node, Type ntype);
Type Specifier(struct Node*node);
void ExtDecList(struct Node*node,Type ntype);
Function FunDec(struct Node*node, Type ntype);
Type StructSpecifier(struct Node* node);
Type analyseType(struct Node*node);
void StmtList(struct Node*node, Type ntype);
FieldList VarList(struct Node* node, Type ntype);
void DefList(struct Node*node, int num);
void Def(struct Node*node);
void DecList(struct Node*node, Type ntype);
void Dec(struct Node*node, Type ntype);

