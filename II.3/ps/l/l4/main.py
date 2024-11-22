import numpy
import matplotlib.pyplot as plt
from scipy.stats import binom

def A1():
    N = 1000
    x = [0,1,3,5]
    P = [0.4,0.1,0.3,0.2]
    rng = numpy.random.default_rng()
    r = rng.choice(x, size=N, replace=True, p=P)
    y,count=numpy.unique(r,return_counts=True)
    plt.bar(y, count/N, alpha=0.6, color='g', edgecolor='black',
             label='Simulated', width=0.8)
    plt.bar(x, P, width=0.5, color='blue', alpha=0.5, label='Theoretical')
    plt.xticks(x)
    plt.show()

#A1()

def A2():
    N = 1000
    x = [0, 1, 2, 3, 4]
    P = [0.25, 0.35, 0.25, 0.1, 0.05]
    rng = numpy.random.default_rng()
    typos = rng.choice(x, size=N, replace=True, p=P)
    prob_at_most_1 = numpy.mean(typos <= 1)
    expected_value = numpy.mean(typos)
    print(prob_at_most_1)
    print(expected_value)

#A2()

def A3():
    N=10
    n=8
    p=0.5
    X=binom.rvs(n,p,size=N)
    print(N,"zufallige Werte fur X:",X)
    k=5
    w=binom.pmf(k,n,p)
    print("binom.pmf(",k,",",n,",",p,") berechnet die Wh P(X=",k,f"={w:.5f}")

#A3()

def A4():
    genau=binom.pmf(4, 7, 0.4)
    hochstens=binom.cdf(3, 7, 0.4)
    mindestens=1-binom.cdf(4, 7, 0.4)+binom.cdf(4, 7, 0.4)
    print(genau)
    print(hochstens)
    print(mindestens)

A4()