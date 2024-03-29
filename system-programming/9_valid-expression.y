%{

	#include <stdio.h>
	#include <ctype.h>
	#define YYSTYPE double

%}

%token NUMBER

%left '+' '-'
%left '*' '/'
%right UMINUS

%%

lines	: lines expr '\n'		{ printf("Valid expression! It's value is: %g\n", $2); }
     	| lines '\n'
	| /* empty */
	| error '\n' { yyerror("Invalid expression, please check and reenter"); yyerrok; }
	;

expr	: expr '+' expr	{ $$ = $1 + $3; }
     	| expr '-' expr	{ $$ = $1 - $3; }
     	| expr '*' expr	{ $$ = $1 * $3; }
     	| expr '/' expr	{ $$ = $1 / $3; }
	| '(' expr ')'  { $$ = $2; }
	| '-' expr %prec UMINUS { $$ = - $2; }
     	| NUMBER
	;

%%

yylex() {
	int c;
	while( (c = getchar()) == ' ' || c == '\t');
	if( (c == '.') || (isdigit(c)) ) {
		ungetc(c, stdin);
		scanf("%lf", &yylval);
		return NUMBER;
	}
	return c;
}

main() {
	printf("Enter an expression to check whether it is valid or not: \n");
	yyparse();
}

