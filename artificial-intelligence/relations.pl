parent(priya, bobby).
parent(tilak, bobby).
parent(tilak, lalita).
parent(bobby, anita).
parent(bobby, pratiksha).
parent(pratiksha, john).

female(priya).
female(lalita).
female(anita).
female(pratiksha).
male(tilak).
male(bobby).
male(john).

% Y is an offspring of X if X is a parent of Y
offspring(Y, X)	:- parent(X, Y).

% X is the father of Y if X is male and is parent of Y
father(X, Y)	:- male(X), parent(X, Y).

% X is the mother of Y if X is female and is parent of Y
mother(X, Y)	:- female(X), parent(X, Y).

% X is the sister of Y if X is female, parent of X and Y is Z (same), and X and Y are distinct
sister(X, Y)	:- female(X), parent(Z, X), parent(Z, Y), X \== Y.

% X is the brother of Y if X is male, parent of X and Y is Z (same), and X and Yare distinct
brother(X, Y)	:- male(X), parent(Z, X), parent(Z, Y), X \== Y.


% X is a grandparent of Y if X is the parent of Z and Z is the parent of Y
grandparent(X, Y)	:- parent(X, Z), parent(Z, Y).

grandchild(Y, X)	:- grandparent(X, Y).

grandfather(X, Y)	:- male(X), grandparent(X, Y).

grandmother(X, Y)	:- female(X), grandparent(X, Y).

predecessor(X, Z)	:- parent(X, Z).
predecessor(X, Z)	:- parent(X, Y), predecessor(Y, Z).

