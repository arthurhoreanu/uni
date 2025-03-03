class ADTIterator:

    def __init__(self, Bag):
        self.Bag = Bag
        if Bag.length() == 0:
            self.i = -1
        else:
            self.i = 0

    def valid(self):
        if 0 <= self.i < self.Bag.length():
            return True
        else:
            return False

    def next(self):
        if self.valid():
            self.i += 1
        else:
            raise StopIteration("Iterator has reached the end")

    def first(self):
        if self.Bag.length() == 0:
            raise IndexError("Bag is empty, no first element")
        else:
            self.i = 0

    def getCurrent(self):
        if self.valid():
            return self.Bag.elements[self.i]
        else:
            raise IndexError("Iterator out of bounds")