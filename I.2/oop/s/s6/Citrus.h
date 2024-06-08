//
// Created by Arthur Horeanu on 04.06.2024.
//

#ifndef S6_CITRUS_H
#define S6_CITRUS_H

#include "Fruit.h"

class Citrus : public Fruit{
private:
    bool hasPeel;
public:
    Citrus();
    Citrus(std::string color, std::string taste, double weight, bool hasPeel);
    bool getHasPeel();
};


#endif //S6_CITRUS_H
