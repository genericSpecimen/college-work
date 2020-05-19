start	:-	write('Enter first  number: '), read(X),
		write('Enter second number: '), read(Y),
		gcd(X, Y, R), write('\n'),
		write(' gcd of '), write(X), write(' and '), write(Y), write(' = '), write(R).

/*
 * if B == 0, then the GCD(A, B) = A. This, we set G to A. We don't look for
 * any more solutions if B == 0, as indicated by the cut.
 *
 * Otherwise, we use the recursive procedure as shown,
 * which uses A and B to hold the alternating remainders.
 * In the first call, if A < B, then A and B get swapped,
 * and the subsequent calls are the same as when A > B.
 *
 * Now, A > B, and we calculate the remainder of A/B, and set A1 to the remainder.
 * Then, gcd(A, B) = gcd(B, A mod B).
 */
gcd(A, B, G) :- B = 0, !, G is A.
gcd(A, B, G) :-
	A1 is A mod B,
	gcd(B, A1, G).

