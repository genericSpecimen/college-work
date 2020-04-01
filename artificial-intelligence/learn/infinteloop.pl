parent(X, Y) :- child(Y, X).
child(A, B) :- parent(B, A).

