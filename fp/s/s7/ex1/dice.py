import random


class Dice:
    def __init__(self, sides):
        self.sides = sides

    def throw(self):
        return random.randint(1, self.sides)