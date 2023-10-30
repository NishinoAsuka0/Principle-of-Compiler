#include <stdio.h>
#include <string.h>
#include "hash.h"
#include <stdbool.h>
#include "syntaxTree.h"

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
void DefList(struct Node*node, int ifstruct);
void Def(struct Node*node, int ifstruct);
void DecList(struct Node*node, Type ntype, int ifstruct);
void Dec(struct Node*node, Type ntype, int ifstruct);
FieldList ParamDec(struct Node*node);
FieldList VarDec(struct Node*node, Type ntype, int ifstruct);
Type Exp(struct Node*node);
bool findFunc(Function func);
Type Struct_Type_get(Type structType, char* name);
Type Type_get(struct Node*node);
