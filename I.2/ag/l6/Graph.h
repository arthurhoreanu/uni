//
// Created by Arthur Horeanu on 07.06.2024.
//

#ifndef L6_GRAPH_H
#define L6_GRAPH_H
#include <string>
using namespace std;

class Graph {
private:
    int m,n,s,t;
    int capacity[100][100];
    int flow[100][100];
    std::vector<int> parent;

public:
    Graph(string filename);
    bool isValid();
    bool BFS(int source, int sink, std::vector<int>& parent);
    void edmondsKarp(int source, int sink);
};

#endif //L6_GRAPH_H
