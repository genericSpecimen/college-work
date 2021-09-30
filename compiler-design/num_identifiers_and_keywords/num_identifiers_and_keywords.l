%{

#include <stdio.h>
int num_keywords    = 0;
int num_identifiers = 0;

%}

%option noyywrap

KEYWORD asm|else|new|this|auto|enum|operator|throw|bool|explicit|private|true|break|export|protected|try|case|extern|public|typedef|catch|false|register|typeid|char|float|reinterpret_cast|typename|class|for|return|union|const|friend|short|unsigned|const_cast|goto|signed|using|continue|if|sizeof|virtual|default|inline|static|void|delete|int|static_cast|volatile|do|long|struct|wchar_t|double|mutable|switch|while|dynamic_cast|namespace|template|and|bitor|not_eq|xor|and_eq|compl|or|xor_eq|bitand|not|or_eq

PREPROCDIR  ^#.*\n

IDENTIFIER	[_a-zA-Z][A-Za-z0-9_]*

SL_COMMENT   \/\/.*$
OMS (\*)+
ML_COMMENT   "/*"([^*]|{OMS}[^*/])*{OMS}"/"

STR_LITERAL     \"([^\\\"]|\\.)*\"

%%
{SL_COMMENT}    {}
{ML_COMMENT}    {}
{STR_LITERAL}   {}
{KEYWORD}       {printf("KEYWORD: %s\n", yytext); num_keywords++;}
{PREPROCDIR}    //{printf("PREPROC: %s\n", yytext); }
{IDENTIFIER}    { printf("IDENTIFIER: %s\n", yytext); num_identifiers++;}
.|\n
%%

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Please enter filename to read in the argument. Example: ./a.out test.cpp\n");
        return 0;
    }
    printf("List of detected identifiers and keywords in file '%s':\n", argv[1]);
    yyin = fopen(argv[1], "r");
    yylex();
    
    printf("----------------------------------\n");
    printf("Total number of keywords    : %d\n", num_keywords);
    printf("Total number of identifiers : %d\n", num_identifiers);
    printf("----------------------------------\n");
    
    fclose(yyin);
    return 0;
}
