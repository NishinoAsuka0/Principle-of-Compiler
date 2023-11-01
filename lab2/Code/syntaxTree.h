#ifndef _SYNTAXTREE_
#define _SYNTAXTREE_


#include <stdio.h>
#include <string.h>
#include <stdarg.h>
//extern int errorflag;
//extern int lastErrorLineno;
enum NodeType { NTML, NVL, VL };
struct Node {
	char* nodeName;
        enum NodeType nodeType;
        int lineNum;
        union {
            int Valint;
            float Valfloat;
            char* Valstr;
        };
        struct Node* firstChild;
        struct Node* bro;
};


//extern struct Node* Root;
//构造树节点并建立语法树
    
struct Node* constructNode(char* nodeName, enum NodeType nodeType, int lineNum);
    
void construct(struct Node* fatherNode, int index, ...);
    
    
//语法树的打印
    
void Print_Tree(struct Node* rootNode,int SpaceNum);
    
    
//对树进行删除
    
void destroyTree(struct Node* rootNode);
    
    
//对Error的打印
void printError(char errorType, int lineno, char* msg);
int isNewError(int errorLineno);

#endif
