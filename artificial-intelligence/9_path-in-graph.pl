% these edges represent the directed arcs between nodes
edge(p, q).
edge(q, r).
edge(r, s).
edge(s, t).
edge(t, p).
edge(r, p).

path(X, Y) :- path(X, Y, T).

% boundary condition: a path from X to X trivially exists.
path(X, X, T) :- !.

/*
 * To avoid getting stuck in a loop, we use a list T to keep
 * a trail of the nodes we've visited. If we've already visited
 * a node, then we don't visit it again. Thus, we onlt visit a node
 * when it is not_visited. not_visited simply checks for a non-membership test
 * in the list T.
 *
 * A path from X to Y exists if there's some unvisited Z such that
 * there's an edge from X to Z and there's a path from Z to Y. If
 * there's such a Z, then we add it to the head of the list T to
 * indicate that the node has been visited.
*/
path(X, Y, T) :-
	edge(X, Z), not_visited(Z, T), path(Z, Y, [Z|T]).

% since the list of visited nodes is empty, X hasn't been visited yet
not_visited(X, []) :- !.

/*
 * Otherwise, we check if X is at the head of the list T. If it is, then
 * we've already visited X, and thus not_visited fails returns false.
 * If X is not at the head of the list, then we continue searching for X
 * in the tail of the list. If X is not found, then not_visited succeeds and
 * returns true.
 */
not_visited(X, [H|T]) :- \+ X=H, not_visited(X, T).

