%% Aufgabe 1

% Fakten: Verbundene Punkte im Labyrinth (Einbahnstraßen)
connected(1,2).
connected(3,4).
connected(5,6).
connected(7,8).
connected(9,10).
connected(12,13).
connected(13,14).
connected(15,16).
connected(17,18).
connected(19,20).
connected(4,1).
connected(6,3).
connected(4,7).
connected(6,11).
connected(14,9).
connected(11,15).
connected(16,12).
connected(14,17).
connected(16,19).

% Regel: Pfad zwischen zwei Punkten finden
% Basisfall: Wenn zwei Punkte direkt verbunden sind, existiert ein Pfad.
path(Punkt1, Punkt2) :- 
    connected(Punkt1, Punkt2).

% Rekursiver Fall: Wenn ein Punkt mit einem Zwischenpunkt verbunden ist
% und ein Pfad von diesem Zwischenpunkt zum Zielpunkt existiert.
path(Punkt1, Punkt2) :- 
    connected(Punkt1, Zwischenpunkt),
    path(Zwischenpunkt, Punkt2).

% Können Sie von Punkt 5 zu Punkt 10 gehen? - JA
% Welche andere Punkte können Sie ankommen, wenn Sie mit Punkt 1 beginnen? - Punkt 2
% Welche Punkte können Sie ankommen, wenn Sie mit Punkt 13 beginnen? - Punkte 14, 9, 17, 10, 18

%% Aufgabe 2

% Fakten: 
byCar(auckland, hamilton).
byCar(hamilton, raglan).
byCar(valmont, saarbruecken).
byCar(valmont, metz).
byTrain(metz, frankfurt).
byTrain(saarbruecken, frankfurt).
byTrain(metz, paris).
byTrain(saarbruecken, paris).
byPlane(frankfurt, bangkok).
byPlane(frankfurt, singapore).
byPlane(paris, losAngeles).
byPlane(bangkok, auckland).
byPlane(singapore, auckland).
byPlane(losAngeles, auckland).

% Regel:
% Basisfall: Direkte Verbindung
travel(Ort1, Ort2) :- 
    byCar(Ort1, Ort2).
travel(Ort1, Ort2) :- 
    byTrain(Ort1, Ort2).
travel(Ort1, Ort2) :- 
    byPlane(Ort1, Ort2).

% Rekursiver Fall: Reise über einen Zwischenort mit beliebigen Verkehrsmitteln und Kombinationen
travel(Ort1, Ort2) :- 
    (byCar(Ort1, Zwischenort);
     byTrain(Ort1, Zwischenort);
     byPlane(Ort1, Zwischenort)),
    travel(Zwischenort, Ort2).

%% Aufgabe 3

% Fakten: direkte Vererbungsbeziehungen
et(albert, kevin).  
et(lena, albert).
et(marie, lena).

% Regel:
% Basisfall: Eine Person X ist ein direkter Vorfahr von Y, wenn es eine direkte Beziehung gibt
vorfahr(X, Y) :- et(X, Y). 

% Rekursiver Fall: Eine Person X ist ein Vorfahr von Y, wenn es eine Person Z gibt,
% die zwischen X und Y liegt, und Z ein Nachkomme von X ist,
% während Y ein Nachkomme von Z ist
vorfahr(X, Y) :- vorfahr(X, Z), vorfahr(Z, Y).

% Die obige Klausel führt zu unendlicher Rekursion, 
% da sie immer wieder rekursiv aufgerufen wird, ohne die Basisrelation et/2 zu nutzen.

% Korrektur:
vorfahr(X, Y) :- et(X, Z), vorfahr(Z, Y).

%% Aufgabe 4

% Fakten:
directlyIn(irina, natasha).
directlyIn(natasha, olga).
directlyIn(olga, katarina).

% Regel:
% Basisfall:
in(X, Y) :- directlyIn(X, Y).

% Rekursiver Fall:
in(X, Y) :- directlyIn(X, Z), in(Z, Y).

%% Aufgabe 5

% Hauptregel: Startet das Zählen von 10.
start :- zaehle_ab(10).

% Regel: zaehle_ab(N) zählt absteigend, solange N größer als 0 ist.
% Es gibt N aus und ruft sich selbst rekursiv mit N-1 auf.
zaehle_ab(N) :-
    N > 0,                     
    writeln(N),                
    N1 is N - 1,               
    zaehle_ab(N1).             


% Basisfall: Wenn N = 0 ist, wird die Rekursion beendet.
zaehle_ab(0) :- writeln('Fertig!').        

%% Aufgabe 6

% Regel:
vergleiche(X, Y) :- 
    X >= Y,                              
    writeln('X ist grosser oder gleich').  

vergleiche(X, Y) :- 
    X < Y,                               
    writeln('X ist kleiner').              