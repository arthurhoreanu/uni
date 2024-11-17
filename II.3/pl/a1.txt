%% Dieses Programm definiert Prädikate zur Berechnung von Teilern und zur Überprüfung, ob eine Zahl perfekt ist.
%% Ein Teiler von X ist eine Zahl Y, die X ohne Rest teilt. 
%% Eine Zahl X ist perfekt, wenn die Summe ihrer echten Teiler (außer X selbst) gleich X ist.

% Definiert ein Prädikat, das die Teiler einer Zahl erzeugt.
% divisor(X, Y) - Y ist ein Teiler von X, wenn Y X ohne Rest teilt
divisor(X, Y) :- 
    Y < X,                % Y muss kleiner als X sein
    X mod Y =:= 0.        % Y ist ein Teiler, wenn die Division von X durch Y keinen Rest hat

% Berechnet die Summe der echten Teiler einer Zahl
% teilersumme(X, S) - S ist die Summe der echten Teiler von X
teilersumme(X, S) :- 
    teilersumme(X, X - 1, 0, S).  % Beginnt mit X-1 als höchstem echten Teiler

teilersumme(_, 0, S, S).                   % Wenn wir bei 0 ankommen, ist die Summe vollständig
teilersumme(X, Aktuell, Akk, S) :-
    Aktuell > 0,
    (divisor(X, Aktuell) -> NeuerAkk is Akk + Aktuell ; NeuerAkk is Akk),
    NeuerAktuell is Aktuell - 1,
    teilersumme(X, NeuerAktuell, NeuerAkk, S).

% Überprüft, ob eine Zahl perfekt ist
% perfekt(X) - X ist perfekt, wenn die Summe seiner echten Teiler gleich X ist
perfekt(X) :- 
    teilersumme(X, S), 
    S =:= X.