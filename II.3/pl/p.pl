% Dijkstra (kurzesten Pfad von einen Starknote zu alle andere Knoten,
% wo alle Knoten einen nichtnegativen Kost haben).

% Fakte:
edge(1,2,1).
edge(2,1,1).
edge(2,3,4).
edge(3,2,4).
edge(3,4,5).
edge(4,3,5).
edge(1,5,10).
edge(5,1,10).
edge(5,4,11).
edge(4,5,11).

% Regel:
% Wir checken, ob die Knoten Nachbarn sind.
connected(X, Y, Cost) :- edge(X, Y, Cost).
connected(X, Y, Cost) :- edge(Y, X, Cost).

% „Main”-Regel:
dijkstra(Start, Paths) :-
    dijkstra_helper([[Start, 0]], [], Paths).

% „Helper”-Regel:
dijkstra_helper([], Visited, Visited).
dijkstra_helper([[Current, Dist] | RestQueue], Visited, Paths) :-
    explore_neighbors(Current, Dist, Visited, Neighbors),
    append(RestQueue, Neighbors, UpdatedQueue),
    sort_queue(UpdatedQueue, SortedQueue),
    dijkstra_helper(SortedQueue, [[Current, Dist] | Visited], Paths).
     
explore_neighbors(Current, Dist, Visited, Neighbors) :-
find_neighbors(Current, Dist, Visited, [], Neighbors).

find_neighbors(Current, Dist, Visited, Acc, Neighbors) :-
    connected(Current, Next, Cost),
    not_member([Next, _], Visited),
    NewDist is Dist + Cost,
    not_member([Next, NewDist], Acc),
    find_neighbors(Current, Dist, Visited, [[Next, NewDist] | Acc], Neighbors).
find_neighbors(_, _, _, Neighbors, Neighbors).

% Wir checken, ob wir einen Nachbarn nicht schon geschrieben haben
not_member(_, []).
not_member(Element, [Head | Tail]) :-
    Element \= Head,
    not_member(Element, Tail).

sort_queue([], []).
sort_queue([X | Rest], Sorted) :-
    sort_insert(X, Rest, TempSorted),
    sort_queue(TempSorted, Sorted).

sort_insert(X, [], [X]).
sort_insert([Node1, Dist1], [[Node2, Dist2] | Rest], [[Node1, Dist1], [Node2, Dist2] | Rest]) :-
    Dist1 =< Dist2.
sort_insert([Node1, Dist1], [[Node2, Dist2] | Rest], [[Node2, Dist2] | Sorted]) :-
    Dist1 > Dist2,
    sort_insert([Node1, Dist1], Rest, Sorted).
