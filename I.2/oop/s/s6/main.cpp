#include <iostream>
#include "FruitVendor.h"
#include "Citrus.h"
#include "Basket.h"

int main() {
    Fruit apple("red", "sweet", 1);
    Citrus lemon("yellow", "sour", 1, true);
    std::vector<std::unique_ptr<Basket>> basket(5);
    basket.addFruit(apple);
    basket.addFruit(lemon);
    FruitVendor vendor("Bob");
}