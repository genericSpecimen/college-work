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
fib(N, F)	:-	fib(N, F, _).

/*
 * F	= N	th fibonacci number
 * F1	= N-1	th fibonacci number
 * F0 	= N-2	th fibonacci number
 * to find the Nth fibonacci number F, we must find F0 and F1,
 * and add them, i.e. F(N) = F(N-2) + F(N-1).
 *
 * To do this, we keep track of the N-2 th fibonacci number in F0.
 * At the boundary conditions, once we find that F(0) = 0, and F(1) = 1,
 * F0 is instantiated with 0, and F1 with 1. Now, the recursive calls start
 * returning, instantiating F(N) with F(N-2) + F(N-1) at each level.
 */ 
fib(N, F, F1)	:-	N > 1,
			N1 is N - 1,
			fib(N1, F1, F0),	/* F0	= (N-1)-1 th fibonacci number */
			F is F0 + F1.		/* F(N) = F(N-2) + F(N-1) */

fib(0, 0, 0). /* N = 0 th fibonacci number is 0 */
fib(1, 1, 0). /* N = 1 st fibonacci number is 1  and (N-1) = 0 th fibonacci number is 0 */
/* ------------------------------------------------------ */

/* generate the fibonacci series starting from the A-th fibonacci number and ending at the B-th fibonacci number */
fib_sequence(A, B)	:-	A >= 0, A =< B,
				fib(A, R),
				write(R), write(', '),
				A1 is A + 1,
				fib_sequence(A1, B).


