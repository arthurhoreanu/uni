//
// Created by Arthur Horeanu on 05.06.2024.
//

#include "Catalog.h"

void Catalog::add(Product product) {
    int found = 0;
    for (Product i: products){
        if (i.getName() == product.getName()){
            found = 1;
        }
    }
    if (found == 0)
        products.push_back(product);
}

//Function that returns the content of the container
std::list<Product> Catalog::getAll() {
    return products;
}