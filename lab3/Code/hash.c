#include <stdio.h>
#include <string.h>
#include "hash.h"
#include <stdlib.h>

//初始化Hash表
void initHashTable(){
	for(int i = 0; i < 1024; i++){
		gTable[i] = NULL;
		sTable[i] = NULL;
	}
	Type readType = (Type)malloc(sizeof(struct Type_));
	Type writeType = (Type)malloc(sizeof(struct Type_));
	readType->kind = FUNCTION;
	writeType->kind = FUNCTION;
	Function funcread = (Function)malloc(sizeof(struct Function_));
	Function funcwrite = (Function)malloc(sizeof(struct Function_));
	char* readname = malloc(strlen("read"+1));
	char* writename = malloc(strlen("read"+1));
	strcpy(readname, "read");
	strcpy(writename, "write");
	funcread->name = readname;
	funcread->state = 1;
	Type retValType = (Type)malloc(sizeof(struct Type_));
	retValType->kind = BASIC;
	retValType->inform.basic = 1;
	retValType->possition = RIGHT;
	funcwrite->name = writename;
	funcwrite->state = 1;
	readType->inform.function = funcread;
	writeType->inform.function = funcwrite;
	insert(readname, readType);
	insert(writename, writeType);
}


unsigned int time33_hash(char*name){
	unsigned int hash = 5381;
	while(*name){
		hash = hash*33 + (*name++);
	}
	return (hash&0x7FFFFFFF)%1024;
}

HashNode CreateNewNode(char *name, Type type){
	HashNode newNode = (HashNode)malloc(sizeof(struct HashNode_));
	newNode->name = name;
	newNode->type = type;
	newNode->param = NULL;
	newNode->next = NULL;
	return newNode;
}

//符号表的插入操作
int insert(char *name,Type type){
	if(find(name) && DEBUG_FLAG){
		printf("Error!The symbol has already exist.\n");
		return 0;
	}
	int HashNum = time33_hash(name);
	HashNode newNode = CreateNewNode(name, type);
	HashNode curNode = gTable[HashNum];
	if(curNode == NULL){
		gTable[HashNum] = newNode;
		if(DEBUG_FLAG){
			printf("insert successfully at first and the symbol name is %s.\n", newNode->name);
		}
		return 1;
	}
	else{
		while(curNode->next != NULL){
			curNode = curNode->next;
		}
		curNode->next = newNode;
		if(DEBUG_FLAG){
                        printf("insert successfully at end and the symbol name is %s.\n", newNode->name);
                }
		return 1;
	}
}

//符号表的查找操作
int find(char *name){
	int HashNum = time33_hash(name);
	//printf("HashNum is %d", HashNum);
	HashNode curNode = gTable[HashNum];
	while(curNode != NULL){
		if(strcmp(curNode->name, name) == 0){
			return 1;
		}
		curNode = curNode->next;
	}
	return 0;
}

