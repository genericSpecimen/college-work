reverse(L, R) :- reverse(L, [], R).
reverse([], A, A) :- !.
reverse([H|T], A, R) :- reverse(T, [H|A], R).

% a list is a palindrome if the reverse of the list
% is the same as the original list.
palindrome(L) :- reverse(L, R), L = R.

