% S -> NP VP
sentence(A, C) :- np(A, B), vp(B, C).

% NP -> N | ART N 
np(A, B) :- noun(A, B).
np(A, C) :- art(A, B), noun(B, C).

% VP -> V | V NP | V PP
vp(A, B) :- verb(A, B).
vp(A, C) :- verb(A, B), np(B, C).
vp(A, C) :- verb(A, B), pp(B, C).

% PP -> PREP NP
pp(A, C) :- prep(A, B), np(B, C).

prep([at|X], X).

art([a|X], X).
art([the|X], X).

noun([dog|X], X).
noun([cow|X], X).
noun([moon|X], X).

verb([barked|X], X).
verb([winked|X], X).

