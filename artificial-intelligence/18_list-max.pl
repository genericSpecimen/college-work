max(X, Y, MAX) :- X >= Y, !, MAX is X; MAX is Y.

/* maximum of a single list element is the element itself */
max_list([H], H).

/* maximum of a list = max(head, max of tail list) */
max_list([H|T], M) :- max_list(T, MT), max(H, MT, M).

