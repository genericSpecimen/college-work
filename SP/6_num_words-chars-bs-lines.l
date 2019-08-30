%{
	#include <stdio.h>
	int num_lines = 0, num_bs = 0, num_chars = 0, num_words = 0;
%}

%option noyywrap

WORD		[a-zA-Z]+

%%
\n			{ num_lines++; num_chars++; }
[[:space:]]		{ num_bs++; num_chars++; }
{WORD}			{ num_words++; num_chars += yyleng; }
.*			{ num_chars++; }
%%

int main(void) {
	yylex();
	printf("\n\nNumber of\nwords: %d\ncharacters: %d\nblank spaces: %d\nlines: %d\n", num_words, num_chars, num_bs, num_lines);
	return 0;
}

