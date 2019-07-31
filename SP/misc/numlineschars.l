%{
	#include <stdio.h>
	int num_lines = 0, num_chars = 0;
	int num_spaces = 0, num_tabs = 0;
%}

%option noyywrap

%%

\n	++num_lines; ++num_chars;
[" "]	++num_spaces; ++num_chars;
\t	++num_tabs; ++num_chars;
. 	++num_chars;

%%

int main(void) {
	yylex();
	printf("# of lines = %d, # of chars = %d # of spaces = %d, # of tabs = %d\n", num_lines, num_chars, num_spaces, num_tabs);
	return 0;
}

