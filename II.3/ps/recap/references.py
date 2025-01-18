from itertools import permutations, combinations, combinations_with_replacement
#from more_itertools import distinct_permutations
from math import factorial, perm, comb, log, exp, dist, sqrt
from random import choice, choices, sample, randint,randrange, random

import matplotlib
from matplotlib.pyplot import hist, bar, plot, xticks, yticks, axis, legend, grid, show, title, xlabel, ylabel, figure
matplotlib.use("TkAgg")
#from numpy import mean, var, std, randint, linspace, log, exp, unique, random, random.default_rng()
import numpy as np
from scipy.stats import randint, bernoulli, binom, hypergeom, geom, uniform, norm, expon
# Fur die obigen Klassen aus scipy.stats, werden die Methoden: rvs, pdf, pmf, cdf benutzt.
# Man sei aufmerksam bei der Wahl der Parameter von jeder Verteilung, insbesondere fur loc und scale.

#-------PERMUTATIONEN  |  VARIATIONEN  |  KOMBINATIONEN--------------
perm(4,4)                                                # alle Permutationen einer Menge von 4 Elementen
perm(4,2)                                                # alle Variationen einer Menge von 4 Elementen
permutations("sicher")                                   # alle Permutationen (eines Wortes)
sample("sicher",6)                          # eine Permutation
permutations("sicher",2)                       # alle Variationen je 2 Buchstaben
combinations("sicher",2)                       # alle Kombinationen je 2 Buchstaben
#list(distinct_permutations("AABB"))                     # Permutationen mit Wiederholung
list(combinations_with_replacement("ABC",2))   #Kombinationen mit Wiederholung


#-----------NUMPY------------
np.random.randint(1,20,size=100)                                  # 100 random int Zahlen im Intervall [1,20)
np.random.random(25)                                                        # 25 float Zahlen im Intervall [0,1)
np.random.uniform(-1,1,1000)                                      # 1000 random float Zahlen im Intervall [-1,1)
np.var([0.15,0.23,-0.25,0.09])                                              # die Varianz der Liste
z, count = np.unique([1,1,1,2,3,4,4,5], return_counts=True)             # z = [1,2,3,4,5], count = [3,1,1,2,1]

rng = np.random.default_rng()                                               # rng (random number generator machine)
r = rng.choice([0,1,3,5], size=1000, replace=True, p=[0.4,0.1,0.3,0.2])  # replace=true -> mit Zurucklegen

#----------RANDOM------------
sample(['r','b','g'],counts=[6,4,6],k=3)   # eine random Wahl von k=3 Kugeln aus einer Urne mit 6 roten, 4 blauen, 6 gelben Kugeln
randrange(1,7)                  # eine random int Zahl aus dem Intervall [1,7)

#----------BINOM-------------
binom.rvs(7, 0.4, size=10)     # 10 zufallige Werte; je hoher die Wahrscheinlichkeit, desto naher sind die Zahlen an 7
binom.cdf(3, 7, 0.4)           # Wahrscheinlichkeit, dass eine Zahl aus binom.rvs hoechstens 3 ist; fur "wenigstens" macht man dann 1 - binom.cdf(...)
binom.pmf(3, 7, 0.4)           # Wahrscheinlichkeit, dass eine Zahl aus binom.rvs genau 3 ist

#---------UNIFORM------------
# durch Simulierungen:
X = uniform.rvs(10,10,size=1000)    # X ~ Unif[10,20]  (wie es geht: rvs(X,X+Y,Anzahl Simulationen), also rvs(10,10+10,1000) )
np.mean((X >= 14) & (X <= 18))
# theoretische WS:
uniform.cdf(18,10,20) - uniform.cdf(14,10,20)


#------------ZEICHNEN EINER FIGUR-------------
fig = figure()
axis("square")
axis((0,1,0,1))
X = np.random.random(25)
Y = np.random.random(25)
plot(X,Y,"bo")   #"bo" oder "g*"
fig.suptitle("Beispiel 1 ",fontweight="bold")
title("Wie man das zeichnet")
xlabel("Werte fur X")
ylabel("Werte fur Y")
plot(X, Y, "bo", label="Data Points")
legend(loc='upper left')

P = np.linspace(0, 1, 100)  #Schwarze Linie machen
plot(P, P, "k-")
show()

bar([1,2,3,4,5],[0.1,0.4,0.2,0.3,0.5],width=0.9,color="red",edgecolor="black",label="Tabelle Simulationen")
bar([1,2,3,4,5],1/6,width=0.7,color="blue",edgecolor="black",label="Tabelle Theoretisch")
legend(loc="lower left")
xticks(range(0,7))
grid()
show()