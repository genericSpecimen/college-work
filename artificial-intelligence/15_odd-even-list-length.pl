% length of empty list is 0
list_length([], 0) :- !.

% length of nonempty list = 1 + length of tail of the list
list_length([H|T], L) :-
	list_length(T, L1),
	L is L1+1.

% length L of a list is even if L mod 2 == 0 (L is divisible by 2)
even_length(List) :-
	list_length(List, L),
	R is L mod 2,
	R = 0.

% if length of list is not even, then it must be odd.
% the goal \+ P succeeds iff goal P fails.
odd_length(List) :- \+ even_length(List).

