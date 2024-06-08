//
// Created by Arthur Horeanu on 04.06.2024.
//

#ifndef S6_BASKET_H
#define S6_BASKET_H

#include <iostream>
#include <vector>
#include <memory>
#include "Fruit.h"

class Basket {
private:
    int capacity;
    std::vector<std::shared_ptr<Fruit>> fruits;
public:
    int getCapacity();
    Basket(int capacity);
    virtual void addFruit(std::unique_ptr<Fruit> fruit) {
        fruits.push_back(fruit);
    }
};


#endif //S6_BASKET_H
