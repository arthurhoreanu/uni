def Primfaktoren(n):
    div = 2
    exp = 0
    while n > 1:
        while n % div == 0:
            exp += 1
            n /= div
        if exp != 0:
            print(div, "zum Exponenten", exp)
        exp = 0
        div += 1


Primfaktoren(100)