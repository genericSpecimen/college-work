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
DIGIT		[0-9]
INTEGER		{DIGIT}+
FLOAT		{DIGIT}+.{DIGIT}
COMMENT         [/]{2,}.*

%%
[ \n\t{;}=,]|{INTEGER}|{FLOAT}		{}
{KEYWORD}	//{ printf("%s is a keyword!\n", yytext); }
{PREPROCDIR}	//{ printf("%s is a preprocessor directive!\n", yytext); }
{IDENTIFIER}	{ printf("%s\n", yytext); num_identifiers++;}
{FUNCTION}	// { printf("%s is a function or function call\n", yytext); }
{STRING}	//{ printf("%s is a string\n", yytext);}
{COMMENT}       //{ printf("%s is a comment\n", yytext);}
%%

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Please enter filename to read in the argument. Example: ./a.out helloworld.c\n");
		return 0;
	}
	printf("List of detected identifiers (function identifiers are not counted) in file '%s':\n", argv[1]);
	yyin = fopen(argv[1], "r");
	yylex();
	printf("Total number of identifiers: %d\n", num_identifiers);
	fclose(yyin);
	return 0;
}

