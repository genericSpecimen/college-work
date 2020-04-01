max(X, Y, R) :-
	X > Y, R is X, !;
	R is Y.

