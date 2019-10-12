%{
	#include <stdio.h>
	int num_lines = 0, num_chars = 0;
%}

%option noyywrap

%%

\n	++num_lines; ++num_chars;
. 	++num_chars;

%%

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Please enter filename to read in the argument. Example: ./a.out filename\n");
		return 0;
	}
	yyin = fopen(argv[1], "r");
	printf("In file: %s\n", argv[1]);
	yylex();
	printf("# of lines = %d, # of chars = %d\n", num_lines, num_chars);
	fclose(yyin);
	return 0;
}

