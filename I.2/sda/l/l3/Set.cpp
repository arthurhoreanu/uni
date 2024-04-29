#include "Set.h"
#include "SetIterator.h"
#include <exception>
#include <iostream>

// Best, average and worst case: Theta(n)
// const, complex liniara, n e cap init, initializam tot in constructor
Set::Set() {
    this->currentSize=0;
    this->capacity=10;
    this->firstEmpty=0;
    this->head=-1;
    this->elements=new TElem[this->capacity];
    this->next=new int[this->capacity];
    for(int idx=0; idx< this->capacity; idx++){
        this->elements[idx]=NULL_TELEM;
    }
    for(int idx=0; idx< this->capacity-1; idx++){
        this->next[idx]=idx+1;
    }
    this->next[this->capacity-1]=-1;
}

// Best, average and worst case: Theta(n)
// const, complex liniara, 2*cap init
void Set::resize() {
    int newCapacity=2*capacity;
    TElem* newElements=new TElem[newCapacity];
    int* newNext=new int[newCapacity];
    for(int idx=0; idx<capacity; idx++){
        newElements[idx]=elements[idx];
        newNext[idx]=next[idx];
    }
    for(int idx=capacity; idx<newCapacity-1; idx++) {
        newNext[idx] = idx + 1;
    }
    newNext[newCapacity-1]=-1;
    delete[] elements;
    delete[] next;
    elements=newElements;
    next=newNext;
    firstEmpty=capacity;
    capacity=newCapacity;
}

// Best case: Theta(1)
// Average and worst case: Theta(n)
// TODO exception Set- elem unique, unordered--> add anywhere(first), no space left
bool Set::add(TElem elem) {
    if(search(elem))
        return false;
    if(firstEmpty==-1)
        resize();
    int newPos=firstEmpty;
    firstEmpty=next[firstEmpty];
    elements[newPos]=elem;
    next[newPos]=head;
    head=newPos;
    currentSize++;
    return true;
}

// Best case: Theta(1) (firstEmpty ul e imediat la indemana si elem e unic)
// Average and worst case: Theta(n)
bool Set::remove(TElem elem) {
    int current=head;
    int previous=-1;
    while(current!=-1 && elements[current]!=elem){
        previous=current;
        current= this->next[current];
    }
    if(current==-1)
        return false;
    if(previous!=-1)
        next[previous]=next[current];
    else
        head=next[head];
    next[current]= firstEmpty;
    firstEmpty=current;
    currentSize--;
    return true;
}

// Best, average and worst case: Theta(n) (trebuie sa trav toata lista const)
bool Set::search(TElem elem) const {
    int current=head;
    while(current!=-1){
        if(elements[current]==elem){
            return true;
        }
        current=next[current];
    }
    return false;
}

// Best, average and worst case: Theta(1)
int Set::size() const {
    return currentSize;
}

// Best, average and worst case: Theta(1)
bool Set::isEmpty() const {
    return currentSize == 0;
}

// Best, average and worst case: Theta(n^2)
Set Set::unionWith(const Set& other) const {
    Set unionSet;
    SetIterator it = this->iterator();
    while (it.valid()) {
        unionSet.elements[unionSet.firstEmpty] = it.getCurrent();
        unionSet.next[unionSet.firstEmpty] = unionSet.head;
        unionSet.head = unionSet.firstEmpty;
        unionSet.firstEmpty++;
        unionSet.currentSize++;
        it.next();
    }
    SetIterator itTwo = other.iterator();
    while (itTwo.valid()) {
        TElem elem = itTwo.getCurrent();
        bool found = false;
        int current = unionSet.head;
        while (current != -1 && !found) {
            if (unionSet.elements[current] == elem) {
                found = true;
            }
            current = unionSet.next[current];
        }
        if (!found) {
            unionSet.elements[unionSet.firstEmpty] = elem;
            unionSet.next[unionSet.firstEmpty] = unionSet.head;
            unionSet.head = unionSet.firstEmpty;
            unionSet.firstEmpty++;
            unionSet.currentSize++;
        }
        itTwo.next();
    }
    return unionSet;
}

// Functie aditionala pentru a ne verifica corectitudine reuniunii
// Best, average and worst case: Theta(n)
void Set::print() const {
    std::cout << "{ ";
    if (isEmpty()) {
        std::cout << " }";
        return;
    }
    SetIterator it = this->iterator();
    while (it.valid()) {
        std::cout << it.getCurrent() << ", ";
        it.next();
    }
    std::cout << "}" << std::endl;
}

// Best, average and worst case: Theta(1)
Set::~Set() {
    delete[] elements;
    delete[] next;
}

// Best, average and worst case: Theta(1)
SetIterator Set::iterator() const {
    return SetIterator(*this);
}