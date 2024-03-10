#include <vector>

class Graph {
private:
    int n;
    int m;
    int matrix[100][100];
    std::vector<std::vector<int>> adjList;
    int maxDegree;
    int minDegree;
public:
    Graph();
    void printGraph();
    void addEdge(int x, int y);
    void isEdge(int x, int y);
    void convertToAdjList();
    void printAdjList();
    int calculateMaxDegree();
    int calculateMinDegree();
    void minAndMax();
};