//
// Created by stefa on 27/05/2024.
//

#include "CarUi.h"

void CarUi::printMenu() {
    std::cout << "Car Management System" << std::endl;
    std::cout << "1. Create Car" << std::endl;
    std::cout << "2. Delete Car" << std::endl;
    std::cout << "3. Update Car" << std::endl;
    std::cout << "4. List all Cars" << std::endl;
    std::cout << "5. Search Car by license plate" << std::endl;
    std::cout << "6. Deactivate car" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

void CarUi::createCar() {
    std::string licensePlate, model, brand, fuelType, transmission, color, remarks;
    bool isActive;
    int yearOfFirstRegistration;
    int mileage;
    float dailyRate;

    std::cout << "Enter license plate: ";
    std::cin >> licensePlate;
    std::cout << "Enter model: ";
    std::cin >> model;
    std::cout << "Enter brand: ";
    std::cin >> brand;
    std::cout << "Enter fuel type: ";
    std::cin >> fuelType;
    std::cout << "Enter transmission: ";
    std::cin >> transmission;
    std::cout << "Enter color: ";
    std::cin >> color;
    std::cout << "Enter remarks: ";
    std::cin >> remarks;
    std::cout << "Enter mileage: ";
    std::cin >> mileage;
    std::cout << "Enter daily Rate: ";
    std::cin >> dailyRate;
    std::cout << "Enter year of first registration: ";
    std::cin >> yearOfFirstRegistration;
    std::cout << "Enter is active status (true or false): ";
    std::cin >> isActive;

    try {
        Car newCar(licensePlate, model, brand, yearOfFirstRegistration,
                   mileage, dailyRate, fuelType, transmission, color, remarks, isActive);
        carController.createCar(newCar);
        std::cout << "New car added successfully!" << std::endl;
    } catch (std::invalid_argument e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}


void CarUi::deleteCar() {
    std::string licensePlate;
    std::cout << "Enter the license Plate: ";
    std::cin >>licensePlate;
    carController.deleteCar(licensePlate);
}


void CarUi::deactivateCar() {
    std::string licensePlate, model, brand, fuelType, transmission, color, remarks;
    bool isActive;
    int yearOfFirstRegistration;
    int mileage;
    float dailyRate;

    std::cout << "Enter licensePlate: ";
    std::cin >> licensePlate;
    std::cout << "Enter model: ";
    std::cin >> model;
    std::cout << "Enter brand: ";
    std::cin >> brand;
    std::cout << "Enter fuel type: ";
    std::cin >> fuelType;
    std::cout << "Enter transmission: ";
    std::cin >> transmission;
    std::cout << "Enter color: ";
    std::cin >> color;
    std::cout << "Enter remarks: ";
    std::cin >> remarks;
    std::cout << "Enter mileage: ";
    std::cin >> mileage;
    std::cout << "Enter daily rate: ";
    std::cin >> dailyRate;
    std::cout << "Enter year of first registration: ";
    std::cin >> yearOfFirstRegistration;
    std::cout << "Enter is active status (true or false): ";
    std::cin >> isActive;

    try {
        Car newCar(licensePlate, model, brand, yearOfFirstRegistration,
                   mileage, dailyRate, fuelType, transmission, color, remarks, isActive);
        carController.deactivateCar(newCar);
        std::cout << "Car deactivated successfully!" << std::endl;
    } catch (std::invalid_argument e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}


void CarUi::listCars() {
    carController.listCars();
}


void CarUi::searchCar() {
    std::string licensePlate;
    std::cout << "Enter a license plate: " <<std::endl;
    std::cin >> licensePlate;
    carController.searchCar(licensePlate);
}


void CarUi::updateCar() {
    std::string licensePlate, model, brand, fuelType, transmission, color, remarks;
    bool isActive;
    int yearOfFirstRegistration;
    int mileage;
    float dailyRate;

    std::cout << "Enter licensePlate: ";
    std::cin >> licensePlate;
    std::cout << "Enter new model: ";
    std::cin >> model;
    std::cout << "Enter new brand: ";
    std::cin >> brand;
    std::cout << "Enter new fuel type: ";
    std::cin >> fuelType;
    std::cout << "Enter new transmission: ";
    std::cin >> transmission;
    std::cout << "Enter new color: ";
    std::cin >> color;
    std::cout << "Enter new remarks: ";
    std::cin >> remarks;
    std::cout << "Enter new mileage: ";
    std::cin >> mileage;
    std::cout << "Enter new daily rate: ";
    std::cin >> dailyRate;
    std::cout << "Enter new year of first registration: ";
    std::cin >> yearOfFirstRegistration;
    std::cout << "Enter is active status (true or false): ";
    std::cin >> isActive;

    try {
        Car newCar(licensePlate, model, brand, yearOfFirstRegistration,
                   mileage, dailyRate, fuelType, transmission, color, remarks, isActive);
        carController.updateCar(newCar);
        std::cout << "Car deactivated successfully!" << std::endl;
    } catch (std::invalid_argument e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void CarUi::run() {
    int choice;
    do {
        printMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                createCar();
            case 2:
                deleteCar();
            case 3:
                updateCar();
            case 4:
                listCars();
            case 5:
                searchCar();
            case 6:
                deactivateCar();
            case 0:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cerr << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 0);
}



