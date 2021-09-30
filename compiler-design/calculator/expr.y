%{
// ordinary C declarations
#include <stdio.h>
#define YYSTYPE double

// to get rid of "implicit declaration" warnings
int yylex();
void yyerror(const char *s);

%}

%token NUMBER

%%

S       : expr '\n' {printf("= %g\n", $1);}
        ;
        
expr    : expr '+' term { $$ = $1 + $3; }
        | term
        ;

term    : term '*' factor { $$ = $1 * $3; }
        | factor
        ;

factor: '(' expr ')'
        | NUMBER
        ;

%%

int main() {
    printf("Enter an expression to evaluate it: \n");
    yyparse();
}

