#ifndef L3_GRAPH_H
#define L3_GRAPH_H

#include <fstream>
#include <iostream>
#include <vector>

class Graph {
private:
    int n;
    int m;
    std::vector<std::vector<int>> adjList;
public:
    Graph(std::string filename);
    void printGraph();
    bool isBinaryTree(int x);
    bool DFS(int x, std::vector<bool> visitedNodes, int parent);
};

#endif //L3_GRAPH_H
