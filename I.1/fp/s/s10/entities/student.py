class Student:
    def __init__(self, id, name, address):
        self.id = id
        self.name = name
        self.address = address

    def __lt__(self, other):
        return self.name < other.name

    def __str__(self):
        return f"Id: {self.id}, name: {self.name}, adress: {self.address}"