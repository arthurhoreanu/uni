//
// Created by stefa on 27/05/2024.
//

#ifndef CARSHARING_CARUI_H
#define CARSHARING_CARUI_H
#include "../Controller/CarController.h"


class CarUi{
private:
    CarController carController;
    void printMenu();
    void createCar();
    void updateCar();
    void deleteCar();
    void deactivateCar();
    void listCars();
    void searchCar();
public:
    CarUi(std::string fileName) : carController(fileName){}
    void run();

};


#endif //CARSHARING_CARUI_H
