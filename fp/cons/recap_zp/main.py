import math
# l = []
# l = l.__add__([1])
# print(l)
def read_list(filename):
    f = open (filename ,'r')
    l = [int(num) for line in f for num in line.strip().split(',')]
    f.close()
    return l

def build_and_check(num):
    nc = int(math.log10(num)) + 1
    k = nc % 3 #posibile poz mult de trei
    num //= 10 ** k
    nr_nou = 0
    ogl = 0
    p = 1
    while num != 0:
        uc = num % 10
        num //= 1000
        nr_nou = nr_nou * 10 + uc
        ogl = ogl + p * uc
        p *= 10
    return nr_nou == ogl



def transfer(l, filename):
    with open(filename , 'w') as file:
        for num in l:
            if build_and_check(num):
                file.write(str(num) + '\n')

def sub_matrix(m1, m2):
    m3 =[]
    for i in range(len(m1)):
        line = []
        for j in range(len(m1)):
            line.append(m1[i][j] - m2[i][j])
        m3.append(line)
    return m3

def sort_line(line, matrix):
    return sorted(matrix[line], key=lambda x:list(x)[1])

def main():

    # l = read_list('input.txt')
    # print(build(123))
    # print(build(23))
    # print(build(1000))
    # print(build_and_check(123456789))
    # print(build_and_check(123456783))
    # transfer(l, 'output.txt')

    m1 = [
          [{1,2}, {1}, {2,5}],
          [{1,2,3}, {3,4,5}, {5,6,7}],
          [{0,1}, {7,9}, {3,4}]
        ]

    m2 = [
          [{1,4}, {1}, {2,8}],
          [{1,6,3}, {3,4,5}, {5,6,3}],
          [{0,1}, {7,2}, {9,4}]
        ]
   # print(sub_matrix(m1,m2))
    print(sort_line(1, m2))
main()