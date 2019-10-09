%{

	#include <stdio.h>
	#include <ctype.h>
	#define YYSTYPE double

%}

%token LCASELETTER
%token UCASELETTER
%token DIGIT

%%

lines	: lines var '\n'		{ printf("Valid variable!\n"); }
      	| lines '\n'
	| /* empty */
	| error '\n' { yyerror("Invalid variable!"); yyerrok; }
	;

var	: LCASELETTER alnum
	;

alnum	: LCASELETTER alnum
      	| UCASELETTER alnum
	| DIGIT alnum
	| LCASELETTER
	| UCASELETTER
	| DIGIT

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
	if ( isupper(c) ) {
		yylval = c;
		return UCASELETTER;
	}
	return c;
}

main() {
	printf("This program checks whether the variable name entered starts with a lowercase letter followed by 1 or more occurences of alphanumeric characters. \n");
	printf("Enter a variable name to check if it is valid or not:\n");
	yyparse();
}

