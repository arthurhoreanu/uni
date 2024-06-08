//
// Created by Arthur Horeanu on 05.06.2024.
//

#ifndef P_ORDER_H
#define P_ORDER_H

#include <string>
#include <list>
#include "Product.h"

class Order {
private:
    int id;
    std::string clientName;
    std::list<Product> products;
public:

};


#endif //P_ORDER_H
