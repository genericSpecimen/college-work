%{
	#include <stdio.h>
%}

%option noyywrap
OPERATOR	[+-/*%]
OPERAND		[0-9]+

%%

[\n]		{}
[ \t]*{OPERAND}[ \t]*({OPERATOR}[ \t]*{OPERAND}[ \t]*)+	{ printf("Valid\n");}
.+	{ printf("Not valid\n"); }

%%

int main(int argc, char *argv[]) {
	yylex();
	return 0;
}

