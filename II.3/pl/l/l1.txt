%A1
hungrig(lena).
mutter(lena, otto). % Lena ist Mutter von Otto
mag(lena, X) :- schenkt_schokolade(X, lena).
mag(lena, X) :- singen_koennen(X), gut_kochen(X).
mag(lena, X) :- schenkt_schokolade(X, lena); schenkt_kekse(X, lena).
mensch(X) :- sterblich(X).
sterblich(sokrates).
tochter(X, Y) :- weibliches_kind(X, Y). % X ist Tochter von Y 
hund(X) :- mag_wurst(X).
mag(pluto, X) :- gibt(mickey, pluto, X).

%A2
mann(arthur).
mann(ron).
mann(harry).
mann(hugo).
mann(james).
mann(albus).
frau(molly).
frau(hermione).
frau(ginny).
frau(rose).
frau(lily).

mutter(molly, ron).
mutter(molly, ginny).
mutter(hermione, rose).
mutter(hermione, hugo).
mutter(ginny, james).
mutter(ginny, albus).
mutter(ginny, lily).

vater(arthur, ron).
vater(arthur, ginny).
vater(ron, rose).
vater(ron, hugo).
vater(harry, james).
vater(harry, albus).
vater(harry, lily).

tochter(ginny, molly).
tochter(ginny, arthur).
tochter(rose, hermione).
tochter(rose, ron).
tochter(lily, ginny).
tochter(lily, harry).

sohn(ron, molly).
sohn(ron, arthur).
sohn(hugo, hermione).
sohn(hugo, ron).
sohn(james, ginny).
sohn(james, harry).
sohn(albus, ginny).
sohn(albus, harry).

schwester(ginny, ron).
schwester(rose, hugo).
schwester(lily, james).
schwester(lily, albus).

bruder(ron, ginny).
bruder(hugo, rose).
bruder(james, lily).
bruder(albus, lily).

eltern(E, K) :- vater(E, K); mutter(E, K).
grossvater(G, E) :-
   vater(G, X), eltern(X, E), mann(G).

%A3
vINCENT - Atom
Footmassage - Variable
variable23 - Atom
Variable2000 - Variable
big_kahuna_burger - Atom
'big_kahuna_burger' - Atom
big kahuna burger - nichts
'Jules' - Atom
_Jules - Variable
'_Jules' - Atom

%A4
loves(Vincent, mia) - komplexer Term, Funktor:loves, Stelligkeit:2
'loves(Vincent, mia)' - Atom
Butch(boxer) - nichts
boxer(Butch) - komplexer Term, Funktor:boxer, Stelligkeit:1
and(big(burger),kahuna(burger)) - komplexer Term, Funktor: and, Stelligkeit:2
and(big(X),kahuna(X)) - komplexer Term, Funktor: and, Stelligkeit: 2
_and(big(X),kahuna(X)) - nichts
(Butch kills Vincent) - nichts
kills(Butch Vincent) - nichts
kills(Butch, Vincent - nichts
      
%A5
Klauseln - entweder Fakte oder Regeln
woman(vincent) - Fakt
woman(mia) - Fakt
man(jules) - Fakt
person(X) :- man(X); woman(X) - Regel, RKopf: person(X), RKorper: man(X); woman(X)
loves(X,Y) :- father(X, Y) - Regel, Rkopf: loves(X, Y), RKorper: father(X, Y)
father(Y,Z) :- man(Y), son(Z, Y) - Regel, Rkopf: father(Y,Z), RKorper: man(Y), son(Z, Y)
father(Y,Z) :- man(Y), daughter(Z, Y) - Regel, Rkopf: father(Y,Z), Rkorper: man(Y), daughter(Z, Y)