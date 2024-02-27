def guess (word, char, current_state):
    found_indexes = []

    for idx in range(len(word)):
        if char == word[idx] and idx not in current_state[2]:
            found_indexes.append(idx)

    tries = 1 if len(found_indexes) == 0 else 0

    return (current_state[0] + tries,
            current_state[1] + len(found_indexes),
            current_state[2] + found_indexes)


def win (word, current_state):
    return current_state[1] == len(word)


def loss (word, current_state, max_tries):
    return current_state[0] > max_tries