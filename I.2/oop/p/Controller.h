//
// Created by Arthur Horeanu on 05.06.2024.
//

#ifndef P_CONTROLLER_H
#define P_CONTROLLER_H

#include "Catalog.h"

class Controller {
    Catalog catalog;
public:
    void add(Product product);
    void showAll();
};


#endif //P_CONTROLLER_H
