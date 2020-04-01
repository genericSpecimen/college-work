max(X, Y, R) :- X > Y, R is X, !; R is Y.

lmax([H], H) :- !.
lmax([H|T], M) :-
	lmax(T, M1),
	max(H, M1, M).

