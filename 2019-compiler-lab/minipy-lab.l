%{
#include <stdlib.h>
#include <stdio.h>

#include "y.tab.h"

/*  any C declaration  */
%}

letter    [a-zA-Z]

digit     [0-9]

number   {digit}+

id       {letter}({letter}|{digit})*

real     {number}"."{number}?|{number}?"."{number}

%%
[ \t]+      {/*do nothing , just skip */}
{number}    { yylval.Tval.val = atoi(yytext);
	      printf("int %s\n",yytext);
              return INT;
            }
{real}      { yylval.Tval.val = atof(yytext);
	      printf("real %s\n",yytext);
              return REAL;
            }
{id}        { sscanf(yytext,"%s",yylval.name);
              return ID; 
            }
\"(\\.|[^\\"])*\"	{
             return(STRING_LITERAL); 
                  }
.|\n        { return yylval.name[0] = yytext[0];}
%%
