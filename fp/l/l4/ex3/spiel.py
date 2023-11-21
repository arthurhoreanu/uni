import random
import illustrationen.illustrationen

def game_choice():
    print('1. Schere\n2. Stein\n3. Papier \n')
    choice = int(input('Wahl eingeben: '))
    options = ['schere', 'stein', 'papier']

    user_choice = options[choice - 1]
    computer_choice = random.choice(options)

    return user_choice, computer_choice

def main():
    print("Lass uns Schere-Stein-Papier spielen!")
    user_score = 0
    cpu_score = 0

    for runde in range(1, 4):
        print(f'\nRunde {runde} \n')
        user_choice, computer_choice = game_choice()
        print(f'\nDu hast gewählt: ')
        print(getattr(illustrationen.illustrationen, user_choice)())
        print(f'Der Computer hat gewählt: ')
        print(getattr(illustrationen.illustrationen, computer_choice)())

        if user_choice == computer_choice:
            print("Unentschieden!")
        elif (user_choice == 'schere' and computer_choice == 'stein') or \
                (user_choice == 'stein' and computer_choice == 'papier') or \
                (user_choice == 'papier' and computer_choice == 'schere'):
            cpu_score += 1
        else:
            user_score += 1

        print(f'Du: {user_score}, Computer: {cpu_score}')

    if user_score > cpu_score:
        print(illustrationen.illustrationen.winner())
    elif cpu_score > user_score:
        print(illustrationen.illustrationen.loser())
    else:
        print(illustrationen.illustrationen.tie())

main()