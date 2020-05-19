% boundary conditions
% an empty list merged with an empty list is the empty list
merge_lists([], [], []) :- !.
% an empty list merged with a nonempty list L is the list L
merge_lists([], L, L) :- !.
% same as above, with interchanged arguments
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

/*
 * if (H1 < H2), this means that the head of the first list
 * is less than the head of the second list. Thus, the head
 * of the merged list, H3, is instantiated with H1 (the smaller value)
 * and now we merge the remaining part (tail) of first list, T1, and all
 * of the second list into the tail (T3) of the merged list using a recursive call
 *
 * Otherwise, H1 >= H2, this means that the head of the first list is
 * greater than or equal to the head of the second list. Therefore, the
 * head of the merged list H3, is instantiated with the head of the second list, H2,
 * and then the remaining tail of second list, T2, is merged with all of the first list
 * using a recursive call
 */

