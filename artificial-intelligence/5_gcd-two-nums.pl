start	:-	write('Enter first  number: '), read(X),
		write('Enter second number: '), read(Y),
		gcd(X, Y, R), write('\n'),
		write(' gcd of '), write(X), write(' and '), write(Y), write(' = '), write(R).


gcd(A, B, G) :- B = 0, !, G is A.
gcd(A, B, G) :-
	A1 is A mod B,
	gcd(B, A1, G).

