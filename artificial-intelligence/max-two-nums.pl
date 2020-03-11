% max(X, Y, MAX)	:-	X >= Y, MAX is X.
% max(X, Y, MAX)	:-	X < Y, MAX is Y.

/* using cut */
max(X, Y, MAX)	:-	X >= Y, !, MAX is X;
			MAX is Y.

