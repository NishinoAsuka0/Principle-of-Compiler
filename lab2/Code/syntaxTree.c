#include "syntaxTree.h"
#include <stdio.h>
#include <stdlib.h>

struct Node* constructNode(char* nodeName, enum NodeType nodeType, int lineNum) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->nodeName = nodeName;
    newNode->nodeType = nodeType;
    newNode->lineNum = lineNum;
    newNode->firstChild = NULL;
    newNode->bro = NULL;
    return newNode;
}

void construct(struct Node* fatherNode, int index, ...) {
    va_list valist;
    va_start(valist, index);
    struct Node* firstChild = NULL;
    struct Node* lastChild = NULL;
    for (int i = 0; i < index; i++) {
        struct Node* nowNode = va_arg(valist, struct Node*);
        if (firstChild == NULL) {
            if (nowNode != NULL) {
                firstChild = nowNode;
                lastChild = firstChild;
            }
        } else {
            if (nowNode != NULL) {
                lastChild->bro = nowNode;
                lastChild = nowNode;
            }
        }
    }
    va_end(valist);
    fatherNode->firstChild = firstChild;
}

void Print_Tree(struct Node* rootNode, int SpaceNum) {
    if (rootNode == NULL)
        return;
    for (int i = 0; i < SpaceNum; i++) {
        printf(" ");
    }
    switch (rootNode->nodeType) {
        case NTML:
            printf("%s (%d)\n", rootNode->nodeName, rootNode->lineNum);
            break;
        case NVL:
            printf("%s\n", rootNode->nodeName);
            break;
        case VL:
            printf("%s: ", rootNode->nodeName);
            if ((strcmp(rootNode->nodeName, "TYPE") == 0) || (strcmp(rootNode->nodeName, "ID") == 0)) {
                printf("%s\n", rootNode->Valstr);
            } else if (strcmp(rootNode->nodeName, "INT") == 0) {
                printf("%d\n", rootNode->Valint);
            } else if (strcmp(rootNode->nodeName, "FLOAT") == 0) {
                printf("%f\n", rootNode->Valfloat);
            } else {
                printf("ERROR!\n");
            }
            break;
        default:
            printf("ERROR!\n");
    }
    Print_Tree(rootNode->firstChild, SpaceNum + 2);
    Print_Tree(rootNode->bro, SpaceNum);
}


void printError(char errorType, int lineno, char* msg) {
    fprintf(stderr, "Error type %c at Line %d: %s.\n", errorType, lineno, msg);
}

int isNewError(int errorLineno) {
    if (lastErrorLineno != errorLineno) {
        errorflag = 1;
        lastErrorLineno = errorLineno;
        return 1;
    } else {
        return 0;
    }
}

void destroyTree(struct Node* rootNode) {
    if (rootNode == NULL) {
        return;
    }
    while (rootNode->firstChild != NULL) {
        struct Node* nowNode = rootNode->firstChild;
        rootNode->firstChild = nowNode->bro;
        destroyTree(nowNode);
    }
    if ((strcmp(rootNode->nodeName, "TYPE") == 0) || (strcmp(rootNode->nodeName, "ID") == 0)) {
        free(rootNode->Valstr);
        rootNode->Valstr = NULL;
    }
    return;
    free(rootNode);
    rootNode = NULL;
}
