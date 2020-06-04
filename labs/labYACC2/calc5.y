%{
    #include <stdio.h>
    #include <stdlib.h>

    extern int yylex();
    extern int yyparse();
    extern int yyerror();

%}

%token number

%%

command : exp   {printf("%d\n",$1);}
        ;  // Allows to print the result, as shown in the book.

exp     : exp opsuma term {if($2 == '+') $$ = $1 + $3; else $$ = $1 - $3;}
        | term            {$$ = $1;}
        ;

opsuma  : '+'   {$$ = $1;}
        | '-'   {$$ = $1;}
        ;

term    : term opmult factor {$$ = $1 * $3;}
        | factor             {$$ = $1;}
        ;

opmult  : '*'           {$$ = $1;}
        ;

factor  : number        {$$ = $1;}
        |'(' exp ')'    {$$ = $2;}
        ;

%%

int main()
{
    yyparse();
}

int yyerror(char * s)
{
    fprintf(stderr, "Parse error: %s\n", s);
    return 0;
} // Allows for printing of an error message