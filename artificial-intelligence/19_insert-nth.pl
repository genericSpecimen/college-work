% inserting at 1st position is equivalent to prepending the item to list L.
insert_nth(Item, 1, L, R) :- R = [Item|L], !.

/*
 * To insert an item at the nth position,
 * 1. strip the head of the current list.
 * 2. insert the item at the (n-1)th position of the tail of the current list.
 * 3. add the head of the list back to R.
 */
insert_nth(Item, N, [H|T], [H|R]) :-
	N1 is N-1,
	insert_nth(Item, N1, T, R).

