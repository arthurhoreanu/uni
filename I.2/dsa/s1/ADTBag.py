class ADTBag:

    def __init__(self):
        self.list = []

    def add(self, elem):
        self.list.append(elem)

    def remove(self, elem):
        if elem in self.list:
            self.list.remove(elem)
            return True
        else:
            return False

    def length(self):
        return len(self.list)

    def search(self, elem):
        if elem in self.list:
            return True
        else:
            return False

    def nrOccurence(self, elem):
        nr = 0
        for i in range(len(self.list)):
            if self.list[i] == elem:
                nr += 1
        return nr
