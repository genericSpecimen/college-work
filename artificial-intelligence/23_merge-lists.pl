% boundary conditions
merge_lists([], [], []) :- !.
merge_lists([], L, L) :- !.
merge_lists(L, [], L) :- !.

/*
 * To merge two sorted lists,
 * 1. compare the heads of the two lists.
 * 2. make the smaller head of the two the head of the merged list
 * 3. merge the remaining lists, excluding the head that was already added.
 */
merge_lists([H1|T1], [H2|T2], [H3|T3]) :-
	H1 < H2, H3 = H1, !, merge_lists(T1, [H2|T2], T3);
	H3 = H2, merge_lists([H1|T1], T2, T3).

