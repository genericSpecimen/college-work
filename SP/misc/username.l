%{
	#include <stdio.h>
%}

%option noyywrap

%%

username printf("%s", getlogin());

%%

int main(void) {
	yylex();
	return 0;
}
