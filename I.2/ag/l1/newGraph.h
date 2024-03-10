#include <vector>

class newGraph {
private:
    std::vector<std::vector<int>> newAdjList;
    int n;
    int m;
    int matrix[100][100];
    int minDegree;
    int maxDegree;

public:
    newGraph();
    void printNewAdjList();
    int calculateNewMinDegree();
    int calculateNewMaxDegree();
    void newMinAndMax();
};