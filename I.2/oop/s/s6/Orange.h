//
// Created by Arthur Horeanu on 04.06.2024.
//

#ifndef S6_ORANGE_H
#define S6_ORANGE_H

#include <string>
#include "Citrus.h"


class Orange : public Citrus {
private:
    std::string variety;
public:
    Orange(std::string color, std::string taste, double weight, bool hasPeel, std::string variety);
    std::string getVariety();
};


#endif //S6_ORANGE_H
