gcd(A, B, G) :- B = 0, !, G is A.
gcd(A, B, G) :-
	A1 is A mod B,
	gcd(B, A1, G).

