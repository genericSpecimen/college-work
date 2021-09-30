%{
// C includes
#include <stdio.h>
%}

%option noyywrap

STR_LITERAL     \"([^\\\"]|\\.)*\"

SL_COMMENT      \/\/.*$

OM_STARS        (\*)+
ML_COMMENT      "/*"([^*]|{OM_STARS}[^*/])*{OM_STARS}"/"

%%
{STR_LITERAL}   { printf("String Literal matched: %s\n\n", yytext); }

{SL_COMMENT}    { printf("Single Line comment matched: %s\n\n", yytext); }

{ML_COMMENT}    { printf("Multi-line comment matched:\n%s\n\n", yytext); }

.|\n
%%

int main(void) {
    yyin = fopen("../test.cpp", "r");
    yylex();
    return 0;
}
