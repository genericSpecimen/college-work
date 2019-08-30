%{
	#include <stdio.h>
	#include <stdlib.h>
%}

%option noyywrap

digit [0-9]

%%
{digit}+	{
		printf("Detected a number: %s\n", yytext);
	}

.|\n	{ /*ignore all other characters*/ }
%%

int main(void) {
	yylex();
	return 0;
}
