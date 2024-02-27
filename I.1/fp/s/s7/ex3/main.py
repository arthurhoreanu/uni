from ex3.car import Car
from ex3.statistics import Statistics
from ex3.tests import test_average

def main():
    cars = [Car('Mercedes', 'S-Class', 2023, 'black'),
            Car('Mercedes', 'S-Class', 2017, 'black'),
            Car('Skoda', 'Octavia', 2014, 'grey')]
    stats = Statistics(cars)
    print(stats.color_count('black'), ' ', stats.average_year('S-Class'))

main()
test_average()