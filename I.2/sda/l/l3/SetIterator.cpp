#include "SetIterator.h"
#include "Set.h"
#include <exception>

// Best, average and worst case: Theta(1)
SetIterator::SetIterator(const Set& m) : set(m)
{
    current = m.head;
}

// Best, average and worst case: Theta(1)
void SetIterator::first() {
    current=set.head;
}

// Best, average and worst case: Theta(1)
void SetIterator::next() {
    if(!valid()) {
        throw std::exception();
    }
    current=set.next[current];
}

// Best, average and worst case: Theta(1)
TElem SetIterator::getCurrent(){
    if(!valid())
        throw std::exception();
    return set.elements[current];
}

// Best, average and worst case: Theta(1)
bool SetIterator::valid() const {
    return current!=-1;
}