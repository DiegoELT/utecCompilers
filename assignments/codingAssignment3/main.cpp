#include <iostream>
#include <fstream>

extern int yylex();
extern int yylineno;
extern char* yytext;
extern FILE* yyin;

std::string types[] = {"null", "KEYWORD", "OPERATOR", "SPECIAL_SYMBOL", "IDENTIFIER", "INT_CONSTANT", "FLOAT_CONSTANT", "UNEXPECTED_CHAR"};

std::ofstream tokenTable("tokenTable.txt");

int main(int argc, char* argv[])
{
    yyin = fopen(argv[1],"r");
    int tokenCategory;
    tokenCategory = yylex();
    while (tokenCategory)
    {
        tokenTable << "(\"" << yytext << "\", " << types[tokenCategory] << ")\n"; 
        tokenCategory = yylex();
    }
    return 0;
}