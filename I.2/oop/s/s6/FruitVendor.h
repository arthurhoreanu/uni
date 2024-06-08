//
// Created by Arthur Horeanu on 04.06.2024.
//

#ifndef S6_FRUITVENDOR_H
#define S6_FRUITVENDOR_H

#include <string>
#include <memory>
#include "Basket.h"

class FruitVendor {
private:
    std::string name;
    std::vector<std::unique_ptr<Basket>> baskets;
public:
    std::string getName();
    FruitVendor(std::string name);
    void addBasket(std::unique_ptr<Basket> basket);
};

#endif //S6_FRUITVENDOR_H
