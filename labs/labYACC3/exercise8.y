%{
    #include <stdio.h>
    #include <ctype.h>
%}

%%

sentencia : sentif {}
          | ';'    {}
          ;

sentif   : 'i' 'f' '(' exp ')' sentencia                           {}
         | 'i' 'f' '(' exp ')' sentencia 'e' 'l' 's' 'e' sentencia {}
         ;

exp      : '0' {}
         | '1' {}

%%

int main()
{
    return yyparse();
}