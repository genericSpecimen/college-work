/*
 * can L be broken into two lists L1 and L2,
 * such that head of L2 contains the list S?
 */
sublist(S, L) :- append(L1, L2, L), append(S, L3, L2).

