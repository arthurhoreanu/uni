#include <iostream>
#include "Test.h"
#include "UI.h"

int main() {
    Test test;
    test.tests();
    std::cout << "All tests passed!" << std::endl;
    UI console;
    console.menu();
}
