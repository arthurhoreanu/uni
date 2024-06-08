//
// Created by scoti on 25.05.2024.
//

#ifndef CARSHARINGFINAL_CARREPOSITORY_H
#define CARSHARINGFINAL_CARREPOSITORY_H

#include "../Models/Car.h"
#include <iostream>
#include <string>
#include <vector>

class CarRepository {
private:
    std::vector<Car> cars;
    std::string fileName;

    void readFromCsv();

    void writeToCsv();

public:

    CarRepository(std::string fileName);
    CarRepository() {readFromCsv();};

    std::string getFileName();

    Car findByLicensePlate(std::string &licensePlate);

    void saveCar(Car &car);

    void deleteCar(std::string &licensePlate);

    void updateCar(Car &car);

    std::vector<Car> listAllCars();

    std::vector<Car> searchCar(std::string &licensePlate); //V3.2 Auto nach Kennzeichen suchen

};


#endif //CARSHARINGFINAL_CARREPOSITORY_H
