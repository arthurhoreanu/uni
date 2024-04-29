#include "Map.h"
#include "MapIterator.h"

// Map constructor
// Time complexity: Theta(1) for all cases
Map::Map() {
    this->head= nullptr;
}

// Map destructor
// Time complexity: Theta(1) for best case
// Theta(n) for average and worst case
Map::~Map() {
    Node* current = head;
    Node* next;

    // Loop through the map and free the memory for each node
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }

    // After freeing memory for all nodes, set head to nullptr to mark the map as empty
    head = nullptr;
}

// Map add method
// Time complexity: Theta(1) for best case
// Theta(n) for average and worst case
TValue Map::add(TKey c, TValue v){
    if (head == nullptr) { // Map is empty, creating the first node
        head = new Node(c, v);
        return NULL_TVALUE;
    }

    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr) {
        if (current->key == c) { // If the key already exists, update value and return previous value
            TValue oldValue = current->value;
            current->value = v;
            return oldValue;
        }
        previous = current;
        current = current->next;
    }

    previous->next = new Node(c, v);
    return NULL_TVALUE;
}

// Map search method
// Time complexity: Theta(1) for best case
// Theta(n) for average and worst case
TValue Map::search(TKey c) const{
    if (head == nullptr) { // Map is empty, thus no key-value pair
        return NULL_TVALUE;
    }

    Node* current = head;
    TValue lastValue = NULL_TVALUE; // Implicit value in case of not found key

    // Loop through the map to search for the last value associated with they given key
    while (current != nullptr) {
        if (current->key == c) {
            lastValue = current->value; // Update last value
        }
        current = current->next;
    }

    return lastValue;
}

// Map remove method
// Time complexity: Theta(1) for best case
// Theta(n) for average and worst case
TValue Map::remove(TKey c){
    if (head == nullptr) {
        return NULL_TVALUE;
    }

    Node* current = head;
    Node* prev = nullptr;
    TValue removedValue = NULL_TVALUE;

    while (current != nullptr) {
        if (current->key == c) {
            removedValue = current->value;

            if (prev == nullptr) { // If the node is the first one in the map
                head = current->next;
            } else {
                prev->next = current->next;
            }

            delete current;
            break;
        }

        prev = current;
        current = current->next;
    }

    return removedValue;
}

// Map size method
// Time complexity: Theta(1) for best case
// Theta(n) for average and worst case
int Map::size() const {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// Map isEmpty method
// Time complexity: Theta(1) for all cases
bool Map::isEmpty() const{
    if(head == nullptr)
        return true;
    else
        return false;
}

// Map iterator method
// Time complexity: Theta(1) for best case
// Theta(n) for average and worst case
MapIterator Map::iterator() const {
    return MapIterator(*this);
}

// Map reverse method
// Time complexity: Theta(1) for best case
// Theta(n) for average and worst case
void Map::reverseMap() {
    Node* previous = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->next; // All map elements, except the first one
        current->next = previous; // The first element in the map
        previous = current; // Stores what is currenty in current, new element will always be on the first position
        current = next; // The rest of the elements
    }
    head = previous;
}