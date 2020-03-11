start	:-	write('Enter first  number: '), read(X),
		write('Enter second number: '), read(Y),
		sum(X, Y, SUM),
		write(X), write(' + '), write(Y), write(' = '), write(SUM).

sum(X, Y, SUM)		:-	SUM is X + Y.
