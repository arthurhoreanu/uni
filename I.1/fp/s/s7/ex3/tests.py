from ex3.statistics import Statistics
from ex3.car import Car

def test_average():
    cars = [Car('Mercedes', 'S-Class', 2023, 'black'),
            Car('Mercedes', 'S-Class', 2017, 'black'),
            Car('Skoda', 'Octavia', 2014, 'grey')]
    stats = Statistics(cars)
    assert stats.average_year('S-Class') == 2020

test_average()