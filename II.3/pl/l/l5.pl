% 8) a) Der Prädikat berechnet den Nachfolger einer Liste von Ziffern
nachfolger_liste(Liste, Ergebnis) :-
    reverse(Liste, UmgekehrteListe), % Zuerst kehren wir die Liste um (für die Verarbeitung von rechts nach links)
    addiere_ziffern(UmgekehrteListe, 1, ErgebnisUmgekehrt), % Wir addieren 1 (der Nachfolger) von rechts nach links
    reverse(ErgebnisUmgekehrt, Ergebnis). % Zum Schluss kehren wir das Ergebnis um

% Rekursive Verarbeitung der Ziffern, mit Übertrag
addiere_ziffern([], 0, []). % Basisfall: Keine Ziffern und kein Übertrag mehr
addiere_ziffern([], 1, [1]). % Basisfall: Es bleibt ein Übertrag von 1 übrig
addiere_ziffern([Ziffer | Rest], Übertrag, [NeueZiffer | NeuesRestErgebnis]) :-
    Summe is Ziffer + Übertrag, % Die aktuelle Ziffer plus Übertrag berechnen
    NeueZiffer is Summe mod 10, % Neue Ziffer ist der Rest der Division durch 10
    NeuerÜbertrag is Summe // 10, % Neuer Übertrag ist die Ganzzahldivision durch 10
    addiere_ziffern(Rest, NeuerÜbertrag, NeuesRestErgebnis). % Rekursiver Aufruf mit dem Rest der Liste

% b) Der Prädikat verarbeitet eine heterogene Liste und berechnet den Nachfolger für jedes Element
nachfolger_heterogen([], []). % Basisfall: Eine leere Liste bleibt leer
nachfolger_heterogen([Kopf | Rest], [NeuerKopf | NeuesRestErgebnis]) :-
    berechne_nachfolger(Kopf, NeuerKopf), % Den Nachfolger für das aktuelle Element berechnen
    nachfolger_heterogen(Rest, NeuesRestErgebnis). % Rekursiver Aufruf für den Rest der Liste

% Fall 1: Das Element ist eine Liste von Ziffern
berechne_nachfolger(ListeVonZiffern, Ergebnis) :-
    is_list(ListeVonZiffern), % Überprüfen, ob das Element eine Liste ist
    nachfolger_liste(ListeVonZiffern, Ergebnis). % Den Nachfolger der Liste berechnen

% Fall 2: Das Element ist eine ganze Zahl (unverändert lassen)
berechne_nachfolger(Zahl, Zahl) :-
    integer(Zahl). % Überprüfen, ob es sich um eine ganze Zahl handelt