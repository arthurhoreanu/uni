#pragma once
#include "Map.h"
class MapIterator
{
    //DO NOT CHANGE THIS PART
    friend class Map;
private:
    const Map& map;
    MapIterator(const Map& m);

    //TODO - Representation
    Map::Node* current;
public:
    void first();
    void next();
    TElem getCurrent();
    bool valid() const;
};


