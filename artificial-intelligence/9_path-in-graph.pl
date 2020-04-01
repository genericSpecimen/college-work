edge(p, q).
edge(q, r).
edge(r, s).
edge(s, t).
edge(t, p).
edge(r, p).

path(X, Y) :- path(X, Y, T).
path(X, X, T) :- !.
path(X, Y, T) :-
	edge(X, Z), not_visited(Z, T), path(Z, Y, [Z|T]).

not_visited(X, []).
not_visited(X, [H|T]) :- \+ X=H, not_visited(X, T).

