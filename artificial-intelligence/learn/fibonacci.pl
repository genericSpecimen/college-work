/*
fib(N, 0) :- N =< 0, !.
fib(N, 1) :- N = 1, !.
fib(N, R) :-
	N1 is N-1, N2 is N-2,
	fib(N1, R1), fib(N2, R2),
	R is R1+R2.
*/

fib(N, R) :- fib(N, R, Q).

fib(N, 0, 0) :- N =< 0, !.
fib(N, 1, 0) :- N = 1, !.

/*
 * R : N   th fibonacci number
 * Q : N-1 th fibonacci number
 */
fib(N, R, Q) :-
	% N > 1,
	N1 is N-1,
	fib(N1, Q, Q1), /* Q is N-1 th fib num, Q1 is N-2 th fib num */
	R is Q+Q1.

