% first element of a list is the head
nth_element(1, [H|T], X) :- X = H, !.

/*
 * nth_element of a list is (n-1)th element of the tail of the list
 * i.e.
 * 2nd element of a list is the 1st element of the tail of the list..
 * 3rd element of a list is the 2nd element of the tail of the list..
 * and so on...
 */
nth_element(N, [H|T], X) :-
	N1 is N-1,
	nth_element(N1, T, X).

