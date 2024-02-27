class Account:
    def __init__(self, number, admin, sum = 0):
        self.number = number
        self.sum = sum
        self.admin = admin
    def cash_in(self, sum):
        self.sum += sum
    def cash_out(self, sum):
        self.sum -= sum