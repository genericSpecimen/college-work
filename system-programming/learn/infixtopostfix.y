%{

	#include <stdio.h>
	#include <ctype.h>

%}

%token ZERO ONE TWO THREE FOUR FIVE SIX SEVEN EIGHT NINE

%%

lines	: lines expr '\n'		
      	| lines '\n'
	|

expr	: expr '+' term		{ printf("+"); }
     	| expr '-' term		{ printf("-"); }
	| term

term	: ZERO	{ printf("0");}
     	| ONE	{ printf("1");}
     	| TWO	{ printf("2");}
     	| THREE	{ printf("3");}
     	| FOUR	{ printf("4");}
     	| FIVE	{ printf("5");}
     	| SIX	{ printf("6");}
     	| SEVEN	{ printf("7");}
     	| EIGHT	{ printf("8");}
     	| NINE	{ printf("9");}
	;

%%

yylex() {
	int c;
	c = getchar();
	if(isdigit(c)) {
		yylval = c - '0';
		switch (yylval) {
			case 0: return ZERO; break;
			case 1: return ONE; break;
			case 2: return TWO; break;
			case 3: return THREE; break;
			case 4: return FOUR; break;
			case 5: return FIVE; break;
			case 6: return SIX; break;
			case 7: return SEVEN; break;
			case 8: return EIGHT; break;
			case 9: return NINE; break;
		}
	}
	return c;
}

