'''
def find(target, source):
    for i in range(len(target) - len(source) + 1):
        cnt=0
        idx=i
        for j in range(len(source)):
            if target[idx] == source[j]:
                cnt+=1
            idx+=1

        if cnt == len(source):
            return i

    return -1

def find_better(target, source):
    for i in range(len(target) - len(source) + 1):
       if target[i:i+len(source)] == source:
           return i
    return -1

def find_even_better(target, source):
    position = -1
    j = 0
    for i in range(len(target)):
        if target[i] != source[j]:
            position = -1
            j=0
        if target[i] == source[j]:
            if j==0:
                position = i
        if j >= len(source) - 1:
            break
        else:
            j+=1
    return position

def test_find_1():
    assert find('string', 'ing') == 3

def test_find_2():
    assert find_better('string', 'ing') == 3

def test_find_3():
    assert find_even_better('string', 'ing') == 3

def main():
    pass

test_find_1()
test_find_2()
test_find_3()
main()


def find_sum(numbers, sum):
    for i in range(len(numbers) - 1):
        if sum - i in numbers:
            return i, sum - i
    return None

def test_find_sum():
    assert find_sum([1, 2, 9], 3) == (1, 2)
    assert find_sum([1, 2, 9], 12) == None

def main():
    pass

test_find_sum()


def generate_multiple(number, count):
    multi = [number]
    i=2
    while i <= count:
        multi.append(number*i)
        i+=1

def test_generate_multiple():
    assert test_generate_multiple(3, 4) == [3, 6, 9, 12]
    assert test_generate_multiple(2, 2) == [2, 4]

def main():
    pass

test_generate_multiple()
'''

def big_sum(a, b):
    s = 0
    p = 1
    t = 0
    for ind in range(len(a) -1, -1, -1):
        cif1 = int(a[ind])
        cif2 = int(b[ind])
        nr = (cif1 + cif2 + t) % 10
        if cif1 + cif2 > 9:
            t = 1
        s = nr * p + s
        p*=10
    return str(s)

def test_big_sum():
    asssert big_sum('123', '123') == '246'

def main():
    pass

test_big_sum()