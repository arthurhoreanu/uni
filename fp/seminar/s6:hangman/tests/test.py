from logik.hangman import guess


def test_guess():
    assert guess('animal', 'n', (0, 2, [0, 5])) == (0, 3, [0, 5, 1])
    assert guess('animal', 'j', (0, 3, [0, 5, 1])) == (1, 3, [0, 5, 1])


def run_tests():
    test_guess()