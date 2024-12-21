import random

import numpy
from math import dist
from itertools import permutations
from random import random, choice, sample
from matplotlib.pyplot import bar, show, grid, legend, xticks, xlabel
from scipy.stats import binom

# 1. Man simuliere zufallig 2000 Kugeln aus dem Quader
def a1():
    X = numpy.random.uniform(-1,1,1000) # Quader - 3 Dimensionen
    Y = numpy.random.uniform(-1,1,1000)
    Z = numpy.random.uniform(-1,1,1000)
    E=0
    dAList=[]

    for i in range(1000):
        A = [X[i],Y[i],Z[i]]
        O = [0,0,0]

        dA = dist(A,O)
        E = E + dA
        dAList.append(dA)

    print("Erwartungswert ist " + str(E/1000))
    print("Varianz: " + str(numpy.var(dAList)))

#a1()

def a2():
    liste = list(permutations("mutig"))

    ct = 0
    for perm in liste:
        print(''.join(perm))
        ct+=1

    print("Anzahl Permutationen: " + str(ct))
    print("2 zufallige Permutatioen: ")
    P1 = choice(liste)
    P2 = choice(liste)
    print(''.join(P1))
    print(''.join(P2))

#a2()

def a3():
    N=10000
    U=3*["b"] + 3*["r"] + 4*["w"]
    X=[]

    for i in range(N):
        K = random.sample(U,3) # 3 Kugeln
        if len(set(K)) == 1:
            X.append(5)
        elif len(set(K)) == 3:
            X.append(2)
        else:
            X.append(-1)

    G = [-1,2,5] # Gewinn und Verlust
    P = [0,0,0]
    P[2] = (3*2*1 + 3*2*1 + 4*3*2)/(10*9*8) # Fall: alle haben die gleiche Farbe
    P[1] = 6 * (3*3*4)/(10*9*8) #Fall: alle verschieden r,b,w; w,r,b usw.
    P[0] = 1-P[1]-P[2]

    for i in range(len(P)):
        print("Theoretische Wh: ", G[i], f"{P[i]:.3f}")

    z,count = numpy.unique(X,return_counts=False)
    for i in range(len(z)):
        print("Aus Simulationen: ", z[i],f"{count[i]/N:.4f}")

    print("Aus Simulationen E(X): ", numpy.mean())
    print("Theoretishcen E(X): ", f"{G[0]*P[0] + G[1]*P[1] + G[2]*P[2]Ș:.4f}")

    bar(z, count/N, width=0.8, color="red", edgecolor="g")

#a3()

def a4():
    n=4; p=0.5; c1=0; c2=0
    N=10000

    X = binom.rvs(n,p,size=N) # X - Bino(n,p)
    Y = [(X[i]-1)**2+1 for i in range(len(X))]

    z,count = numpy.unique(Y,return_counts=True)

    for i in range(N):
        c1 = c1 + (Y[i] <= 5)
        c2 = c2 + (Y[i] >= 2)

    print("Anhand Simulationen P(Y<=5): ", c1/N)
    print("Theoretische Wh. P(Y<=5): ", 1-binom.pmf(4,4,0.5))

    print("Anhand Simulationen P(Y>=2): ", c2/N)
    print("Theoretische Wkt. P(Y>=2): ", 1-binom.pmf(1,4,0.5))

    y = [1,2,5,10]
    p2 = [binom.pmf(1,4,0.5),binom.pmf()]