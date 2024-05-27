#pragma once

#include "SortedMultiMap.h"


class SMMIterator{
    friend class SortedMultiMap;
private:
    //DO NOT CHANGE THIS PART
    const SortedMultiMap& map;
    SMMIterator(const SortedMultiMap& map);

    //TODO - Representation
    int current;
    Node** stack;
    int stackLength;
    int stackCapacity;

public:
    void first();
    void next();
    bool valid() const;
    TElem getCurrent() const;
};

