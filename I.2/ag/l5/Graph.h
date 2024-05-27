#ifndef GRAPH_H
#define GRAPH_H

#include <string>

struct Edge {
    int node1;
    int node2;
    Edge* next;
};

class Graph {
public:
    Graph(const std::string& filename);
    void insertEdge(Edge*& head, int node1, int node2);
    void print();
    void BFS(std::vector<int>& order);
    void improvedColoring();

    int n, m;       // number of nodes
    Edge* edgeList; // edge list head
};

#endif // GRAPH_H