%{

#include <stdio.h>

// to get rid of "implicit declaration" warnings
void yyerror(const char *str) {
    fprintf(stderr,"error: %s\n",str);
}
int yylex();

/*
 * The "lines" non terminal is used to handle multiple sentences,
 * one on each line. A line be empty, or, a sentence S followed by '\n',
 * or, lines followed by S and '\n'. If neither of these productions
 * can be used to derive the parse tree, then we signal an error.
 *
 * A sentence in the language L = {a^n b^2n : n >= 0} can be written using
 * the following grammar:
 * S -> aSbb | empty
 */

%}

%%

lines   : lines S '\n' { printf("Valid sentence!\n\n"); }
        | /* empty */
        | error '\n' { yyerror("Invalid sentence!\n"); yyerrok; }
        ;
        
S       : 'a' S 'b' 'b'
        | /* empty */
        ;

%%

int main() {
    printf("Language: {a^nb^2n : n >= 0} \n");
    printf("Enter a string to see if it belongs to this language: \n");
    yyparse();
    return 0;
}
