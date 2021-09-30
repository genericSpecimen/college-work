%{
#include <stdio.h>
%}

%option noyywrap

DIGIT   [0-9]
DIGITS  {DIGIT}+
NUMBER  ({DIGITS}\.{DIGITS})|{DIGITS}

%%

[ \t]       {/* ignore blanks */}
{NUMBER}    { sscanf(yytext, "%lf", &yylval); return NUMBER; }
.|\n        { /* return other characters as is */ return yytext[0]; }

%%
