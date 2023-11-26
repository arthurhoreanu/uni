import math

def common_elements(list):
    dict = {}
    newList = []
    for ind1 in range(len(list)):
        for ind2 in range(len(list[ind1])):
            if list[ind1][ind2] in dict:
                dict[list[ind1][ind2]] += 1
            else:
                dict[list[ind1][ind2]] = 1
    print(dict)

    for index, val in dict.items():
        for elem in list:
            value = elem.count(index) - 1

        if value > 0:
            val -= value

        if val == len(list):
            newList.append(index)

    return newList

def read_matrix(filename):
    file = open(filename, 'r')
    matrix = [[int(el) for el in line.strip().split(',')] for line in file]
    file.close()

    return matrix

def is_sparse(matrix):
    ct1 = sum([sum(line) for line in matrix])
    ct0 = len(matrix) ** 2 - ct1

    return ct0 > 0.7 * len(matrix) ** 2

def main():
    m = read_matrix('input.txt')
    print(is_sparse(m))

# def test():
#     assert do_stuff([2, 4, 7, 9]) == [True, True, True, True]
#     assert do_stuff([2, 4, 7, 9]) == [True, True, False, False]

main()