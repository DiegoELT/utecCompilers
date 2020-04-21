%{
    #include "basicScanner.h"
%}
%%
[ \t\n]   ; // ignore all whitespace and newline
"int"|"void"|"while"|"if"|"else"    return KEYWORD;
[!\-+*/<>]?= return OPERATOR; 
[+\-><*/] return OPERATOR; // These are the ones that might be by themselves, might be improved upon.
[{}();] return SPECIAL_SYMBOL;
[a-zA-Z][a-zA-Z0-9]*    return IDENTIFIER;
[+\-]?[0-9]*   return INT_CONSTANT;
[+\-]?[0-9]*\.[0-9]*   return FLOAT_CONSTANT;
.   return UNEXPECTED_CHAR;
%%
int yywrap(void)
{
    return 1;
}