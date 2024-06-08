//
// Created by demku on 5/27/2024.
//

#ifndef CARSHARINGFINAL_CARCONTROLLER_H
#define CARSHARINGFINAL_CARCONTROLLER_H

#include "../Repository/CarRepository.h"
#include "vector"

class CarController {

private:
    CarRepository carRepository ;

public:
    CarController(CarRepository repository);
   void createCar(Car car);
   void updateCar(Car car);
   void deleteCar(std::string &licensePlate);
   void deactivateCar(Car car);
   std::vector<Car> listCars();
   std::vector<Car> searchCar(std::string &licensePlate);
};


#endif //CARSHARINGFINAL_CARCONTROLLER_H
