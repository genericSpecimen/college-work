%{
	#include <stdio.h>
	// #include <string.h>
	int max = 0;
	char * longest = NULL;
%}

%option noyywrap

%%

[a-zA-Z]+ {
		printf("%s is of %d", yytext, yyleng);
		if (yyleng >= max) {
			max = yyleng;
			longest = yytext;
			printf("%s is the current longest\n", longest);
		}
	}
%%

int main(void) {
	printf("Press Ctrl-D (on unix) or Ctrl-Z (on windows) when you are done entering..\n");
	yylex();
	printf("%s is the longest word, and is of %d characters \n", longest, max);
	return 0;
}

