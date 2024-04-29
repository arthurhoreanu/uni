#include <iostream>
#include "Graph.h"

int main() {
    Graph g = Graph("data.in");
    g.printGraph();
    if(g.isBinaryTree(0)==0)
        std::cout << "The graph is not a binary tree";
    else
        std::cout << "The graph is a binary tree";
    return 0;
}
