%{
// C includes
#include <stdio.h>
int num_integers = 0;
int num_fp = 0;
%}

%option noyywrap

DIGIT       [0-9]

FRACTION    \.{DIGIT}+
EXPONENT    (E|E(\+|\-)){DIGIT}+
FP          ({DIGIT}+{FRACTION})|({DIGIT}+{EXPONENT})|({DIGIT}+{FRACTION}{EXPONENT})

INTEGER     {DIGIT}+
%%

{FP}        {
    /*
     * Since a floating point number is a longer match, we first try
     * to match FP numbers. An FP number is one or more digits followed
     * by an optional fractional part, and, an optional exponent part.
     */
    printf("FP number: %s\n", yytext); num_fp++;
}

{INTEGER}   {
    /* An integer is simply a sequence of one or more digits.
     * If an FP number wasn't matched on a line, it's possible
     * that the number could be an integer.
     */
    printf("Integer  : %s\n", yytext); num_integers++; }
.|\n
%%


int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Please enter filename to read in the argument. Example: ./a.out numbers.txt\n");
        return 0;
    }
    printf("List of detected integers and floating point (FP) numbers in file '%s':\n", argv[1]);
    yyin = fopen(argv[1], "r");
    yylex();
    
    printf("----------------------------------\n");
    printf("Total number of integers  : %d\n", num_integers);
    printf("Total number of FP numbers: %d\n", num_fp);
    printf("----------------------------------\n");
    
    fclose(yyin);
    return 0;
}
