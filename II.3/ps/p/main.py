# Biblioteci standard pentru generare de valori aleatoare și calcule matematice

from random import random, randint, choices, sample, shuffle, uniform
from math import factorial, sqrt, exp, log, comb, perm

import matplotlib

# NumPy - pentru calcule numerice rapide și funcții de probabilitate
import numpy as np
from numpy.random import choice, randint as np_randint, normal, uniform as np_uniform, exponential

# SciPy - pentru distribuții avansate și funcții de densitate/probabilitate
from scipy.stats import bernoulli, binom, poisson, geom, hypergeom, uniform as sp_uniform, expon, norm
# SciPy include metode precum:
#   - rvs: generare de valori aleatoare
#   - pmf/pdf: funcție de masă/densitate
#   - cdf: funcție de distribuție cumulativă
#   - ppf: inversa funcției de distribuție cumulativă

# Matplotlib - pentru grafice, histograme și vizualizări
matplotlib.use("TkAgg")
import matplotlib.pyplot as plt
from matplotlib.pyplot import hist, bar, plot, xlabel, ylabel, title, legend, grid, show

# More-Itertools - pentru manipulări avansate ale permutărilor și combinărilor (opțional)
from itertools import permutations, combinations, combinations_with_replacement

# Time - pentru măsurarea performanței simulărilor (opțional)
import time

# ----------------------------------------------------------------------------------------------------------------------

benutzer = 2*[0] + 7*[1]
# 0/1 = geladen

nicht_funktioniert = 0
genau_einen_ausgeladenen = 0

erwartungswert = 0
S = []

for _ in range(50):
    Akku1 = sample(benutzer, 1)
    Akku2 = sample(benutzer, 1)
    Akku3 = sample(benutzer, 1)

    if ((Akku1 == Akku2 == Akku3 == [0]) or
            (Akku1 == [0] and Akku2 == Akku3 == [1]) or
            (Akku1 == Akku3 == [1] and Akku2 == [0]) or
            (Akku1 == Akku2 == [0] and Akku3 == [1]) or
            (Akku1 == Akku2 == [0] and Akku3 == [1]) or
            (Akku1 == Akku3 == [0] and Akku2 == [1]) or
            (Akku2 == Akku3 == [0] and Akku1 == [1])):
        nicht_funktioniert += 1

    if (Akku1==[0] and Akku2==Akku3==[1]) or (Akku2==[0] and Akku1==Akku3==[1]) or (Akku3==[1] and Akku1==Akku3==[0]):
        genau_einen_ausgeladenen += 1

    S.append(Akku1[0]+Akku2[0]+Akku3[0])
    erwartungswert += Akku1[0]+Akku2[0]+Akku3[0]

print("Die Wahrscheinlichkeit, dass die Taschenlampe nicht functioniert: ", nicht_funktioniert / 6000)
# print("Die theoretische Wahrscheinlichkeit: ", (2/9)**3)
print("Die Wahrscheinlichkeit, dass der Benutzer genau einen ausgeladenen Akku gewählt hat: ", genau_einen_ausgeladenen / 6000)

print("Erwartungswert: ", erwartungswert / 6000)

z, count = np.unique(S, return_counts=True)
bar(z, count / 6000, width=0.9, color="red", edgecolor="black", label="Relative Häufigkeiten")
title("Relative Häufigkeiten der Werte von S")
legend(loc="lower left")
show()

# Theoretische Wahrsceinlichkeit
# [ausgeladen, ausgeladen, aufgeladen, aufgeladen, aufgeladen, aufgeladen, aufgeladen, aufgeladen, aufgeladen]

# A: die Taschenlampe funktioniert nicht
# P(A) = P(1) + P(2) + P(3)
#      = 2/9 + 2/9 + 2/9
#      = (2/9)^3