#include "SMMIterator.h"
#include "SortedMultiMap.h"

SMMIterator::SMMIterator(const SortedMultiMap& d) : map(d) {
    this->stackCapacity = 100;
    this->stackLength = 0;
    this->stack = new int[stackCapacity];
    current = -1;
    first();
}

// Best case: Theta(1)
// Average and worst case: Theta(n log(n))
void SMMIterator::first() {
    while (stackLength > 0) {
        pop();
    }
    current = map.root;
    if (current != -1) {
        push(current);
    }
    // We move to the leftmost node
    while (current != -1 && map.left[current] != -1) {
        current = map.left[current];
        push(current);
    }
    if (stackLength > 0) {
        current = pop();
    } else {
        current = -1;
    }
}

// Best case: Theta(1)
// Average and worst case: Theta(n log(n))
void SMMIterator::next() {
    if(!valid())
        throw std::exception();
    // We check if there is a right child for the current node
    if (map.right[current] != -1) {
        current = map.left[map.right[current]];
        while (current != -1) {
            push(current);
            current = map.left[current];
        }
    } else {
        if(stackLength>0)
            current = pop();
        else
            current = -1;
    }
}

// Best, average and worst case: Theta(1)
bool SMMIterator::valid() const {
    return current != -1;
}

// Best, average and worst case: Theta(1)
TElem SMMIterator::getCurrent() const {
    if (current == -1) {
        return NULL_TELEM;
    }
    return TElem(map.info[current].key, map.info[current].value);
}

// Best, average and worst case: Theta(1)
int SMMIterator::pop() {
    if (stackLength == 0) {
        throw exception();
    }
    return stack[--stackLength];
}

// Best case: Theta(1)
// Average and worst case: Theta(n log(n))
void SMMIterator::push(int nodeIndex) {
    if (stackLength == stackCapacity) {
        stackCapacity *= 2;
        int* newStack = new int[stackCapacity];
        for (int i = 0; i < stackLength; ++i) {
            newStack[i] = stack[i];
        }
        delete[] stack;
        stack = newStack;
    }
    stack[stackLength++] = nodeIndex;
}

// Best case: Theta(1)
// Average and worst case: Theta(n log(n))
bool SMMIterator::previous() {
    if(!valid())
        throw std::exception();
    // If the stack is empty, there are no previous elements
    if (stackLength == 0) {
        return false;
    }

    int parentIndex = map.parent[current];

    // If the parent has a left child, move to the leftmost child
    if (map.left[parentIndex] != -1) {
        current = map.left[parentIndex];
        while (current != -1) {
            push(current);
            current = map.left[current];
        }
    } else {
        // If there is no left child, we move to the parent itself
        current = parentIndex;
    }

    // We return the value associated with the previous node
    if(map.info[current].value)
        return true;
}