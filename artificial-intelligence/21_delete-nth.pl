% deleting at 1st position is equivalent to stripping the head.
delete_nth(1, [H|T], R) :- R = T, !.

/*
 * To delete an item at the nth position,
 * 1. strip the head of the current list.
 * 2. delete the item at the (n-1)th position of the tail of the current list.
 * 3. add the head of the current list back to R.
 */
delete_nth(N, [H|T], [H|R]) :-
	N1 is N-1,
	delete_nth(N1, T, R).

