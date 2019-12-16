%{
	#include <stdio.h>
%}

%option noyywrap

%%

float	{ fprintf(yyout, "double"); }

%%

int main() {
	yyin = fopen("input.txt", "r");
	yyout = fopen("output.txt", "w");
	yylex();
}

