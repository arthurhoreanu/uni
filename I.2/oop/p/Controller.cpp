//
// Created by Arthur Horeanu on 05.06.2024.
//

#include "Controller.h"
#include <iostream>

//Function for adding a product
void Controller::add(Product product) {
    catalog.add(product);
}

//Function that shows all products
void Controller::showAll() {
    std::list<Product> repository = catalog.getAll();
    for (Product i: repository){
        i.showProduct();
        std::cout << "\n";
    }
}