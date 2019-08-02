%{
	#include <stdio.h>
	#include <string.h>
	char * word = NULL;
	char * longest = NULL;
	int max = -1;
	int len = -1;
%}

%option noyywrap

%%

[a-zA-Z]+ {
		word = yytext;
		len = strlen(word);
		// printf ("%s with length %d ", word, len);
		if (len > max) {
			// printf("%d > %d", len, max);
			longest = word;
			max = len;
			// printf("%s is current longest with %d length", longest, max);
		} else {
			// printf("hecc\n");
		}
	}

%%

int main(void) {
	printf("Press Ctrl-D (on unix) or Ctrl-Z (on windows) when you are done entering..\n");
	yylex();
	printf("%s is the longest word, and is of %d characters \n", longest, max);
	return 0;
}

