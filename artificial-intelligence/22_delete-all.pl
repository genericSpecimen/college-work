% deleting all occurences of X from empty list results in the empty list
delete_all(X, [], []) :- !. 

/*
 * if the head of the list is X, then don't add this to R.
 * Continue deleting occurences of X in the tail of the list
 * with a recursive call
 */
delete_all(X, [X|T], R) :- delete_all(X, T, R), !.

/*
 * if the head of the list is not X, (the cut in the previous clause guarantees this),
 * then add this to the head of R.
 * Continue deleting occurences of X on the tail of the list.
 */
delete_all(X, [H|T], [H|R]) :- delete_all(X, T, R).

