#ifndef AGEXERSARE_MATRIX_H
#define AGEXERSARE_MATRIX_H

#include <string>
#include <map>
class Matrix {
private:
    int n;
    int m;
    int matrix[100][100];
    std::map<int, bool> visited;

public:

    Matrix(std::string filename);

    void addEdge(int x, int y);

    bool isEdge(int x, int y);

    void printMatrix();
    void DFS(int start);
    void BreadthFirstSearch(int x);
    bool isBinaryTree();
    //bool isCycle(int node, bool *visited, int parent);

};


#endif //AGEXERSARE_MATRIX_H

