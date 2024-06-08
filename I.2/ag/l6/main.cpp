#include <iostream>
#include "Graph.h"

int main() {
    Graph matrix = Graph("data.in");
    std::cout<<matrix.isValid();
}

