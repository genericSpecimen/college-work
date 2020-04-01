% move N discs from source peg (a) to target peg (c) using spare peg (b)
tower_of_hanoi(N) :- move(N, a, c, b), !.

move(N, Source, Target, Spare) :- N = 0, !.
move(N, Source, Target, Spare) :-
	N1 is N-1,
	move(N1, Source, Spare, Target),
	inform(N, Source, Target),
	move(N1, Spare, Target, Source).

inform(N, X, Y) :-
	write('Move disc '), write(N), write(' from peg '), write(X), write(' to peg '), write(Y), write("\n").
