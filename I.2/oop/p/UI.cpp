//
// Created by Arthur Horeanu on 05.06.2024.
//

#include <iostream>
#include "UI.h"

//Shows menu options
void UI::console() {
    std::cout << "Choose an option:\n"
            "1. See ALL products\n"
            "2. ADD a product\n";
}

void UI::menu() {
    console();
    populateData(action);
    int choice = 0;
    std::cin >> choice;
    if(choice==1)
        action.showAll();
    if(choice==2)
        addProduct();
}

void UI::populateData(Controller &action) const {
    Product p1 = Product("Croissant", 15.0, 2);
    action.add(p1);
}

void UI::addProduct() {
    std::string name;
    double price;
    int preparationTime;
    Product product = Product("Name", 0.0, 0);
    std::cin >> name;
    product.setName(name);
    std::cin >> price;
    product.setPrice(price);
    std::cin >> preparationTime;
    product.setPreparationTime(preparationTime);
    action.add(product);
}