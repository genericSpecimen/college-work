/* --- Basic implementation with two recursive calls ---- */
/*
fib(N, F)	:-	N > 1,
			N2 is N-2, fib(N2, F2),
			N1 is N-1, fib(N1, F1),
			F is F2 + F1.
fib(0, 0).
fib(1, 1).
*/
/*--------------------------------------------------------*/


/* ---- Implementation with only one recursive call ----- */
fib(N, T)	:-	fib(N, T, _).

/* T	= N	th fibonacci number */
/* T1	= N-1	th fibonacci number */
fib(N, T, T1)	:-	N > 1,
			N1 is N - 1,
			fib(N1, T1, T0),	/* T0	= (N-1)-1 th fibonacci number */
			T is T0 + T1.		/* T(N) = T(N-2) + T(N-1) */

fib(0, 0, 0). /* N = 0 th fibonacci number is 0 */
fib(1, 1, 0). /* N = 1 st fibonacci number is 1  and (N-1) = 0 th fibonacci number is 0 */
/* ------------------------------------------------------ */

/* generate the fibonacci series starting from the A-th fibonacci number and ending at the B-th fibonacci number */
fib_sequence(A, B)	:-	A >= 0, A =< B,
				fib(A, R),
				write(R), write(', '),
				A1 is A + 1,
				fib_sequence(A1, B).


