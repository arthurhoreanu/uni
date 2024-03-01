from ADTBag import ADTBag

class ADTIterator:
    def valid(self):
        return 0 <= self.i < len(self.b)

    def first(self, i):
        self.i = 0
        return self.i

    def next(self, i):
        if self.valid(self.i + 1):
            self.i += 1
            return self.b[self.i]

    def getCurrent(self, e):
       if self.i <= len(self.b):
           raise IndexError
       else:
           e = self.b[self.i]