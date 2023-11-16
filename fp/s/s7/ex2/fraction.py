class Fraction:
    def __init__(self, n, m):
        self.n = n
        self.m = m

    def extend(self, k):
        self.n += k

    def simplify(self, k):
        self.n //=k
        self.m //=k

    def gcd(self, a, b):
        while b !=0:
            rest = a % b
            a,b = b,rest
        return a

    def reduce(self):
        div = self.gcd(self.n, self.m)
        self.n //= div
        self.m //= div