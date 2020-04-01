lsum([], 0).
lsum([H|T], S) :- lsum(T, ST), S is ST + H.

