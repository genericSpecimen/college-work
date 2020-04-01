list_length([], 0) :- !.
list_length([H|T], L) :-
	list_length(T, L1),
	L is L1+1.

even_length(List) :-
	list_length(List, L),
	R is L mod 2,
	R = 0.

odd_length(List) :- \+ even_length(List).

