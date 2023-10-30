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
	if(find(name)){
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
	HashNode curNode = gTable[HashNum];
	while(curNode != NULL){
		if(strcmp(curNode->name, name) == 0){
			return 1;
		}
		curNode = curNode->next;
	}
	return 0;
}

