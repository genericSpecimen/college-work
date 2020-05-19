start	:-	write('Enter an integer: '), read(N),
		factorial(N, F),
		write(N), write('! = '), write(F).
/*
 * boundary condition:
 * 0! = 1, so F is instantiated with 1,
 * and we use the cut to indicate that no
 * more solutions are to be looked for when N = 0
 */
factorial(0, 1) :- 	!.
factorial(N, F)	:-	N > 0, N1 is N - 1,
			factorial(N1, F1),
			F is N * F1.

/*
 * if N > 0, then we first calculate (N-1)! and store it into F1
 * then N! = N * (N-1)! and we assign this value to F, the factorial of N
 */

