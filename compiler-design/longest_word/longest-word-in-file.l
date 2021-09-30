%{

#include <stdio.h>
#include <string.h>

// keep track of the longest word and its length
int max_len = 0;
char longest_word[256];
%}

%option noyywrap

%%

[a-zA-Z]+ {
        // A word is a contiguous sequence of one or more alphabetic characters.
        // Therefore, when a word is matched, we check it's length. If it's greater
        // than the current max_len, we update the longest word and its length.
        
        // printf("%s is of %d\n", yytext, yyleng);
        if (yyleng > max_len) {
            max_len = yyleng;
            strcpy(longest_word, yytext);
            // printf("%s is the current longest\n", longest_word);
        }
    }
.|\n
%%

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Please enter filename to read in the argument. Example: ./a.out sample_text.txt\n");
        return 0;
    }
    yyin = fopen(argv[1], "r");
    printf("File: %s\n\n", argv[1]);
    yylex();
    
    printf("Longest word: '%s' (%d characters) \n", longest_word, max_len);
    
    fclose(yyin);
    return 0;
}
