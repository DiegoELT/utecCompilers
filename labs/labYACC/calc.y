%{
    #include <stdio.h>
    #include <ctype.h>
%}

%token numero

%%

command : exp   {printf("%d\n",$1);}
        ;  // Allows to print the result, as shown in the book.

exp     : exp opsuma term {if($2 == '+') $$ = $1 + $3; else $$ = $1 - $3;}
        | term            //{$$ = $1;}
        ;

opsuma  : '+'   //{$$ = $1;}
        | '-'   //{$$ = $1;}
        ;

term    : term opmult factor {$$ = $1 * $3;}
        | factor //{$$ = $1;}
        ;

opmult  : '*'   //{$$ = $1;}
        ;

factor  : numero        //{$$ = $1;}
        |'(' exp ')'    {$$ = $2;}
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
    else
    {
        ungetc(c, stdin);
        scanf("%c", &yylval);
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