#ifndef L2_GRAPH_H
#define L2_GRAPH_H
#include <iostream>

#include <vector>

class Graph {
private:
    int n, exponent;
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<int>> result;
    std::vector<std::vector<int>> temp;
    std::vector<std::vector<int>> B;
public:
    Graph(std::string filename);
    void printGraph();
    void multiply(std::vector<std::vector<int>>& result);
    std::vector<std::vector<int>> power(int exponent);
    void printPowerGraph(const std::vector<std::vector<int>>& result);
    bool isConnected();
};

#endif //L2_GRAPH_H