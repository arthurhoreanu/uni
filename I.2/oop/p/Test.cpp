//
// Created by Arthur Horeanu on 05.06.2024.
//

#include <cassert>
#include "Test.h"
#include "Catalog.h"

//All tests
void Test::tests() {
    testCatalog();
}

//Tests for repository
void Test::testCatalog(){
    Catalog catalog;
    // Test add and retrieve elements
    Product p1("Croissant", 15.0, 2);
    catalog.add(p1);
    assert(catalog.getAll().size() == 1);
}