reverse(L, R) :- reverse(L, [], R).
reverse([], A, A) :- !.
reverse([H|T], A, R) :- reverse(T, [H|A], R).

palindrome(L) :- reverse(L, R), L = R.

