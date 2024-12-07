% Aufgabe 1:
% Schreiben Sie ein Prolog-Programm, das das letzte Element einer Liste zurückgibt.
% Das Ziel ist es, ein Prädikat zu definieren, das eine Liste als Eingabe nimmt und das letzte Element dieser Liste bestimmt.
% In Prolog verwenden wir die rekursive Struktur von Listen: [Kopf | Rest], wobei Kopf das erste Element und Rest der Rest der Liste ist.

% letztes_element(Liste, Element)
% Dieser Prädikat bestimmt das letzte Element einer Liste und liefert es als Ausgabe zurück.
% Die Lösung basiert auf zwei Fällen:
% 1. Basisfall: Eine Liste mit genau einem Element. Dieses Element ist das letzte.
% 2. Rekursiver Fall: Eine Liste mit mehr als einem Element. Hier ignorieren wir das erste Element (Kopf) 
%    und wenden das Prädikat auf den Rest der Liste an, bis der Basisfall erreicht wird.

% Basisfall: Wenn die Liste genau ein Element hat, dann ist dieses Element das letzte.
letztes_element([Element], Element).

% Rekursiver Fall: Wenn die Liste aus einem Kopf und einem Rest besteht,
% dann wird das Prädikat für den Rest der Liste aufgerufen, bis nur ein Element übrig ist.
letztes_element([_ | Rest], Element) :-
    letztes_element(Rest, Element).