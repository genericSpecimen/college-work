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

KEYWORD		{ printf("%s is a keyword!\n", yytext); }
INTEGER		{ printf("%s is an integer!", yytext); }	
FLOAT		{ printf("%s is a floating point number!", yytext); }
IDENTIFIER	{ printf("%s is an identifier!", yytext);}
OP		{ printf("%s is an operator!", yytext); }
COMMENT		{ printf("%s is a comment", yytext);}
.*		{ printf("Unknown character!"); }
%%

int main(void) {
	yylex();
	return 0;
}

