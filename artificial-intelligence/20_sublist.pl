/*
 * To check if S is a sublist of L, we try to
 * break L into two lists L1 and L2, such that
 * the beginning of L2 contains the list S?
 * We break L2 into two lists, and check if
 * one of it is S.
 * If yes, then this means that L2 was formed by appending
 * S with some list L3. Therefore, L, which contains L2, also
 * contains sublist S.
 *
 * L = L1 L2
 * .......|\
 * L = L1 S L3
 *
 */
sublist(S, L) :- append(L1, L2, L), append(S, L3, L2).

