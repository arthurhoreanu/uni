//
// Created by Arthur Horeanu on 05.06.2024.
//

#ifndef P_CATALOG_H
#define P_CATALOG_H

#include <list>
#include "Product.h"

class Catalog {
private:
    std::list<Product> products;
public:
    void add(Product product);
    std::list<Product> getAll();
};


#endif //P_CATALOG_H
