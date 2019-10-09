%{

	#include <stdio.h>
	#include <ctype.h>
	#define YYSTYPE double

%}

%token LCASELETTER
%token DIGIT

%%

lines	: lines var '\n'		{ printf("Valid variable!\n", $2); }
      	| lines '\n'
	| /* empty */
	| error '\n' { yyerror("Invalid variable!"); yyerrok; }
	;

var	: LCASELETTER DIGIT
	;

%%

yylex() {
	int c;
	while( (c = getchar()) == ' ' || c == '\t'); // ignore spaces
	if( isdigit(c) ) {
		yylval = c;
		return DIGIT;
	}
	if( islower(c) ) {
		yylval = c;
		return LCASELETTER;
	}
	return c;
}

main() {
	printf("This program checks whether the variable name entered starts with a lowercase letter and ends with a digit. e.g, a1, b1, c5 are valid. \n");
	printf("Enter a variable name to check if it is valid or not:\n");

	yyparse();
}

