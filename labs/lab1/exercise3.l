%{
    #include <stdio.h>
%}
identifier [a-zA-Z][a-zA-Z0-9]*
int [+\-]?[0-9]*
float [+\-]?[0-9]*\.[0-9]*
file [a-zA-Z0-9\-_]*\.[a-zA-Z]*
quotes \"
leftcurly "{"
rightcurly "}"
semicolon ";"
linechange \n
whitespace [ \t]*
error .
%%
{identifier}        {printf("IDENTIFICADOR\n");}
{int}               {printf("NUMEROENTERO\n");}
{float}             {printf("NUMERODECIMAL\n");}
{file}              {printf("RUTANOMBREARCHIVO\n");}
{quotes}            {printf("COMILLAS\n");}
{leftcurly}         {printf("LLAVEIZQUIERDA\n");}
{rightcurly}        {printf("LLAVEDERECHA\n");}
{semicolon}         {printf("SEMICOLON\n");}
{linechange}        {printf("CAMBIODELINEA\n");}
{whitespace}        {;}
{error}             {printf("NOVALIDO\n");}
%%
int yywrap(void)
{}
int main(int argc, char* argv[])
{ 
    char* fileName = argv[1];
    extern FILE* yyin;
    yyin = fopen(fileName,"r");
    yylex();
}