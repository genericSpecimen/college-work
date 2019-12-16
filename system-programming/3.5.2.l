%{
	#include <stdio.h>
%}

%option noyywrap

%%

[ \t\n]+	{ fprintf(yyout, " "); /* replace by single space */ }

%%

int main() {
	yyin = fopen("input.txt", "r");
	yyout = fopen("output.txt", "w");
	yylex();
	return 0;
}

