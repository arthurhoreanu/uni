def add(states, state):
    """
    state = (tries, guessed, indexes)
    """
    states.append(state)


def current(states):
    return states[-1]