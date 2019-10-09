%{

	#define YYSTYPE double
	#include <math.h>

%}

%token NUM

%%

input	: input line '\n'
	| /* empty */
	;

line	: exp '\n' { printf ("\t%.10g\n", $1); }
	| '\n'
	;

exp	: NUM { $$ = $1; }
    	| exp exp '+' { $$ = $1 + $2; }
    	| exp exp '-' { $$ = $1 - $2; }
    	| exp exp '*' { $$ = $1 * $2; }
    	| exp exp '/' { $$ = $1 / $2; }
    	| exp exp '^' { $$ =  pow($1, $2); }
	| exp 'n' { $$ = -$1;}
	;
%%


