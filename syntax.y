%locations
%{
	#include<stdio.h>
	#include<string.h>
	#include<stdarg.h>
	#include<ctype.h>
	#include "lex.yy.c"

	void yyerror(const char* s);
	int errorflag = 0;
	int last_error = 0;
	enum NodeType{
		NTML,
		NVL,
		VL
	};
	struct Node {
		char *nodeName;
		enum NodeType nodeType;
		int lineNum;
		union{
			int Valint;
			float Valfloat;
			char* Valstr;
		};
		struct Node* firstChild;
		struct Node* Sibc;
	};
%}

/* declared types */
%union {
 int type_int;
 float type_float;
 double type_double;
}

/* declared tokens */
%token <type_int> INT
%token <type_float>FLOAT
%token <type_string>ID TYPE
%token SEMI COMMA
%token RELOP ASSIGN
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


%type <type_pnode> Program ExtDefList ExtDef ExtDecList Specifier
%type <type_pnode> VarDec FunDec VarList ParamDec CompSt
%type <type_pnode> StmtList Stmt DefList Def DecList Dec Exp Args

%nonassoc error
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%right ASSIGN
%left OR
%left AND
%left RELOP
%left PLUS MINUS
%left STAR DIV
%right NOT
%left LP RP LB RB DOT

%%

Program :ExtDefList
ExtDefList : ExtDef ExtDefList
| 
ExtDef :Specifier ExtDecList SEMI
| Specifier SEMI
| Specifier FunDec CompSt
ExtDecList :VarDec
| VarDec COMMA ExtDecList
;
Specifier :TYPE
| StructSpecifier
StructSpecifier :STRUCT OptTag LC DefList RC
| STRUCT Tag
OptTag :ID
| 
Tag :ID
;
VarDec : ID
| VarDec LB INT RB
FunDec :ID LP VarList RP
| ID LP RP
VarList :ParamDec COMMA VarList
| ParamDec
ParamDec :Specifier VarDec
;
CompSt :LC DefList StmtList RC
StmtList :Stmt StmtList
| 
Stmt :Exp SEMI
| CompSt
| RETURN Exp SEMI
| IF LP Exp RP Stmt
| IF LP Exp RP Stmt ELSE Stmt
| WHILE LP Exp RP Stmt
;
DefList :Def DefList
| 
Def :Specifier DecList SEMI
DecList :Dec
| Dec COMMA DecList
Dec :VarDec
| VarDec ASSIGNOP Exp
;
Exp :Exp ASSIGNOP Exp
| Exp AND Exp
| Exp OR Exp
| Exp RELOP Exp
| Exp PLUS Exp
| Exp MINUS Exp
| Exp STAR Exp
| Exp DIV Exp
| LP Exp RP
| MINUS Exp
| NOT Exp
| ID LP Args RP
| ID LP RP
| Exp LB Exp RB
| Exp DOT ID
| ID
| INT
| FLOAT
Args :Exp COMMA Args
| Exp
;
%%
struct Node* constructNode(char*Name, enum NodeType Type, int line){
	struct Node* newNode = &node_list[node_idx++];
	newNode->nodeName = Name;
	newNode->nodeType = Type;
	newNode->lineNum = line;
	newNode->firstChild = NULL;
	newNode->Sibc = NULL;
	return newNode;
}
