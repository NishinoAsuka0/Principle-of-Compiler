#include <stdio.h>

extern FILE* yyin;
extern int yydebug;
extern int yyparse (void);
extern void yyrestart (FILE *input_file  );
extern int errorflag;
extern struct Node* Root;
extern void Print_Tree(struct Node* rootNode,int SpaceNum);
extern void destroyTree(struct Node* rootNode);

int main(int argc, char** argv) {
    if (argc <= 1) 
        return 1;
    FILE* f = fopen(argv[1], "r");
    if (!f) {
        perror(argv[1]);
        return 1;
    }
    yyrestart(f);
    // yydebug = 1;
    yyparse();
    if (errorflag == 0) {
        Print_Tree(Root,0);
    }
    destroyTree(Root);
    return 0;
}

