%option noyywrap

%{
#include <stdio.h>

//#define YY_DECL int yylex()

#include "y.tab.h"
%}

numero [0-9]+

%%

[ ]               {/* Ignores all whitespaces basically */}
{numero}		  {yylval = atoi(yytext); return number;}
\n                {yylineno++; yylval = yytext[0]; return EOL;}
.                 {yylval = yytext[0]; return yytext[0]; /* yytext[0] holds the first character of the text matched by the current token. */}


%%