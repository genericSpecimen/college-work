% first element of a list is the head
nth_element(1, [H|T], X) :- X = H, !.

/*
 * nth_element of a list is (n-1)th element of the tail of the list
 * i.e.
 * 2nd element of a list is the 1st element of the tail of the list..
 * 3rd element of a list is the 2nd element of the tail of the list..
 * and so on...
 *
 * Thus, to find the Nth element in a list, we keep stripping off the head
 * of the list until we reach a stage where the 1st element of the remainder
 * list is the Nth element of the original list.
 * We recursively call nth_element with decreasing N until N == 1, where
 * the boundary condition gets satisfied and X is instantiated to the first element.
 * This element gets passed back up through the returning recursive calls.
 */
nth_element(N, [H|T], X) :-
	N1 is N-1,
	nth_element(N1, T, X).

