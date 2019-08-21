%{
	#include <stdio.h>
	int num_identifiers = 0;
%}

%option noyywrap
KEYWORD		int|float|void|double|while|for|do|main|printf
DIGIT		[0-9]
INTEGER		{DIGIT}+
FLOAT		{DIGIT}+.{DIGIT}+
IDENTIFIER	[_a-zA-Z][A-Za-z0-9_]*
OP		[-+/*]
COMMENT		[/]{2,}.*
NL		\n
%%

{KEYWORD}
{INTEGER}
{FLOAT}
{OP}
{COMMENT}
{NL}
{IDENTIFIER}					{ printf("Identifier!"); num_identifiers++;}
.*						{ printf("Unknown character!"); }
%%

int main(void) {
	yylex();
	printf("Number of identifiers: %d", num_identifiers);
	return 0;
}

