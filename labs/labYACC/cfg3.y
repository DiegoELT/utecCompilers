%{
    #include <stdio.h>
    #include <ctype.h>

    #define YYSTYPE char *
%}

%%

S   : A
    | B
    ;

A   : 'a'
    ;

B   : 'a'
    ;

%%

int main()
{
    return yyparse();
}

int yylex(void)
{
    char c; // c is gonna be the char we obtain each time.
    while((c = getchar()) == ' ');
    ungetc(c, stdin);
    scanf("%c", &yylval);
    if (c == '\n')
        return 0;
    return(c);
}

int yyerror(char * s)
{
    fprintf(stderr,"%s\n",s);
    return 0;
} // Allows for printing of an error messages