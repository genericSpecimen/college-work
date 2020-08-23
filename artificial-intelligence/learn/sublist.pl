% S is a suffix of L if L can be formed by appending some list by S
suffix(S, L) :- append(_, S, L), !.
% P is a prefix of L if L can be formed by appending P by some list S
prefix(P, L) :- append(P, _, L), !.

sublist(SubL, L) :- suffix(S, L), prefix(SubL, S).

