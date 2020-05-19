/*
 * if X is at the head, H, of the list,
 * then X is clearly a member of the list.
 * No need to look for further solutions, so
 * use the cut operator to disallow backtracking.
 */
 member(X, [X|_]) :- !.

% otherwise, search for X in the tail T of the list
member(X, [_|T]) :- member(X, T).

