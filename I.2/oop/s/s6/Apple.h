//
// Created by Arthur Horeanu on 04.06.2024.
//

#ifndef S6_APPLE_H
#define S6_APPLE_H

#include <string>
#include "Fruit.h"

class Apple : public Fruit{
private:
    std::string variety;
public:
    std::string getVariety();
    Apple();
    Apple(std::string color, std::string taste, double weight, std::string variety);
};


#endif //S6_APPLE_H
