from ADTIterator import ADTIterator

class ADTBag:

    def __init__(self, b=None):
        if b is None:
            self.b = []
        else:
            self.b = b

    def add(self, e):
        if e not in self.b:
            self.b.append(e)

    def remove(self, e):
        if e in self.b:
            self.b.remove(e)

    def search(self, e):
        if e in self.b:
            return True
        else:
            return False

    def size(self):
        return len(self.b)

    def nrOccurrences(self, e):
        count = 0
        for item in self.b:
            if item == e:
                count += 1
        return count

    def iterator(self):
        self.i = i
        return self.i