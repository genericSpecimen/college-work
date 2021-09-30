%{
// this is needed to include the tokens declared in .y file
#include "y.tab.h"

/*
 * Lexical Analyzer
 * Input: a stream of characters
 * Process: match numbers and operators
 * Output: a stream of tokens and their corresponding attribute values stored in yylval
 */
%}

%option noyywrap

DIGIT   [0-9]
DIGITS  {DIGIT}+
NUMBER  ({DIGITS}\.{DIGITS})|{DIGITS}

%%

[ \t]+       {/* ignore blanks */}
{NUMBER}    {
                /* 
                 * Whenever a number is matched, we return the NUMBER token to the parser.
                 * The attribute value associated with the NUMBER token will be sent to
                 * the parser using the yylval variable.
                 */
                sscanf(yytext, "%lf", &yylval); return NUMBER; }
.|\n        { /* return other characters as is */ return yytext[0]; }

%%
