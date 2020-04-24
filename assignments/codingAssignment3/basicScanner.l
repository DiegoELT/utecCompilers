%{
    #include "basicScanner.h"
%}
whitespace [ \t\n]
keyword "int"|"void"|"while"|"if"|"else"
operator ([!\-+*/<>]?=)|([+\-><*/])
specialSymbol [{}();]
identifier [a-zA-Z][a-zA-Z0-9]*
int [+\-]?[0-9]*
float [+\-]?[0-9]*\.[0-9]* 
%%
{whitespace}   ; // ignore all whitespace and newline
{keyword}                           return KEYWORD;
{operator}                          return OPERATOR; // These are the ones that might be by themselves, might be improved upon.
{specialSymbol}                     return SPECIAL_SYMBOL;
{identifier}                        return IDENTIFIER;
{int}                               return INT_CONSTANT;
{float}                             return FLOAT_CONSTANT;
.                                   return UNEXPECTED_CHAR;
%%
int yywrap(void)
{
    return 1;
}