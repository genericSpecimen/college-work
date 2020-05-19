% move N discs from source peg (a) to target peg (c) using spare peg (b)
tower_of_hanoi(N) :- move(N, a, c, b), !.

/*
 * if number of discs N == 0, then nothing is to be done,
 * and we indicate that we don't want to look for other solutions
 * using the cut operator.
 */
move(N, Source, Target, Spare) :- N = 0, !.

/*
 * Otherwise, the algorithm is:
 * To move N discs from Source peg to Target peg using a Spare peg,
 * 1. Move N-1 discs from the Source peg to Spare peg using the Target peg as a spare peg
 * 2. Move the Nth disc from the Source to the Target peg
 * 3. Move N-1 discs from the Spare peg to the Target peg using Source peg as a spare peg
 */

move(N, Source, Target, Spare) :-
	N1 is N-1,
	move(N1, Source, Spare, Target),
	inform(N, Source, Target),
	move(N1, Spare, Target, Source).

inform(N, X, Y) :-
	write('Move disc '), write(N), write(' from peg '), write(X), write(' to peg '), write(Y), write("\n").

