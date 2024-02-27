from ex2.fraction import Fraction

def main():
    frac = Fraction(14,22)
    frac.reduce()
    print(frac.n, frac.m)

main()