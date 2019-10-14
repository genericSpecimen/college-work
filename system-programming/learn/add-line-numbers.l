%{
	#include <stdio.h>
	int line_num = 1;
%}

%option noyywrap

%%

.*\n	{ printf("%d %s", line_num, yytext); ++line_num; }

%%

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Please enter filename to read in the argument. Example: ./a.out filename\n");
		return 0;
	}
	yyin = fopen(argv[1], "r");
	printf("File: %s\n\n", argv[1]);
	yylex();
	fclose(yyin);
	return 0;
}

