/*
start	:-	write('Enter an integer: '), read(N),
		factorial(N, F),
		write(N), write('! = '), write(F).
*/

/*
 * Boundary condition (base case):
 * 0! = 1, so F is instantiated with 1, and we use the cut to indicate that no more solutions are to be looked for when N = 0
 */
factorial(0, 1) :- 	!.

/*
 * Recursive case:
 * if N > 0, then we first calculate (N-1)! and instantiate F1 with the value. To calculate (N-1)!, we must calculate (N-2)!, and so on, until the base case is reached.
 * When the recursive call returns at some recursion level, we multiply N with (N-1)!, because N! = N * (N-1)!. Then, F is instantiated with this value, which is the factorial of N.
 */
factorial(N, F)	:-	N > 0, N1 is N - 1,
			factorial(N1, F1),
			F is N * F1.

