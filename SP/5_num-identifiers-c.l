%{
	#include <stdio.h>
	int num_identifiers = 0;
%}

%option noyywrap
KEYWORD		auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while|main
PREPROCDIR	#.*\n	
IDENTIFIER	[_a-zA-Z][A-Za-z0-9_]*
FUNCTION	{IDENTIFIER}\ *\(.*\)
STRING		\".*\"
COMMENT         [/]{2,}.*
%%
[ \n\t]		{}
{KEYWORD}	//{ printf("%s is a keyword!\n", yytext); }
{PREPROCDIR}	//{ printf("%s is a preprocessor directive!\n", yytext); }
{IDENTIFIER}	{ printf("%s\n", yytext); num_identifiers++;}
{FUNCTION}	// { printf("%s is a function or function call\n", yytext); }
{STRING}	//{ printf("%s is a string\n", yytext);}
{COMMENT}       //{ printf("%s is a comment\n", yytext);}
%%

int main(void) {
	printf("List of detected identifiers (function identifiers are not counted):\n");
	yylex();
	printf("Total number of identifiers: %d\n", num_identifiers);
	return 0;
}

