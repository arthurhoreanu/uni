//
// Created by demku on 5/27/2024.
//

#include "CarController.h"


CarController::CarController(CarRepository repository) : carRepository(repository) {}


void CarController::createCar(Car car) {
    carRepository.saveCar(car);
}

void CarController::updateCar(Car car) {
    carRepository.updateCar(car);
}


void CarController::deleteCar(std::string &licensePlate) {
    carRepository.deleteCar(licensePlate);
}


void CarController::deactivateCar(Car car) {
//    car.setActive(false);
    carRepository.updateCar(car);
}


std::vector<Car> CarController::listCars() {
    return carRepository.listAllCars();
}


std::vector<Car> CarController::searchCar(std::string &licensePlate) {
    return carRepository.searchCar(licensePlate);
}

