/* Length of an empty list = 0 */
list_length([], 0).

/* Length of a list [H|T] = 1 + length of list[T] */
list_length([H|T], L) :- list_length(T, L1), L is L1 + 1.

