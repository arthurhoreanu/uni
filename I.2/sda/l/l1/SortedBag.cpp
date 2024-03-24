#include "SortedBag.h"
#include "SortedBagIterator.h"

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

// SortedBag binarySearch method
// Time complexity: Theta(log n) for all cases
int SortedBag::binarySearch(TComp e) const {
    int left = 0, right = numberOfElements - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(elements[mid] == e) {
            return mid;
        } else if(relation(elements[mid], e)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// SortedBag remove method
// Time complexity: Theta(n) for worst case
// Theta(log n) for best and average case
bool SortedBag::remove(TComp e) {
    int position = binarySearch(e);
    if(position == -1) {
        return false;
    }
    for(int i = position + 1; i < numberOfElements; i++) {
        elements[i - 1] = elements[i];
    }
    numberOfElements--;
    autoResize();
    return true;
}

// SortedBag search method
// Time complexity: Theta(log n) for worst case
// Theta(1) for best and average case
bool SortedBag::search(TComp e) const {
    if(isEmpty()) {
        return false;
    }
    int pos = binarySearch(e);
    return pos != -1;
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

SortedBag::~SortedBag() {
    delete[] elements;
}