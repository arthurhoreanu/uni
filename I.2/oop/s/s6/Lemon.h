//
// Created by Arthur Horeanu on 04.06.2024.
//

#ifndef S6_LEMON_H
#define S6_LEMON_H

#include <string>
#include "Citrus.h"

class Lemon : public Citrus{
private:
    std::string variety;
public:
    Lemon(std::string color, std::string taste, double weight, bool hasPeel, std::string variety);
    std::string getVariety();
};


#endif //S6_LEMON_H
