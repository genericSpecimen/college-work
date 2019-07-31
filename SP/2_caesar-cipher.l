%{
	#include <stdio.h>
%}

%option noyywrap

%%

x { printf("%c", 'a');}
y { printf("%c", 'b');}
z { printf("%c", 'c');}
X { printf("%c", 'A');}
Y { printf("%c", 'B');}
Z { printf("%c", 'C');}

[a-bA-Z] { printf("%c", yytext[0] + 3); }


%%

int main(void) {
	yylex();
	return 0;
}

