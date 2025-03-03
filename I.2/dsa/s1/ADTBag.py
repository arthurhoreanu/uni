class ADTBag:

    def __init__(self):
        self.elements = []

    def add(self, elem):
        self.elements.append(elem)

    def remove(self, elem):
        if elem in self.elements:
            self.elements.remove(elem)
            return True
        else:
            raise ValueError(f"Element {elem} not found in the bag")

    def length(self):
        return len(self.elements)

    def search(self, elem):
        if elem in self.elements:
            return True
        else:
            return False

    def nrOccurence(self, elem):
        return self.elements.count(elem)