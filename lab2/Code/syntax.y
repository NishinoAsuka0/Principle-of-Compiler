%locations
%{
    #include <stdio.h>
    #include <string.h>
    #include <stdarg.h>
    #include "lex.yy.c"

    void yyerror(const char* s);

    int errorflag = 0;
    int lastErrorLineno = 0;

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

    struct Node* Root = NULL;
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
%}

/* declared types */
%union {
 int type_int;
 float type_float;
 double type_double;
 char* type_string;
 struct Node* type_pnode;
}

/* declared tokens */
%token <type_int> INT
%token <type_float>FLOAT
%token <type_string>ID TYPE
%token SEMI COMMA
%token RELOP ASSIGNOP
%token PLUS MINUS
%token STAR DIV
%token AND OR
%token DOT
%token NOT
%token LP RP LB RB LC RC
%token STRUCT
%token RETURN
%token IF ELSE
%token WHILE

/* declared non-terminals */
%type <type_pnode> Program ExtDefList ExtDef ExtDecList Specifier
%type <type_pnode> StructSpecifier OptTag Tag
%type <type_pnode> VarDec FunDec VarList ParamDec CompSt
%type <type_pnode> StmtList Stmt DefList Def DecList Dec Exp Args

/* precedence and associativity */
%nonassoc error
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%right ASSIGNOP
%left OR
%left AND
%left RELOP
%left PLUS MINUS
%left STAR DIV
%right NOT
%left LP RP LB RB DOT

%%
/* High-level Definitions */
Program : ExtDefList {
            $$ = constructNode("Program", NTML, @$.first_line);
            construct($$, 1, $1);
            Root = $$;
        }
    | ExtDefList error {
            $$ = NULL;
        }
    ;
ExtDefList : ExtDef ExtDefList {
            $$ = constructNode("ExtDefList", NTML, @$.first_line);
            construct($$, 2, $1, $2);
        }
    | /* empty */ {
            $$ = NULL;
        }
    ;
ExtDef : Specifier ExtDecList SEMI {
            struct Node* nodeSEMI = constructNode("SEMI", NVL, @3.first_line);
            $$ = constructNode("ExtDef", NTML, @$.first_line);
            construct($$, 3, $1, $2, nodeSEMI);
        }
    | Specifier SEMI {
            struct Node* nodeSEMI = constructNode("SEMI", NVL, @2.first_line);
            $$ = constructNode("ExtDef", NTML, @$.first_line);
            construct($$, 2, $1, nodeSEMI);
        }
    | Specifier FunDec CompSt {
            $$ = constructNode("ExtDef", NTML, @$.first_line);
            construct($$, 3, $1, $2, $3);
        }
    | Specifier error {
            $$ = NULL;
        }
    ;
ExtDecList : VarDec {
            $$ = constructNode("ExtDecList", NTML, @$.first_line);
            construct($$, 1, $1);
        }
    | VarDec COMMA ExtDecList {
            struct Node* nodeCOMMA = constructNode("COMMA", NVL, @2.first_line);
            $$ = constructNode("ExtDecList", NTML, @$.first_line);
            construct($$, 3, $1, nodeCOMMA, $3);
        }
    | VarDec error {
    	    $$ = NULL;
    }
    ;

/* Specifiers */
Specifier : TYPE {
            struct Node* nodeTYPE = constructNode("TYPE", VL, @1.first_line);
            nodeTYPE->Valstr = $1;
            $$ = constructNode("Specifier", NTML, @$.first_line);
            construct($$, 1, nodeTYPE);
        }
    | StructSpecifier {
            $$ = constructNode("Specifier", NTML, @$.first_line);
            construct($$, 1, $1);
        }
    ;
StructSpecifier : STRUCT OptTag LC DefList RC {
            struct Node* nodeSTRUCT = constructNode("STRUCT", NVL, @1.first_line);
            struct Node* nodeLC = constructNode("LC", NVL, @3.first_line);
            struct Node* nodeRC = constructNode("RC", NVL, @5.first_line);
            $$ = constructNode("StructSpecifier", NTML, @$.first_line);           
            construct($$, 5, nodeSTRUCT, $2, nodeLC, $4, nodeRC);          
        }
    | STRUCT Tag {
            struct Node* nodeSTRUCT = constructNode("STRUCT", NVL, @1.first_line);           
            $$ = constructNode("StructSpecifier", NTML, @$.first_line);
            construct($$, 2, nodeSTRUCT, $2);
        }
    | STRUCT OptTag LC DefList error {
            $$ = NULL;
        }
    | STRUCT OptTag LC error RC{
            $$ = NULL;
	}

    | STRUCT error LC DefList RC{ $$ = NULL;}
    ;
OptTag : ID {
            struct Node* nodeID = constructNode("ID", VL, @1.first_line);
            nodeID->Valstr = $1;
            $$ = constructNode("OptTag", NTML, @$.first_line);
            construct($$, 1, nodeID);
        }
    | /* empty */ {
            $$ = NULL;
        }
    ;
Tag : ID {
            struct Node* nodeID =  constructNode("ID", VL, @1.first_line);
            nodeID->Valstr = $1;
            $$ = constructNode("Tag", NTML, @$.first_line);
            construct($$, 1, nodeID);
        }
    ;

/* Declarators */
VarDec : ID {
            struct Node* nodeID = constructNode("ID", VL, @1.first_line);
            nodeID->Valstr = $1;
            $$ = constructNode("VarDec", NTML, @$.first_line);
            $$->firstChild = nodeID;
        }
    | VarDec LB INT RB {
            struct Node* nodeLB = constructNode("LB", NVL, @2.first_line);
            struct Node* nodeINT = constructNode("INT", VL, @3.first_line);
            nodeINT->Valint = $3;
            struct Node* nodeRB = constructNode("RB", NVL, @4.first_line);
            $$ = constructNode("VarDec", NTML, @$.first_line);
            construct($$, 4, $1, nodeLB, nodeINT, nodeRB);
        }
    | VarDec LB error RB {
            $$ = NULL;
        }
    ;
FunDec : ID LP VarList RP {
            struct Node* nodeID = constructNode("ID", VL, @1.first_line);
            nodeID->Valstr = $1;
            struct Node* nodeLP = constructNode("LP", NVL, @2.first_line);
            struct Node* nodeRP = constructNode("RP", NVL, @4.first_line);
            $$ = constructNode("FunDec", NTML, @$.first_line);
            construct($$, 4, nodeID, nodeLP, $3, nodeRP);
        }
    | ID LP RP {
            struct Node* nodeID = constructNode("ID", VL, @1.first_line);
            nodeID->Valstr = $1;
            struct Node* nodeLP = constructNode("LP", NVL, @2.first_line);
            struct Node* nodeRP =constructNode("RP", NVL, @3.first_line);
            $$ = constructNode("FunDec", NTML, @$.first_line);
            construct($$, 3, nodeID, nodeLP, nodeRP);
        }
    | ID LP error {
            $$ = NULL;
        }
    | ID LP error RP {
            $$ = NULL;
        }
    ;
VarList : ParamDec COMMA VarList {
            struct Node* nodeCOMMA = constructNode("COMMA", NVL, @2.first_line);
            $$ = constructNode("VarList", NTML, @$.first_line);
            construct($$, 3, $1, nodeCOMMA, $3);
        }
    | ParamDec {
            $$ = constructNode("VarList", NTML, @$.first_line);
            $$->firstChild = $1;
        }
    | ParamDec COMMA error { $$ = NULL;}
    ;
ParamDec : Specifier VarDec {
            $$ = constructNode("ParamDec", NTML, @$.first_line);
            construct($$, 2, $1, $2);
        }
    | Specifier error { $$ = NULL;}
    ;

/* Statements */
CompSt : LC DefList StmtList RC {
            struct Node* nodeLC = constructNode("LC", NVL, @1.first_line);
            struct Node* nodeRC = constructNode("RC", NVL, @4.first_line);
            $$ = constructNode("CompSt", NTML, @$.first_line);
            construct($$, 4, nodeLC, $2, $3, nodeRC);
        }
    | error RC {
            $$ = NULL;
        }
    ;
StmtList : Stmt StmtList {
            $$ = constructNode("StmtList", NTML, @$.first_line);
            construct($$, 2, $1, $2);
        }
    | /* empty */ {
            $$ = NULL;
        }
    ;
Stmt : Exp SEMI {
            struct Node* nodeSEMI = constructNode("SEMI", NVL, @2.first_line);
            $$ = constructNode("Stmt", NTML, @$.first_line);
            construct($$, 2, $1, nodeSEMI);
        }
    | CompSt {
            $$ = constructNode("Stmt", NTML, @$.first_line);
            $$->firstChild = $1;
        }
    | RETURN Exp SEMI {
            struct Node* nodeRETURN = constructNode("RETURN", NVL, @1.first_line);
            struct Node* nodeSEMI = constructNode("SEMI", NVL, @3.first_line);
            $$ = constructNode("Stmt", NTML, @$.first_line);
            construct($$, 3, nodeRETURN, $2, nodeSEMI);
        }
    | IF LP Exp RP Stmt %prec LOWER_THAN_ELSE {
            struct Node* nodeIF = constructNode("IF", NVL, @1.first_line);
            struct Node* nodeLP = constructNode("LP", NVL, @2.first_line);
            struct Node* nodeRP = constructNode("RP", NVL, @4.first_line);
            $$ = constructNode("Stmt", NTML, @$.first_line);
            construct($$, 5, nodeIF, nodeLP, $3, nodeRP, $5);
        }
    | IF LP Exp RP Stmt ELSE Stmt {
            struct Node* nodeIF = constructNode("IF", NVL, @1.first_line);
            struct Node* nodeLP = constructNode("LP", NVL, @2.first_line);
            struct Node* nodeRP = constructNode("RP", NVL, @4.first_line);
            struct Node* nodeELSE = constructNode("ELSE", NVL, @6.first_line);
            $$ = constructNode("Stmt", NTML, @$.first_line);
            construct($$, 7, nodeIF, nodeLP, $3, nodeRP, $5, nodeELSE, $7);
        }
    | WHILE LP Exp RP Stmt {
            struct Node* nodeWHILE = constructNode("WHILE", NVL, @1.first_line);
            struct Node* nodeLP = constructNode("LP", NVL, @2.first_line);
            struct Node* nodeRP = constructNode("RP", NVL, @4.first_line);
            $$ = constructNode("Stmt", NTML, @$.first_line);
            construct($$, 5, nodeWHILE, nodeLP, $3, nodeRP, $5);
        }
    | RETURN error SEMI {
            $$ = NULL;
        }
    | error SEMI {
            $$ = NULL;
        }
    | IF LP error RP Stmt %prec LOWER_THAN_ELSE {
            $$ = NULL;
        }
    | IF error Exp RP Stmt %prec LOWER_THAN_ELSE {
            $$ = NULL;
        }
    | IF LP Exp error Stmt %prec LOWER_THAN_ELSE {
            $$ = NULL;
        }
    | IF error Exp RP Stmt ELSE Stmt {
            $$ = NULL;
        }
    | IF LP error RP Stmt ELSE Stmt {
            $$ = NULL;
        }
    | IF LP Exp error Stmt ELSE Stmt {
            $$ = NULL;
        }
    | IF LP Exp RP error ELSE Stmt{
	    $$ = NULL;    
    	}
    | WHILE error Exp RP Stmt {
            $$ = NULL;
        }
    | WHILE LP error RP Stmt {
            $$ = NULL;
        }
    | WHILE LP Exp error Stmt {
            $$ = NULL;
        }
    ;

/* Local Definitions */
DefList : Def DefList {
            $$ = constructNode("DefList", NTML, @$.first_line);
            construct($$, 2, $1, $2);
        }
    | /* empty */ {
            $$ = NULL;
        }
    ;
Def : Specifier DecList SEMI {
            struct Node* nodeSEMI = constructNode("SEMI", NVL, @3.first_line);
            $$ = constructNode("Def", NTML, @$.first_line);
            construct($$, 3, $1, $2, nodeSEMI);
        }
    | Specifier error SEMI {
            $$ = NULL;
        }
    | Specifier DecList error { $$ = NULL;}
    ;
DecList : Dec {
            $$ = constructNode("DecList", NTML, @$.first_line);
            $$->firstChild = $1;
        }
    | Dec COMMA DecList {
            struct Node* nodeCOMMA = constructNode("COMMA", NVL, @2.first_line);
            $$ = constructNode("DecList", NTML, @$.first_line);
            construct($$, 3, $1, nodeCOMMA, $3);
        }
    | Dec error DecList { $$ = NULL;}
    | Dec error { $$ = NULL;}
    ;
Dec : VarDec {
            $$ = constructNode("Dec", NTML, @$.first_line);
            $$->firstChild = $1;
        }
    | VarDec ASSIGNOP Exp {
            struct Node* nodeASSIGNOP = constructNode("ASSIGNOP", NVL, @2.first_line);
            $$ = constructNode("Dec", NTML, @$.first_line);
            construct($$, 3, $1, nodeASSIGNOP, $3);
        }
    | VarDec ASSIGNOP error {
            $$ = NULL;
        }
    ;

/* Expressions */
Exp : Exp ASSIGNOP Exp {
            struct Node* nodeASSIGNOP = constructNode("ASSIGNOP", NVL, @2.first_line);
            $$ = constructNode("Exp", NTML, @$.first_line);
            construct($$, 3, $1, nodeASSIGNOP, $3);
        }
    | Exp AND Exp {
            struct Node* nodeAND = constructNode("AND", NVL, @2.first_line);
            $$ = constructNode("Exp", NTML, @$.first_line);
            construct($$, 3, $1, nodeAND, $3);
        }
    | Exp OR Exp {
            struct Node* nodeOR = constructNode("OR", NVL, @2.first_line);
            $$ = constructNode("Exp", NTML, @$.first_line);
            construct($$, 3, $1, nodeOR, $3);
        }
    | Exp RELOP Exp {
            struct Node* nodeRELOP = constructNode("RELOP", NVL, @2.first_line);
            $$ = constructNode("Exp", NTML, @$.first_line);
            construct($$, 3, $1, nodeRELOP, $3);
        }
    | Exp PLUS Exp {
            struct Node* nodePLUS = constructNode("PLUS", NVL, @2.first_line);
            $$ = constructNode("Exp", NTML, @$.first_line);
            construct($$, 3, $1, nodePLUS, $3);
        }
    | Exp MINUS Exp {
            struct Node* nodeMINUS = constructNode("MINUS", NVL, @2.first_line);
            $$ = constructNode("Exp", NTML, @$.first_line);
            construct($$, 3, $1, nodeMINUS, $3);
        }
    | Exp STAR Exp {
            struct Node* nodeSTAR = constructNode("STAR", NVL, @2.first_line);
            $$ = constructNode("Exp", NTML, @$.first_line);
            construct($$, 3, $1, nodeSTAR, $3);
        }
    | Exp DIV Exp {
            struct Node* nodeDIV = constructNode("DIV", NVL, @2.first_line);
            $$ = constructNode("Exp", NTML, @$.first_line);
            construct($$, 3, $1, nodeDIV, $3);
        }
    | LP Exp RP {
            struct Node* nodeLP = constructNode("LP", NVL, @1.first_line);
            struct Node* nodeRP = constructNode("RP", NVL, @3.first_line);
            $$ = constructNode("Exp", NTML, @$.first_line);
            construct($$, 3, nodeLP, $2, nodeRP);
        }
    | MINUS Exp {
            struct Node* nodeMINUS = constructNode("MINUS", NVL, @1.first_line);
            $$ = constructNode("Exp", NTML, @$.first_line);
            construct($$, 2, nodeMINUS, $2);
        }
    | NOT Exp {
            struct Node* nodeNOT = constructNode("NOT", NVL, @1.first_line);
            $$ = constructNode("Exp", NTML, @$.first_line);
            construct($$, 2, nodeNOT, $2);
        }
    | ID LP Args RP {
            struct Node* nodeID = constructNode("ID", VL, @1.first_line);
            nodeID->Valstr = $1;
            struct Node* nodeLP = constructNode("LP", NVL, @2.first_line);
            struct Node* nodeRP = constructNode("RP", NVL, @4.first_line);
            $$ = constructNode("Exp", NTML, @$.first_line);
            construct($$, 4, nodeID, nodeLP, $3, nodeRP);
        }
    | ID LP RP {
            struct Node* nodeID = constructNode("ID", VL, @1.first_line);
            nodeID->Valstr = $1;
            struct Node* nodeLP = constructNode("LP", NVL, @2.first_line);
            struct Node* nodeRP = constructNode("RP", NVL, @3.first_line);
            $$ = constructNode("Exp", NTML, @$.first_line);
            construct($$, 3, nodeID, nodeLP, nodeRP);
        }
    | Exp LB Exp RB {
            struct Node* nodeLB = constructNode("LB", NVL, @2.first_line);
            struct Node* nodeRB = constructNode("RB", NVL, @4.first_line);
            $$ = constructNode("Exp", NTML, @$.first_line);
            construct($$, 4, $1, nodeLB, $3, nodeRB);
        }
    | Exp DOT ID {
            struct Node* nodeDOT = constructNode("DOT", NVL, @2.first_line);
            struct Node* nodeID = constructNode("ID", VL, @3.first_line);
            nodeID->Valstr = $3;
            $$ = constructNode("Exp", NTML, @$.first_line);
            construct($$, 3, $1, nodeDOT, nodeID);
        }
    | ID {
            struct Node* nodeID = constructNode("ID", VL, @1.first_line);
            nodeID->Valstr = $1;
            $$ = constructNode("Exp", NTML, @$.first_line);
            $$->firstChild = nodeID;
        }
    | INT {
            struct Node* nodeINT = constructNode("INT", VL, @1.first_line);
            nodeINT->Valint = $1;
            $$ = constructNode("Exp", NTML, @$.first_line);
            $$->firstChild = nodeINT;
        }
    | FLOAT {
            struct Node* nodeFLOAT = constructNode("FLOAT", VL, @1.first_line);
            nodeFLOAT->Valfloat = $1;
            $$ = constructNode("Exp", NTML, @$.first_line);
            $$->firstChild = nodeFLOAT;
        }
    | Exp LB error RB {
            $$ = NULL;
        }
    | error RP {
            $$ = NULL;
        }
    | ID LP Args error {
            $$ = NULL;
        }
    | ID LP error {
            $$ = NULL;
        }
    | Exp ASSIGNOP error {
            $$ = NULL;
        }
    | Exp AND error {
            $$ = NULL;
        }
    | Exp OR error {
            $$ = NULL;
        }
    | Exp RELOP error {
            $$ = NULL;
        }
    | Exp PLUS error {
            $$ = NULL;
        }
    | Exp MINUS error {
            $$ = NULL;
        }
    | Exp STAR error {
            $$ = NULL;
        }
    | Exp DIV error {
            $$ = NULL;
        }
    | MINUS error {
            $$ = NULL;
        }
    | NOT error {
            $$ = NULL;
        }
    | LP Exp error {
            $$ = NULL;
        }
    ;
Args : Exp COMMA Args {
            struct Node* nodeCOMMA = constructNode("COMMA", NVL, @2.first_line);
            $$ = constructNode("Args", NTML, @$.first_line);
            construct($$, 3, $1, nodeCOMMA, $3);
        }
    | Exp {
            $$ = constructNode("Args", NTML, @$.first_line);
            $$->firstChild = $1;
        }
    ;

%%
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


void yyerror(const char* s) {
	if(isNewError(yylineno)){
		fprintf(stdout, "Error type B at Line %d: %s.\n", yylineno, yytext);
		errorflag = 1;
	}
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
