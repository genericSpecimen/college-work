%{
	#include <stdio.h>
%}

%option noyywrap
OPERATOR	[+-/*%]
OPERAND		[0-9]+

%%
[\t\n]		{}
{OPERAND}({OPERATOR}{OPERAND})+	{ printf("valid\n");}
%%

int main(int argc, char *argv[]) {
	yylex();
	return 0;
}

