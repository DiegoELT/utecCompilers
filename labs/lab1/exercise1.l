%{
    #include <stdio.h>
    int lineCounter = 1;
%}
line .*\n
%%
{line}     {printf("%d %s",lineCounter++,yytext);}
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