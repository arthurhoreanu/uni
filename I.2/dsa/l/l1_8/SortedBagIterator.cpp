#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

// Time complexity: Theta(1) for all cases
SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
    current =  0;
}

// Time complexity: Theta(1) for all cases
TComp SortedBagIterator::getCurrent() {
    if (!valid())
        throw exception();
    return this->bag.elements[current];
}

// Time complexity: Theta(1) for all cases
bool SortedBagIterator::valid() {
    if (this->bag.isEmpty())
        return false;
    if (this->current < 0 || this->current >= this->bag.numberOfElements)
        return false;
    return true;
}

// Time complexity: Theta(1) for all cases
void SortedBagIterator::next() {
    if (this->current == this->bag.numberOfElements)
        throw exception();
    this->current++;
}

// Time complexity: Theta(1) for all cases
void SortedBagIterator::first() {
    if (this->bag.isEmpty())
        throw exception();
    this->current = 0;
}