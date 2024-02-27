from functools import reduce

#13.1
def sort2list(l1, l2):
    l3 = []
    i = 0
    j = 0
    while i < len(l1) and j < len(l2):
        if l1[i] < l2[j]:
            l3.append(l1[i])
            i+=1
        else:
            l3.append(l2[j])
            j+=1
    return l3 + l1[i:] + l2[j:]

#13.2
def ex2(l):
    if len(l) == 0:
        return []
    if l[0] == 0:
        return [l[0]] + ex2(l[1:])
    else:
        return ex2(l[1:]) + [l[0]]

#13.3
def ex3(l, start, end):
    if start > end:
        return end + 1
    if start != l[start]:
        return start
    mij = (start + end) // 2
    if mij == l[mij]:
        return ex3(l, mij + 1, end)
    else:
        return ex3(l, start, mij)

#13.8
def get_column(i, n, m):
    if len(m) != n*n:
        raise ValueError("Nu este matrice patratica")
    return m[i:n**2:n]

#13.6
def ex6(l, x, i):
    if l[i] == x:
        return i
    return ex6(l, x, i-1)

#13.4
def binary(l,x,start,end):
    if start > end:
        return False
    mij = (start + end) // 2
    if l[mij] == x:
        return True
    if l[mij] < x:
        return binary(l, x, mij + 1, end)
    else:
        return binary(l, x, start, mij)

def ex4(l, x):
    for idx in range(len(l)):
        if binary(l, x - l[idx], idx, len(l)-1):
            return idx, x - l[idx]
    return None

#14.3
def piglatin(filename):
    with open(filename, 'r') as file:
        s = file.read()
        props = s.split(',')
        for prop in props:
            words = prop.strip().split(' ')
            newords = list(map(lambda word: word[1:] + word[0] + 'ay', words))
            newords = reduce(lambda x, y: x + " " + y, newords)
            print(newords)
def main():
    print(sort2list([1,2,3,4],[4,5,6,7]))
    print(ex2([0,1,0,1,1,0,0,1]))
    print(ex3([0,1,2,4,5,6],0,4))
    print(get_column(1,3,'ABCDEFGHI'))
    print(ex6([1,7,8,7,5,7,2], 7,6))
    print(ex4([1,2,7,8,10], 12))
    piglatin('words.txt')

main()