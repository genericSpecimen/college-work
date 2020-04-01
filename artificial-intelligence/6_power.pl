power(Num, 0, 1) :- !.
power(Num, Pow, Ans) :-
	Pow1 is Pow-1,
	power(Num, Pow1, Ans1),
	Ans is Num*Ans1.

