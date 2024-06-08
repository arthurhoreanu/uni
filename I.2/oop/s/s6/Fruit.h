//
// Created by Arthur Horeanu on 04.06.2024.
//

#ifndef S6_FRUIT_H
#define S6_FRUIT_H

#include <string>


class Fruit {
private:
    std::string color;
    std::string taste;
    double weight;

public:
    Fruit(std::string color, std::string taste, double weight);
    std::string getColor();
    std::string getTaste();
    double getWeight();
};


#endif //S6_FRUIT_H
