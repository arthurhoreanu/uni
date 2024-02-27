class Adress:
    def __init__(self, street, number):
        self.street = street
        self.number = number

    def __str__(self):
        return f"Street= {self.street}, number = {self.number}"