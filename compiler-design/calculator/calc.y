%{
// ordinary C declarations
#include <stdio.h>
#define YYSTYPE double

// to get rid of "implicit declaration" warnings
int yylex();
void yyerror(const char *s);

/*
 * Parser
 * Input: sequence of tokens from the lexical analyzer
 * Process: parse tokens and check if the sequence of tokens can be derived from the start symbol.
 * Output: if the sequence of tokens are valid, evaluate and print the value of the expression.
 *
 *
 * After %}, we declare grammar tokens. There is only one grammar token called DIGIT.
 * These token declarations are made available to the analyzer generated by Lex using
 * the #include "y.tab.h" statement in the .l file. y.tab.h is created by yacc when
 * we pass the -d option.
 *
 * After %%, we write the translation rules consisting of a grammar production and
 * the semantic action to be performed, which is simply evaluating the value of the expression.
 * $$ refers to attribute value of the nonterminal of the head.
 * $i refers to the attribute value of the ith grammar symbol.
 * The semantic action is performed whenever the production is used for reduction.
 *
 * Since we will be using an ambiguous expression grammar, we use:
 * %left '+' '-' to assign the same precedence to them and be left associative.
 * %right UMINUS is a terminal used to denote the unary minus operator, which is
 * right associative and has a higher precedence than +,-,*,/ (therefore written after these)
 */
%}

%token NUMBER

%left '+' '-'
%left '*' '/'
%right UMINUS

%%

lines   : lines expr '\n'   {
                /* When an input containing an expression followed by a newline is found, print the value of the expression*/
                printf("= %g\n", $2);
            }
        | lines '\n' { /* this also allows a sequence of expressions to be evaluated (each on a new line) */ }
        | /* empty alternative */
        | error '\n'    {
                    /* Print error when a syntax error is encountered on a line, and reset normal mode of operation using yyerrok */
                    yyerror("Invalid expression, please check and reenter"); yyerrok;
                    }
        ;
        
expr	: expr '+' expr	{ $$ = $1 + $3; }
        | expr '-' expr	{ $$ = $1 - $3; }
        | expr '*' expr	{ $$ = $1 * $3; }
        | expr '/' expr	{ $$ = $1 / $3; }
        | '(' expr ')'  { $$ = $2; }
        | '-' expr %prec UMINUS { $$ = - $2; /* force the precedence of this production to be the same as UMINUS, i.e. highest */}
        | NUMBER
        ;

%%

int main() {
    printf("Enter an expression to evaluate it: \n");
    yyparse();
}

