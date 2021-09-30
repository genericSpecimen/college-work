%{
// C includes
#include <stdio.h>
%}

%option noyywrap

SL_COMMENT   \/\/.*$

OMS (\*)+
ML_COMMENT   "/*"([^*]|{OMS}[^*/])*{OMS}"/"

%%

{SL_COMMENT}    { printf("Single line comment matched, ignoring...: %s\n\n", yytext); }

{ML_COMMENT}    { printf("Multi-line comment matched, ignoring...: %s\n\n", yytext); }

.|\n    { fprintf(yyout, "%s", yytext); // write everything else into the output file
    }
%%

int main(void) {
    yyin = fopen("../test.cpp", "r");
    yyout = fopen("test_stripped_comments.cpp", "w");

    yylex();
    return 0;
}
