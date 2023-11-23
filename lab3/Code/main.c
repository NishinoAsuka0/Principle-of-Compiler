#include <stdio.h>

extern FILE* yyin;
extern int yydebug;
extern int yyparse (void);
extern void yyrestart (FILE *input_file  );
extern int errorflag;
extern struct Node* Root;
extern void Print_Tree(struct Node* rootNode,int SpaceNum);
extern void destroyTree(struct Node* rootNode);
extern void semantic_check_start(struct Node* rootNode);
extern struct CodeList_* IRCode_start(struct Node* root);
extern void printIRCode(struct CodeList_* curNode, FILE*file);
int main(int argc, char** argv) {
    if (argc <= 1) 
        return 1;
    FILE* f = fopen(argv[1], "r");
    if (!f) {
        perror(argv[1]);
        return 1;
    }
    //printf("lab start");
    yyrestart(f);
    // yydebug = 1;
    //printf("lab1 start");
    yyparse();
    //printf("lab2 start");
    if (errorflag == 0) {
        semantic_check_start(Root);
    }
    //printf("lab3 start");
    struct CodeList_* IRList = IRCode_start(Root);
    FILE*ff;
    if(argv[2] == NULL){ff = fopen("output.ir", "w");}
    else
        ff =fopen(argv[2], "w"); // 构造输出中间代码文件
    printIRCode(IRList, ff); // 写入生成的中间代码
    fclose(ff); // 关闭文件
    destroyTree(Root);
    return 0;
}

