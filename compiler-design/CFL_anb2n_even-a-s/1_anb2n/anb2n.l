%{
#include <stdio.h>
%}

%option noyywrap

WS [ \t]

%%

{WS}+   /* ignore whitespaces */
.|\n       return *yytext;

%%
