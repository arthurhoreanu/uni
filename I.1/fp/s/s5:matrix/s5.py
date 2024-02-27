def sum_diag(matrix):
    result = []

    for i in range(len(matrix)):
        sum_line = 0

        for j in range(len(matrix[i])):
            if i != j:
                sum_line += matrix[i][j]

        result.append(sum_line == matrix[i][i])

    return result


def longest_word(filename):
    f = open(filename, 'r')
    result = []

    for line in f:
        words = line.split(' ')
        max_length = 0
        max_word = ''

        for word in words:
            if len(word.strip()) > max_length:
                max_length, max_word = len(word.strip()), word.strip()

        result.append((max_length, max_word))

    f.close()
    return result


def count_pali(filename):
    f = open(filename, 'r')
    result = {}

    for line in f:
        words = line.split(' ')

        for word in words:
            word = word.strip()

            if word == word[::-1]:
                if word in result:
                    result[word] += 1
                else:
                    result[word] = 1

    f.close()
    return result


def test_count_pali():
    assert count_pali('test2.input') == {'anna':2, 'abba':2}


def test_longest_word():
    assert longest_word('test.input') == [(4, 'mere'), (5, 'totul')]


def test_sum_diag():
    assert sum_diag([
        [4, 3, 1],
        [1, 2, 1],
        [0, 5, 1]
    ]) == [True, True, False]


def main():
    pass


test_count_pali()
test_longest_word()
test_sum_diag()
main()