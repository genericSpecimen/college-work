%{
	#include <stdio.h>
%}

%option noyywrap

%%

[a-zA-Z]* {
		for (int i = yyleng; i > 0; i--) {
			for (int j = 0; j < i; j++) {
				printf("%c ", yytext[j]);	
			}
			printf("\n");
		}
	}
.	

%%

int main(void) {
	yylex();
	return 0;
}

