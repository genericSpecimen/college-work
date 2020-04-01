% base case: an empty list concatenated with L is the list L itself.
conc([], L, L) :- !.

/*
 * recursive case:
 * Recursively strip off the head of the first list until
 * only the empty list is left. Then, the base case applies and L3
 * is instantiated to L2 (which was passed as is upon each call).
 * When the recursive calls start returning, the heads of the
 * first list will get prepended to L3 (which was instantiated with L2).
 * In effect, the elements of first list in reverse order will get
 * prepended with L3.
 * In other words, elements of L3 will contain elements of L1 followed
 * by elements of L2, i.e. L3 is the concatenation of L1 and L2.
 */
conc([H|L1], L2, [H|L3]) :- conc(L1, L2, L3).

