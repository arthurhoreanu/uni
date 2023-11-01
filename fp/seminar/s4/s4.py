from math import gcd

def simplify(a):
    d = gcd(a[0], a[1])
    return a[0] // d, a[1] // d

def add(a, b):
    numerator = a[0] * b[1] + a[1] * b[0]
    denominator = a[1] * b[1]
    return simplify((numerator, denominator))

def sub(a, b):
    numerator = a[0] * b[1] - a[1] * b[0]
    denominator = a[1] * b[1]
    return simplify((numerator, denominator))

def add_frac(fracs, frac):
    print(frac)
    fracs.append(frac)

def sum_frac(fracs):
    total = (0, 1)
    for frac in fracs:
        total = add(total, frac)
    return total

def diff_frac(fracs):
    total = (0, 1)
    for frac in fracs:
        total = sub(total, frac)
    return total

def tests():
    assert add((1, 2), (1, 2)) == (1, 1)
    assert sum_frac([(1, 2), (1, 2)]) == (1, 1)
    assert simplify((4, 4)) == (1, 1)

def menu():
    return """
        1 - add frac
        2 - sum fracs
        3 - diff fracs
        0 - exit
    """

def main():
    fracs = []
    while True:
        print(menu())
        opt = int(input('opt= '))
        if opt == 1:
            n = int(input('n= '))
            m = int(input('m= '))
            add_frac(fracs, (n, m))
        if opt == 2:
            s = sum_frac(fracs)
            print(s)
        if opt == 3:
            d = diff_frac(fracs)
            print(d)
        if opt == 0:
            break

tests()
main()