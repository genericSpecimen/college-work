%{
// C includes
#include <stdio.h>
%}

%option noyywrap

WS  [ \t]+

%%
{WS} {
        /* If a sequence of one or more whitespaces
         * is matched, then it gets replaced by a
         * single space.
         */
        printf(" ");
    }
%%

int main(void) {
    yylex();
    return 0;
}
