%{
    #include <stdio.h>
    int lineCounter = 1; // Since EOF is not being counted as a line. 
    int charCounter = 0;
    int wordCounter = 1;
%}
line "\n"
char [^ ]
word [ \t]*
%%
{line}           {lineCounter++; wordCounter++;}
{char}           {charCounter++;}
{word}           {wordCounter++;}
%%
int yywrap(void)
{}
int main(int argc, char* argv[])
{ 
    char* fileName = argv[1];
    extern FILE* yyin;
    yyin = fopen(fileName,"r");
    yylex();
    printf("The number of lines is: %d\nThe number of chars is: %d\nThe number of words is: %d\n",lineCounter,charCounter,wordCounter);
}