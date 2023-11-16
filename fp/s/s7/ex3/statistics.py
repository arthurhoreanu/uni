class Statistics:
    def __init__(self, carList):
        self.carList = carList
    def color_count(self, color):
        counter = 0
        for car in self.carList:
            if car.color == color:
                counter +=1
        return counter
    def average_year(self, model):
        sum = 0
        count = 0
        for car in self.carList:
            if car.model == model:
                sum += car.year
                count += 1
        return sum // count