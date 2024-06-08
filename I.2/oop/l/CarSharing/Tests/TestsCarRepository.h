#ifndef TESTCARREPOSITORY_H
#define TESTCARREPOSITORY_H

#include "../Repository/CarRepository.h"

class TestCarRepository {
public:
    void testAllCR();
private:
    void testSaveCar(CarRepository &repository); // Test saving a car
    void testUpdateCar(CarRepository &repository); // Test updating a car
    void testDeleteCar(CarRepository &repository); // Test deleting a car
    void testFindCarByLicensePlate(CarRepository &repository); // Test finding a car by its license plate
    void testListAllCars(CarRepository &repository); // Test listing all cars
};

#endif // TESTCARREPOSITORY_H
