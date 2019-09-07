%{
	#include <stdio.h>
	int num_lines = 0, num_bs = 0, num_chars = 0, num_words = 0;
%}

%option noyywrap

WORD		[a-zA-Z]+

%%
\n			{ /*printf("New line ");*/ num_lines++; num_chars++; }
[[:space:]]		{ /*printf("space ");*/ num_bs++; num_chars++; }
{WORD}			{ /*printf("word ");*/ num_words++; num_chars += yyleng; }
.			{ /*printf("unknown character ");*/ num_chars++;}
%%

int main(int argc, char*argv[]) {
	if(argc != 2) {
		printf("Please enter filename to read. Example: ./a.out hello.c\n");
		return 1;
	}
	yyin = fopen(argv[1], "r");
	yylex();
	printf("Number of\n\twords: %d\n\tcharacters: %d\n\tblank spaces: %d\n\tlines: %d\n", num_words, num_chars, num_bs, num_lines);
	return 0;
}

