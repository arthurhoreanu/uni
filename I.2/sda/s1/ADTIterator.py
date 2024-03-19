from ADTBag import ADTBag

class ADTIterator:

    def __init__(self, Bag):
        self.Bag = Bag
        if Bag.length() == 0:
            self.i = -1
        else:
            self.i = 0

    def valid(self):
        if self.i >= 0 and self.i < self.Bag.length():
            return True
        else:
            return False

    def next(self):
        self.i += 1
        if self.valid():
            pass
        else:
            self.i -= 1

    def first(self):
        if self.Bag.length() == 0:
            return False
        else:
            self.i = 0
            return True

    def getCurrent(self):
        if self.valid() == True:
            return self.Bag.list[self.i]