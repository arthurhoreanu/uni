from logik.hangman import guess, win, loss
from repository.state import add, current

def formatw(word, indexes):
    nw = ''

    for idx in range(len(word)):
        nw += word[idx] if idx in indexes else '_'

    return nw


def state(word, state, max_tries):
    return f'guessed: {state[1]}\nremaining tries: {max_tries - state[0]}\n{formatw(word, state[2])}'


def run(word, max_tries, states):
    while True:
        current_state = current(states)

        print(state(word, current_state, max_tries))
        ch = input('guess=')

        new_state = guess(word, ch, current_state)
        add(states, new_state)

        if win(word, new_state):
            print('great')
            return True

        if loss(word, new_state, max_tries):
            print('not so great')
            return False