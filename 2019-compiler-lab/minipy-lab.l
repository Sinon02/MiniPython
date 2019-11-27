%{
#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define YYSTYPE_IS_DECLARED 
#include "types.h"
#include "y.tab.h"

/*  any C declaration  */
%}

letter    [a-zA-Z]

digit     [0-9]

number   {digit}+

id       {letter}({letter}|{digit})*

real     {number}"."{number}?|{number}?"."{number}

%%
[ \t]+		{/*do nothing , just skip */}
{number}	{
			yylval.type=0; 
			yylval.data.i = atoi(yytext);
			return INT;
		}
{real}		{
			yylval.type=1; 
			yylval.data.f = atof(yytext);
			return REAL;
		}
{id}		{
			int len = strlen(yytext);
			yylval.data.s = (char *)malloc(sizeof(char)*(len+1)); 
			strcpy(yylval.data.s,yytext);
			yylval.type=2;
             		return ID; 
		}
\"(\\.|[^\\"])*\"	{int len = strlen(yytext);
		            yylval.data.s = (char *)malloc(sizeof(char)*len); 
		            strncpy(yylval.data.s,yytext+1,len-2);
					yylval.data.s[len-2]=0;
					yylval.type=2;
             		return(STRING_LITERAL); 
		}
.|\n        { return yytext[0];}
%%
#ifdef LEX
YYSTYPE yylval;
int main()
 {
while(1) yylex();
 }
 int yywrap()
 {
 return 1;
 }
#endif
