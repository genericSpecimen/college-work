%{
	#include <stdio.h>
%}

%option noyywrap

%%
[A-Z] {
		char ch = yytext[0];
		ch = ((ch - 'A' + 3) % 26) + 'A';
		printf ("%c", ch);
	}
[a-z] {
		char ch = yytext[0];
		ch = ((ch - 'a' + 3) % 26) + 'a';
		printf ("%c", ch);
	}


%%

int main(void) {
	yylex();
	return 0;
}

