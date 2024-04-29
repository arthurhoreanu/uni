#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;

// Time complexity: Theta(1) for all cases
MapIterator::MapIterator(const Map& d) : map(d)
{
    current = map.head;
}

// Time complexity: Theta(1) for all cases
void MapIterator::first() {
    current = map.head;
}

// Time complexity: Theta(1) for all cases
void MapIterator::next() {
    if(!valid())
        throw exception();
    else if (current != nullptr) {
        current = current->next;
    }
}

// Time complexity: Theta(1) for all cases
TElem MapIterator::getCurrent(){
    if(!valid())
        throw exception();
    else if (current == nullptr) {
        return NULL_TELEM;
    }
    // Return a pair key/value from current key
    return TElem(current->key, current->value);
}

// Time complexity: Theta(1) for all cases
bool MapIterator::valid() const {
    if(current!=nullptr)
        return true;
    else
        return false;
}