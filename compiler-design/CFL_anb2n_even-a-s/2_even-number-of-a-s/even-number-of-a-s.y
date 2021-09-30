%{

#include <stdio.h>

// to get rid of "implicit declaration" warnings
void yyerror(const char *str) {
    fprintf(stderr,"error: %s\n",str);
}
int yylex();

/*
 * The "lines" non terminal is used to handle multiple sentences,
 * one on each line. A line be a sentence S followed by '\n',
 * or, lines followed by S and '\n'. If neither of these productions
 * can be used to derive the parse tree, then we signal an error.
 *
 * A sentence in the language L = {s : s is a sentence with an even number of a's}
 * can be written using the following grammar:
 * S  -> a S1 | b S  | empty
 * S1 -> a S  | b S1
 * This grammar generates the language of all sentences
 * with even number of a's.
 * The productions S -> bS | empty can be used to generates
 * all sentences that start with b. But whenever an 'a' exists
 * in the sentence, the production S -> 'a' S1 says it must end
 * with S1, which either generates b's or a single 'a'. When it
 * S1 generates a single 'a', our pair of two a's is complete.
 */

%}

%%

lines   : lines S '\n' { printf("Valid sentence!\n\n"); }
        | /* empty */
        | error '\n' { yyerror("Invalid sentence!\n"); yyerrok; }
        ;
        
S       : 'a' S1
        | 'b' S
        | /* empty */
        ;

S1      : 'a' S
        | 'b' S1
        ;

%%

int main() {
    printf("Language: {s : s has an even number of a's} \n");
    printf("Enter a string to see if it belongs to this language: \n");
    yyparse();
    return 0;
}
