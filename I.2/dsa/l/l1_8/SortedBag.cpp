#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <iostream>
#include <vector>

// SortedBag constructor
// Time complexity: Theta(1) for all cases
SortedBag::SortedBag(Relation r) {
    this->capacity = 4;
    this->numberOfElements = 0;
    this->elements = new TElem[capacity];
    this->relation = r;
}

// SortedBag resize method
// Time complexity: Theta(n) for all cases (n is the number of elements in the bag)
void SortedBag::resize(int newCapacity) {
    auto newElements = new TElem[newCapacity];
    for(int i = 0; i < numberOfElements; i++) {
        newElements[i] = elements[i];
    }
    delete[] elements;
    elements = newElements;
    capacity = newCapacity;
}

// SortedBag autoResize method
// Time complexity: Theta(1) for all cases
void SortedBag::autoResize() {
    if(numberOfElements == capacity) {
        resize(capacity * 2);
    } else if(numberOfElements <= capacity / 4 && capacity / 2 >= 4) {
        resize(capacity / 2);
    }
}

// SortedBag add method
// Time complexity: Theta(n) for worst case
// Theta(1) for best and average case
void SortedBag::add(TComp e) {
    numberOfElements++;
    autoResize();
    int position = numberOfElements - 1;
    while(position > 0 && !relation(elements[position - 1], e)) {
        elements[position] = elements[position - 1];
        position--;
    }
    elements[position] = e;
}

// SortedBag remove method
// Time complexity: Theta(n) for worst case
// Theta(1) for best and average case
bool SortedBag::remove(TComp e) {
    int i = 0;
    while (i < numberOfElements && elements[i] != e) {
        ++i;
    }
    if (i < numberOfElements) {
        for (int j = i; j < numberOfElements - 1; ++j) {
            elements[j] = elements[j + 1];
        }
        --numberOfElements;
        return true;
    }
    return false;
}

// SortedBag search method
// Time complexity: Theta(n) for worst and average case
// Theta(1) best case
bool SortedBag::search(TComp e) const {
    for (int i = 0; i < numberOfElements; ++i) {
        if (elements[i] == e) {
            return true;
        }
    }
    return false;
}

// SortedBag nrOccurrences method
// Time complexity: Theta(n) for all cases
int SortedBag::nrOccurrences(TComp e) const {
    int count = 0;
    for(int i = 0; i < numberOfElements; i++) {
        if(elements[i] == e) {
            count++;
        }
    }
    return count;
}

// SortedBag size method
// Time complexity: Theta(1) for all cases
int SortedBag::size() const {
    return numberOfElements;
}

bool SortedBag::isEmpty() const {
    return numberOfElements == 0;
}

SortedBagIterator SortedBag::iterator() const {
    return SortedBagIterator(*this);
}

/*
// Time complexity: O(n^2) worst case
// Theta(1) best and average case
int SortedBag::removeMaxFrequency() {
    if (numberOfElements == 0) {
        return false;
    }
    int maxElement = 1000;
    std::vector<int> frequency(maxElement, 0);
    int maxFrequency = 0;
    for (int i = 0; i < numberOfElements; i++) {
        frequency[elements[i]]++;
        if (frequency[elements[i]] > maxFrequency) {
            maxFrequency = frequency[elements[i]];
        }
    }
    std::vector<int> result;
    for (int i = 0; i < numberOfElements; i++) {
        if (frequency[elements[i]] != maxFrequency) {
            result.push_back(elements[i]);
        }
    }
    return true;
}
 */

SortedBag::~SortedBag() {
    delete[] elements;
}