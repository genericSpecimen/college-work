/* sum of an empty list = 0 */
list_sum([], 0).

/* sum of a list [H|T] = H + sum of list [T] */
list_sum([H|T], S) :- list_sum(T, S1), S is S1 + H.

