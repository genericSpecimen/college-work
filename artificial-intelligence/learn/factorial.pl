fact(X, 1) :- X =< 0, !.
fact(X, R) :- X1 is X-1, fact(X1, R1), R is R1*X.

