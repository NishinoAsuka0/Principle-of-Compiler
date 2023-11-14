%{
    #include "syntax.tab.h"

    int yycolumn = 1;
    #define YY_USER_ACTION \
        yylloc.first_line = yylloc.last_line = yylineno; \
	    yylloc.first_column = yycolumn; \
	    yylloc.last_column = yycolumn + yyleng - 1; \
	    yycolumn += yyleng;
    
    extern void printError(char *errorType, int lineno, char* msg);
    extern int isNewError(int errorLineno);
%}
/* 对于ID，先不设置其必须为下划线或者字母开头，识别出来后再去判断 */
letter	[a-zA-Z]
digit	[0-9]
COMMA 	","
ASSIGNOP	"="
RELOP	">"|"<"|">="|"<="|"=="|"!="
PLUS	"+"
MINUS	"-"
STAR	"*"
DIV	"/"
AND	"&&"
OR	"||"
DOT	"."
NOT	"!"
TYPE	int|float
LP	(
RP	)
LB	[
RB	]
LC	{
RC	}
STRUCT	struct
RETURN	return
IF	if
ELSE	else
WHILE	while
INT	0|([1-9]{digit}*)
OINT	([0][1-7]+)
HINT	([0][xX][A-Fa-f0-9]+)
FLOAT	({INT}[.]{digit}+)
efloat  ({digit}*\.{digit}+|{digit}+\.)[eE][+-]?{digit}+
ID	({letter}|{digit}|_)+
ErrorID	({digit})([_a-zA-Z0-9]*)
delimiter	[ \t\r]
EOF	<<EOF>>
SEMI	";"
%option yylineno

%%
{RELOP} {return RELOP;}
";"     {return SEMI;}
","     {return COMMA;}
"="     {return ASSIGNOP;}
"+"     {return PLUS;}
"("     {return LP;}
")"     {return RP;}
"{"     {return LC;}
"}"     {return RC;}
"-"     {return MINUS;}
"*"     {return STAR;}
"/"     {return DIV;}
"&&"     {return AND;}
"||"     {return OR;}
"."     {return DOT;}
"!"     {return NOT;}
"["     {return LB;}
"]"     {return RB;}
"struct"        {return STRUCT;}
"return"        {return RETURN;}
"if"    {return IF;}
"else"  {return ELSE;}
"while" {return WHILE;}
{TYPE}  {


                yylval.type_string = strdup(yytext);
                return TYPE;
        }

{INT}	{
		yylval.type_int = atoi(yytext);
		//debug
		//printf("add in INT, %d\n",atoi(yytext));
		//debug
		return INT;
	}	
{FLOAT}	{
		yylval.type_float = atof(yytext);
		return FLOAT;
	}

{efloat}	{
			if(isNewError(yylineno)){
				printf("Error type A at Line %d: syntax error at \"%s\".\n", yylineno, yytext);
			}
		}

{ID}    {
                //debug
                //printf("add in ID, %s\n",yytext);
		if(yytext[0] >= '0' && yytext[0] <= '9'){
			if (isNewError(yylineno)) {
                       	printf("Error type B at Line %d: syntax error at \"%s\".\n", yylineno, yytext);
                        }

		}
                yylval.type_string = strdup(yytext);
                return ID;
        }

"//"	{
		char c = input();
		while (c != '\n') c = input();
	}

"/*"    {
            char c = input();
            while (1) {
                if (c == '*') {
                    c = input();
                    if (c == '/')
                        break;
                    else
                    	unput(c);
                } else if (c == EOF) {
                    if (isNewError(yylineno)) {
                        printError("B", yylineno, "Unmatched \"/*\"");
                    }
                    break;
                }
                c = input();
            }
        }
"*/"    {
            if (isNewError(yylineno)) {
                printError("B", yylineno, "Unmatched \"*/\"");
            }
        }

\n	{
		yycolumn = 1;
	}
{delimiter}	{ }
.	{	
		//debug
	//	printf("lexical error : %s\n",yytext);
		if(isNewError(yylineno)){
			printf("Error type A at Line %d: syntax error at \"%s\".\n", yylineno, yytext);
		}
	}
%%
