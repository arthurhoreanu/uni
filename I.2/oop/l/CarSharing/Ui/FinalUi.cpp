//
// Created by Darius on 5/28/2024.
//

#include "FinalUi.h"


void FinalUi::displayMenuEmployee() {
    std::cout<<"1. Car Menu"<<std::endl;
    std::cout<<"2. Customer Menu"<<std::endl;
    std::cout<<"0. Exit"<<std::endl;
    std::cout<<"Enter youre choice"<<std::endl;
}

void FinalUi::handleMenuEmployee() {
    int choice;
    CarUi caruii("Cars.csv");
    CustomerHandlingUI customer("Customers.csv");
    do{
        displayMenuEmployee();
        std::cin>>choice;
        switch(choice){
            case 1:
                caruii.run();
                break;
            case 2:
                customer.run();
                break;
            case 0:
                std::cout<<"Existing...";
                break;
        }
    }while(choice != 0);

}


void FinalUi::runAll() {
    User user;
    if(user.login() == 2 || user.login() == 3){//Logged as Employee or admin
        handleMenuEmployee();
    }

}