%{
#include <stdio.h>
#include <string.h>

// to keep track of line number in the file
int line_num = 0;

char* longestWordInLine(char *line) {
    char * longest_word = "";
    int max_len = 0;
    
    // split the line into tokens, where delimiters can be : space, comma, period, dash, tab
    char * tok = strtok(line, " ,.-\t");
    while (tok != NULL) {
        // for each token returned, check if its length is more than the current max_len
        // if yes, update the longest word in line.
        if (strlen(tok) > max_len) {
            max_len = strlen(tok);
            longest_word = tok;
        }
        tok = strtok(NULL, " ,.-\t");
    }
    
    return longest_word;
}

%}

%option noyywrap

%%

[^\n]+$ {
        // a line is a sequence of one or more non-newline characters followed by a new line character.
        // When a line is matched, we use the longestWordInLine function to return the longest word in
        // this line. NOTE: this doesn't match empty lines.
        char * longest_word = longestWordInLine(yytext);
        printf("Line %d : '%s' (%d characters).\n", ++line_num, longest_word, strlen(longest_word));
    }
.|\n
%%

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Please enter filename to read in the argument. Example: ./a.out sample_text.txt\n");
        return 0;
    }
    yyin = fopen(argv[1], "r");
    printf("Longest Words in each line of File: %s\n\n", argv[1]);
    yylex();
    fclose(yyin);
    return 0;
}
