queens(N,S) :-
    add(1,N,L),
    permutation(L,S),
	safe(S).

safe([Y|Ys]) :- safe(Ys), \+ attack(Y,Ys).
safe([]).

attack(R,L) :- 
    attack(R,1,L).
	attack(R,N,[Y|_]) :- R is Y+N ; R is Y-N.
	attack(R,N,[_|Ys]) :- N1 is N+1, attack(R,N1,Ys).

add(M,N,[M|L]) :- 
    M<N, M1 is M+1, add(M1,N,L).
	add(N,N,[N]).
