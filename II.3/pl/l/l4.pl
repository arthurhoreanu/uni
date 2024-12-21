% Aufgabe 3:
% Schreiben Sie ein Prolog-Programm, das der Durchschnitt des zwei Mengen zurückgibt.

% durchschnitt(A, B, Ergebnis)
% Diese Funktion berechnet der Durchschnitt des zwei Listen L1 und L2.
% Das Ergebnis ist eine Liste der gemeinsamen Elemente ohne Duplikate.

% Hauptfunktion: Der Benutzer ruft diese Version der Funktion auf.
durchschnitt(A, B, Ergebnis) :-
    durchschnitt(A, B, [], Ergebnis). % Ruft das Hilfsprädikat mit einer leeren Akkumulatorliste auf.

% Fall 1: Wenn die erste Liste leer ist, ist das Ergebnis gleich dem Akkumulator.
% Dies markiert das Ende der Rekursion.
durchschnitt([], _, Akk, Akk). % Kein weiteres Element wird hinzugefügt.

% Fall 2: Das erste Element der ersten Liste (Kopf) ist in der zweiten Liste (B) und nicht im Akkumulator.
% Wir fügen dieses Element zum Akkumulator hinzu und fahren mit dem Rest der Liste fort.
durchschnitt([Kopf|Rest], B, Akk, Ergebnis) :-
    member(Kopf, B),                             % Überprüfen, ob Kopf ein Element von B ist.
    \+ member(Kopf, Akk),                        % Sicherstellen, dass Kopf noch nicht im Akkumulator ist.
    durchschnitt(Rest, B, [Kopf|Akk], Ergebnis). % Kopf hinzufügen und mit der Rekursion fortfahren.

% Fall 3A: Das erste Element der ersten Liste (Kopf) ist in der zweiten Liste (B),
% aber es ist bereits im Akkumulator. Überspringen und fortfahren.
durchschnitt([Kopf|Rest], B, Akk, Ergebnis) :-
    member(Kopf, B),                      % Überprüfen, ob Kopf ein Element von B ist.
    member(Kopf, Akk),                    % Überprüfen, ob Kopf bereits im Akkumulator ist.
    durchschnitt(Rest, B, Akk, Ergebnis). % Kopf nicht hinzufügen, Rekursion mit Rest fortsetzen.

% Fall 3B: Das erste Element der ersten Liste (Kopf) ist NICHT in der zweiten Liste (B).
% Ignorieren und mit dem Rest der Liste fortfahren.
durchschnitt([Kopf|Rest], B, Akk, Ergebnis) :-
    \+ member(Kopf, B),                   % Überprüfen, ob Kopf kein Element von B ist.
    durchschnitt(Rest, B, Akk, Ergebnis). % Kopf ignorieren, Rekursion mit Rest fortsetzen.
