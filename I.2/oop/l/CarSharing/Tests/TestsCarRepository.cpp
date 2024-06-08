#include "TestCarRepository.h"
#include <iostream>

void TestCarRepository::testAllCR() {
    CarRepository repository("test_cars.csv");

    testSaveCar(repository);
    testUpdateCar(repository);
    testDeleteCar(repository);
    testFindCarByLicensePlate(repository);
    testListAllCars(repository);
}

void TestCarRepository::testSaveCar(CarRepository &repository) {
    Car car("XYZ123", "A4", "Audi", 2020, 12000, 180.0, "Petrol", "Automatic", "Red", "new", true);
    repository.saveCar(car);

    auto cars = repository.listAllCars();
    if (cars.size() == 1 && cars[0].getLicensePlate() == "XYZ123") {
        std::cout << "testSaveCar passed.\n";
    } else {
        std::cout << "testSaveCar failed.\n";
    }
}

void TestCarRepository::testUpdateCar(CarRepository &repository) {
    Car updatedCar("XYZ123", "A6", "Audi", 2021, 10000, 200.0, "Diesel", "Automatic", "Blue", "updated", true);
    repository.updateCar(updatedCar);

    auto cars = repository.listAllCars();
    if (cars.size() == 1 && cars[0].getModel() == "A6" && cars[0].getYearOfFirstRegistration() == 2021) {
        std::cout << "testUpdateCar passed.\n";
    } else {
        std::cout << "testUpdateCar failed.\n";
    }
}

void TestCarRepository::testDeleteCar(CarRepository &repository) {
    std::string licensePlate = "XYZ123";
    repository.deleteCar(licensePlate);

    auto cars = repository.listAllCars();
    if (cars.empty()) {
        std::cout << "testDeleteCar passed.\n";
    } else {
        std::cout << "testDeleteCar failed.\n";
    }
}

void TestCarRepository::testFindCarByLicensePlate(CarRepository &repository) {
    Car car("XYZ123", "A4", "Audi", 2020, 12000, 180.0, "Petrol", "Automatic", "Red", "new", true);
    repository.saveCar(car);

    Car foundCar = repository.findByLicensePlate(car.getLicensePlate());
    if (foundCar.getLicensePlate() == "XYZ123") {
        std::cout << "testFindCarByLicensePlate passed.\n";
    } else {
        std::cout << "testFindCarByLicensePlate failed.\n";
    }
}

void TestCarRepository::testListAllCars(CarRepository &repository) {
    Car car1("ABC111", "Model S", "Tesla", 2020, 15000, 250.0, "Electric", "Automatic", "White", "new", true);
    Car car2("DEF222", "Model 3", "Tesla", 2019, 20000, 200.0, "Electric", "Automatic", "Black", "new", true);
    repository.saveCar(car1);
    repository.saveCar(car2);

    auto cars = repository.listAllCars();
    if (cars.size() == 2) {
        std::cout << "testListAllCars passed.\n";
    } else {
        std::cout << "testListAllCars failed.\n";
    }
}

