#include <assert.h>
#include "Matrix.h"
#include <iostream>

using namespace std;

void testAll() {
    Matrix m(4, 4);
    assert(m.nrLines() == 4);
    assert(m.nrColumns() == 4);
    m.modify(1, 1, 5);
    assert(m.element(1, 1) == 5);
    m.modify(1, 1, 6);
    assert(m.element(1, 2) == NULL_TELEM);
    m.printMatrix();
    std::cout << std::endl;
    m.newDimension(3,3);
    m.printMatrix();
}