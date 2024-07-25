#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <iostream>
#include <vector>
#include <exception>
using namespace std;

// Best, average and worst: Theta(n)
SortedMultiMap::SortedMultiMap(Relation r) {
    // Internal values
    rel = r;
    root = -1;
    capacity = 10;
    length = 0;
    firstEmpty = 0;

    // Memory allocation for info-vectors
    left = new int[capacity];
    right = new int[capacity];
    parent = new int[capacity];

    // Initialising empty Nodes
    for (int i = 0; i < capacity; ++i) {
        info[i].key = NULL_TKEY;
        info[i].value = NULL_TVALUE;
        left[i] = -1;
        right[i] = -1;
        parent[i] = -1;
    }
}

// Best case: Theta(1)
// Average and worst: Theta(n log(n))
void SortedMultiMap::add(TKey c, TValue v) {
    // We check if the tree is empty
    if (length == 0) {
        // We allocate a new node for the root
        info[firstEmpty].key = c;
        info[firstEmpty].value = v;
        parent[firstEmpty] = -1;
        root = firstEmpty;
        left[root] = -1;
        right[root] = -1;
        firstEmpty = length+1;  // We update firstEmpty
        length++;
        return;
    }

    // We find the parent for the new node
    int parentIndex = root;
    int current = root;
    while (current != -1) {
        parentIndex = current;
        if (rel(c, info[current].key)) {
            current = left[current];
        } else {
            current = right[current];
        }
    }

    // We insert it at the appropriate position
    int newNodeIndex = length;
    info[newNodeIndex].key = c;
    info[newNodeIndex].value = v;

    // Case of new key
    if (parentIndex == -1) {
        if (rel(c, info[root].key)) {
            left[parentIndex] = newNodeIndex;
            parent[newNodeIndex] = parentIndex;
        } else {
            right[parentIndex] = newNodeIndex;
            parent[newNodeIndex] = parentIndex;
        }
    } else {
        // Case of Existing key
        int current = left[parentIndex];
        while (right[current] != -1) {
            current = right[current];
        }
        right[current] = newNodeIndex;
        parent[newNodeIndex] = parentIndex;
    }

    // **Fix for adding left child:**
    if (rel(c, info[parentIndex].key)) {
        left[parentIndex] = newNodeIndex;
    }

    length++;
}

// Best case: Theta(1)
// Average and worst: Theta(n log(n))
vector<TValue> SortedMultiMap::search(TKey c) const {
    vector<TValue> values;
    if (length == 0)
        return values;
    int current = root;
    while (current != -1) {
        if (info[current].key == c)
            values.push_back(info[current].value);
        if (rel(c, info[current].key))
            current = left[current];
        else
            current = right[current]; }
        return values;
    }

bool SortedMultiMap::remove(TKey c, TValue v) {
    //TODO - Implementation
}

// Best, average and worst: Theta(1)
int SortedMultiMap::size() const {
    return length;
}

// Best, average and worst: Theta(1)
bool SortedMultiMap::isEmpty() const {
    if(length==0){
        return true;
    }else{
        return false;
    }
}

SMMIterator SortedMultiMap::iterator() const {
    return SMMIterator(*this);
}

// Best, average and worst: Theta(1)
SortedMultiMap::~SortedMultiMap() {
    root = -1;
    length = 0;
    firstEmpty = 0;
}
