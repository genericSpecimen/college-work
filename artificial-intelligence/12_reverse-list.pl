% initialize accumulator A to the empty list
reverse(L, R) :- reverse(L, [], R).

/*
 * boundary condition: when the list is empty, the reversed list is the
 * list that we have accumulated so far in A.
 */
reverse([], A, A) :- !.

/*
 * accumulate the head of the list to the head of accumulator A,
 * and recursively reverse the tail.
 * In effect, all the elements of the list will get accumulated
 * onto the head of A in reverse order.
 * The boundary condition then instantiates R to A.
 */
reverse([H|T], A, R) :- reverse(T, [H|A], R).

