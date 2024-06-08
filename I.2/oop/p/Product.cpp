//
// Created by Arthur Horeanu on 05.06.2024.
//

#include "Product.h"
#include <iostream>

Product::Product(std::string name, double price, int preparationTime) {
    this->name = name;
    this->price = price;
    this->preparationTime = preparationTime;
}

//Getter for name
std::string Product::getName() {
    return name;
}

//Setter for name
void Product::setName(std::string name) {
    name = name;
}

//Setter for price
void Product::setPrice(double price) {
    price = price;
}
//Setter for preparationTime
void Product::setPreparationTime(int preparationTime) {
    preparationTime = preparationTime;
}

//Function that shows the Product with all its info
void Product::showProduct() {
    std::cout << "Name: " << name << ", Price: " << price << ", Preparation Time: " << preparationTime;
}