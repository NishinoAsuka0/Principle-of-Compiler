#include "IRcode.h"
#include <stdio.h>
#include <stdlib.h>


void printCode(IRCode curNode){

}

CodeList Merge_CodeList(CodeList Code1, CodeList Code2){
	if(Code1 == NULL)
		return Code2;
	if(Code2 == NULL)
		return Code1;
	CodeList curList = Code1;
	while(curList->next != NULL)	curList = curList->next;
	curList->next = Code2;
	Code2->pre = curList;
	return Code1;
}
void Add_Code(CodeList IrCode){
	if(LAB3_DEBUG){
		printCode(IrCode->IRcoding);
	}
	if(CodeHead == NULL){
		CodeHead = CodeTail = IrCode;
	}
	else{
		if(IrCode != NULL){
			CodeTail->next = IrCode;
			IrCode->pre = CodeTail;
			CodeTail = IrCode;
		}
	}
}

CodeList IRCode_start(struct Node*root){
	if(root == NULL)	return NULL;//判断AST是否为空
	if(LBA3_DEBUG)	printf("Program : ExtDefList\n")
	if(Use_This_Rule(root, 1, "Program")){
		CodeHead = CodeTail = NULL;
		VarHead = VarTail = NULL;
		VarNum = 1;
		LabelNum = 1;
		TempNum = 1;
		Add_Code(Translate_ExtDefList(root->firstChild));
		return CodeHead;
	}
	else
		return NULL;
}

CodeList Translate_ExtDefList(struct Node* node){
	if(node == NULL)	return NULL;
	if(Use_This_Rule(node, 2, "ExtDef", "ExtDefList")){
		if(LAB3_DEBUG)	printf("ExtDefList : ExtDef ExtDefList \n")
		CodeList ExtDef = Translate_ExtDef(node->firstChild);
		return Merge_CodeList(ExtDef, Translate_ExtDefList(node->firstChild->bro));	
	}
	else{
		printf("Error!No this rule!\n")
	}
}
CodeList Translate_ExtDef(struct Node* node);{
	if(node == NULL)	return NULL;
	if(Use_This_Rule())
}
CodeList Translate_FunDec(struct Node* node);

