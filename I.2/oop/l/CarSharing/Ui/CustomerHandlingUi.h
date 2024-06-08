//
// Created by stefa on 27/05/2024.
//

#ifndef CARSHARING_CUSTOMERHANDLINGUI_H
#define CARSHARING_CUSTOMERHANDLINGUI_H


#include "../Controller/CustomerController.h"
#include <iostream>
#include <string>

class CustomerHandlingUI {
private:
    CustomerController customerController;

    void printMenu();
    void handleAddCustomer();
    void handleDeleteCustomer();
    void handleUpdateCustomer();
    void handleListCustomers();
    void handleSearchCustomerByEmail();
    void handleSearchCustomerByPhoneNumber();
    void handleSearchCustomerByName();

public:
    CustomerHandlingUI(std::string fileName) : customerController(fileName) {}
    void run();
};


#endif //CARSHARING_CUSTOMERHANDLINGUI_H
