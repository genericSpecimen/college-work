start	:-	write('Enter first  number: '), read(N1),
		write('Enter second number: '), read(N2),
		multi(N1, N2, R), write('\n'),
		write(N1), write(' * '), write(N2), write(' = '), write(R).

multi(N1, N2, R)	:-	R is N1 * N2.

