#Aufgabe 1

def prim(nr):
    for i in range(2,nr//2):
        if nr % i == 0:
            return False
    return True

def gen_matrix(wert, n):
    matrix =[[wert for _ in range(n)] for _ in range(n)]
    s = 0
    l_prime =[i for i in range(n * 100) if prim(i)]
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            if j > i:
                matrix[i][j] = s
                s += 2
            if i > j:
                matrix[i][j] = l_prime[0]
                l_prime.pop(0)
    return matrix


def do_stuff(a, x, n):
    i = 0
    while not (i >= n or a[i] == x):
        i += 1
    return i if i < n else -1

def test():
    assert do_stuff([1, 2, 3, 4], 1, 4) == 0
    assert do_stuff([1, 2, 3, 4], 7, 4) == -1

test()
#Aufgabe 3
def file_lenght(filename):
    f = open(filename, 'r')
    count = sum([1 for _ in f])
    f.close()
    return count
def test(filename):
    s = 0
    a = []
    with open(filename, 'r') as file:
        for line in file:
            numbers =[int(nr) for nr in line.strip().split(',')]
            s = sum(numbers)
            if not prim(s):
                return False
            list_impar = [nr for nr in numbers if nr % 2 != 0]
            list_par = [nr for nr in numbers if nr % 2 == 0]
            if sorted(list_impar, reverse=True) != list_impar:
                return False
            if sorted(list_par) != list_par:
                return False
            a.append(numbers)
        if len(a[-1]) != 1:
            return False
    return True
def main():
    m = gen_matrix(7, 5)
    for line in m:
        print(line)

main()