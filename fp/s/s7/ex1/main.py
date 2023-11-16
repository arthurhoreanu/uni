from dice import Dice


def main():
    dice = Dice(6)

    while True:
        result = dice.throw()
        print(result)
        if result == 6:
            break


main()