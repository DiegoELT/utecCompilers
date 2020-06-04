%{
    #include <stdio.h>
    #include <ctype.h>
%}

%token numero

%left'+' '-'
%left'*'

%%

command : exp   {printf("%d\n",$1);}
        ;  // Allows to print the result, as shown in the book.

exp     : numero
        | exp '+' exp   {$$ = $1 + $3;}
        | exp '-' exp   {$$ = $1 - $3;} 
        | exp '*' exp   {$$ = $1 * $3;}
        | '(' exp ')'   {$$ = $2;}
        ;

%%

int main()
{
    return yyparse();
}

int yylex(void)
{
    int c; // c is gonna be the char we obtain each time.
    while((c = getchar()) == ' '); // Eliminates blanks.
    if (isdigit(c))
    {
        ungetc(c, stdin);
        scanf("%d", &yylval);
        return(numero);
    }
    if (c == '\n')
        return 0;
    return(c);
}

int yyerror(char * s)
{
    fprintf(stderr,"%s\n",s);
    return 0;
} // Allows for printing of an error message