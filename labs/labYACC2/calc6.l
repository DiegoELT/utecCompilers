%option noyywrap

%{
#define YYSTYPE double

#include <stdio.h>
#include "y.tab.h"
%}

numero [0-9]+([.][0-9]+)?

%%

[ ]               {/* Ignores all whitespaces basically */}
{numero}		  {yylval = atof(yytext); return number;}
\n                {return 0;}
.                 {yylval = yytext[0]; return yytext[0]; /* yytext[0] holds the first character of the text matched by the current token. */}

%%