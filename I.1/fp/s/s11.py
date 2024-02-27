import math

def sum_rec(l, i):
    if i < len(l):
        return l[i] + sum_rec(l, i + 1)

    else:
        return 0

#print(sum_rec([1, 2, 3, 4], 0))

def sum_rec2(l):
    if len(l) <= 1:
        return l[0]

    return l[0] + sum_rec2(l[1:])

#print(sum_rec2([1, 2, 3, 4]))
def sum_rec3(l):
    if len(l) == 0:
        return 0
    return l[-1] + sum_rec3(l[0:len(l) - 1])

#print(sum_rec3([1, 2, 3, 4]))

#ex1

def sum_even(n):
    if n == 0:
        return 0
    if n % 2 == 0:
        return n % 10 + sum_even(n // 10)
    else:
        return sum_even(n // 10)

#print(sum_even(1234))

#ex2

def func(string):
    if len(string) == 0:
        return None
    if string[-1].isupper():
        return string[-1]
    return func(string[0 : len(string) - 1])

#print(func('abcdefg'))

#ex5

def mx(l):
    if len(l) == 0:
        return None
    if len(l) == 1:
        return l[0]
    return max(l[0], mx(l[1:]))

#print(mx([2, 3, 4, 5]))

#ex6

def pal(string):
    if len(string) <= 1:
        return True
    if string[0] != string[-1]:
        return False
    return pal(string[1 : len(string) - 1])

#print(pal('123322'))

import math
n = 7
nc = int(math.log10(n)) + 1
#print(n // 10 ** (nc - 1))

def pali(nr):
    if nr < 10:
        return True
    if nr // 10 ** (int(math.log10(nr))) != nr % 10:
        return False
    return pali(nr % 10 ** int(math.log10(nr)) // 10)

#print(pali(1233217))

def sl(l):
    s = 0
    for el in l:
        if type(el) == list:
            s = s + sl(el)
        else:
            s += el
    return s
#print(sl([1, [1, [1, 2, 3], 5], 3]))

#ex3

def voc(string):
    if len(string) == 0:
        return 0
    if string[0] in 'aeiouAEIOU':
        return 1 + voc(string[1:])
    else:
        return voc(string[1:])

#print(voc('abcefgi'))

#ex6
def check(l, elem):
    for el in l:
        if type(el) == list:
            if check(el, elem):
                return True
        else:
            if el == elem:
                return True
    return False

print(check([1, 2, [1, 4, 7], 4], 2))