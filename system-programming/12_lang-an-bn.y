%{

	#include <stdio.h>
	#define YYSTYPE double

%}

%token a
%token b

%%

lines	: lines S '\n'		{ printf("Valid string!\n"); }
     	| lines '\n'
	| /* empty */
	| error '\n' { yyerror("Invalid string!\n"); yyerrok; }
	;

S	: a S b
  	| /* empty */
	;

%%

yylex() {
	int c;
	while( (c = getchar()) == ' ' || c == '\t');
	if(c == 'a') return a;
	if(c == 'b') return b;
	return c;
}

main() {
	printf("Language: {an bn, n>=1} \n");
	printf("Enter a string to see if it belongs to this language: \n");
	yyparse();
}

