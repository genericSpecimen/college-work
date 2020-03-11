start	:-	write('Enter first  number: '), read(X),
		write('Enter second number: '), read(Y),
		max(X, Y, M),
		write('max('), write(X), write(', '), write(Y), write(') = '), write(M).

max(X, Y, M)	:-	X >= Y, !, M is X; M is Y.

