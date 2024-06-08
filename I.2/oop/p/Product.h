//
// Created by Arthur Horeanu on 05.06.2024.
//

#ifndef P_PRODUCT_H
#define P_PRODUCT_H

#include <string>

class Product {
private:
    std::string name;
    double price;
    int preparationTime; // in minutes
public:
    Product(std::string name, double price, int preparationTime);
    std::string getName();
    void showProduct();
    void setName(std::string name);
    void setPrice(double price);
    void setPreparationTime(int preparationTime);
};


#endif //P_PRODUCT_H
