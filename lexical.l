%{
	#include "syntax_arr.tab.h"
	#include<stdio.h>
	#include<string.h>
	int yycolumn = 1;
	#define YY_USER_ACTION \
		yylloc.first_line = yylloc.last_line = yylineno; \
			yylloc.first_column = yycolunm; \
			yylloc.last_column = yycolumn + yyleng - 1; \
			yycolumn += yyleng;
	extern void printError(char errorType, int lineno, char*msg);
	extern int Err_new(int errorLineno);
	extern int errorflag;
	extern int oct_to_dec(char * text);
	extern int hex_to_dec(char * text);
%}
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
INT	0|([1-9]{digit}*)|([0][1-7]+)|([0][xX][A-Fa-f0-9]+)
FLOAT	({INT}[.]{digit}+)
ID	([_a-zA-Z])([_a-zA-Z0-9]*)
delimiter	[ \t\r]
EOF	<<EOF>>
SEMI	";"
%option yylineno

%%
{RELOP} {return RELOP;}
";"     {return SEMI;}
","     {return COMMA;}
"="     {return ASSIGN;}
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
{TYPE}	{
		yylval.type_string = strdup(yytext);
		return TYPE;
	}
{ID}    {
                yylval.type_string = strdup(yytext);
                return ID;
        }
{INT}	{
		if('0'==yytext[0]){
			if(yyleng > 2 && (yytext[1]=='x'||yytext[1]=='X')){
				printf("%d",hex_to_dec(yytext));
			}
			else{
				printf("%d",oct_to_dec(yytext));
			}
		}
		else{
			printf("%d",atoi(yytext));
		}
		return INT;
	}	
{FLOAT}	{
		yylval.type_float = atof(yytext);
		return FLOAT;
	}
"//"	{
		char c = input();
		while (c != '\n') c = input();
	}
"/*"	{
		char c = input();
		while(true){
			if(c == '*'){
				c = input();
				if(c == '/') break;
			}
			else{
				c = input();
			}
		}
	}
\n	{
		yycolumn = 1;
	}
{delimiter}	{ }
.	{
		if(Err_new(yylineno)){
			char msg[32];
			sprintf(msg,"Mysterious character \"%s\"",yytext);
			printError('A', yylineno, msg);
		}
	}
%%
int oct_to_dec(char*text){
	int len = strlen(text);
	int decimal = 0;
	int ch;
	for(int i = 1; i < len;i++){
		ch = (int)text[i] - 48;
		decimal = decimal * 8 + ch;
	}
	return decimal;
}
int hex_to_dec(char*text){
	int len = strlen(text);
        int decimal = 0;
        int ch;
        for(int i = 2; i < len;i++){
		if(text[i]>='0'&&text[i]<='9'){
                	ch = (int)text[i] - 48;
		}
		else if(text[i]>='a'&&text[i]<='f'){
			ch = text[i] - 'a' + 10;
		}
		else if(text[i]>='A'&&text[i]<='F'){
			ch = text[i] - 'A' + 10;
		}
                decimal = decimal * 16 + ch;
        }
        return decimal;
}
