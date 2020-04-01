islist([]).
islist([A|B]) :- islist(B).

weak_list([]).
weak_list([_|_]).

