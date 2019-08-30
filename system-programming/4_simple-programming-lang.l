%{
	#include <stdio.h>
%}

%option noyywrap

KEYWORD		int|float|void|double|while|for|do|main|printf
DIGIT		[0-9]
INTEGER		{DIGIT}+
FLOAT		{DIGIT}+.{DIGIT}+
IDENTIFIER	[_a-zA-Z][A-Za-z0-9_]*
OP		[-+/*]
COMMENT		[/]{2,}.*

%%
[ \n\t]		{}
{KEYWORD}	{ printf("%s is a keyword!\n", yytext); }
{INTEGER}	{ printf("%s is an integer!\n", yytext); }	
{FLOAT}		{ printf("%s is a floating point number!\n", yytext); }
{IDENTIFIER}	{ printf("%s is an identifier!\n", yytext);}
{OP}		{ printf("%s is an operator!\n", yytext); }
{COMMENT}	{ printf("%s is a comment\n", yytext);}
%%

int main(void) {
	yylex();
	return 0;
}

