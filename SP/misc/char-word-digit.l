%{
	#include <stdio.h>
%}

%option noyywrap

character [A-Za-z]
word [a-zA-Z]+
digit [0-9]

%%

{character}	{ printf("%s: it is a character\n", yytext); }
{word}		{ printf("%s: it is a word\n", yytext);}
{digit}+	{ printf("%s: it is a number\n", yytext); }
.|\n	{ /*ignore all other characters*/ }
%%

int main(void) {
	yylex();
	return 0;
}
