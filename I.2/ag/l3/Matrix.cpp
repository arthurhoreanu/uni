#include "Matrix.h"
#include <fstream>
#include <iostream>
#include <stack>

using namespace std;

Matrix::Matrix(std::string filename){
    ifstream f;
    f.open(filename);
    f >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int x;
            f >> x;
            if (x == 1) {
                matrix[i][j]=1;
                matrix[j][i]=1;
            }
        }
}

void Matrix::printMatrix(){
    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
void Matrix::DFS(int start){
    visited[start] = true;
    cout << start << " "; // Afisam nodul de la care începem

    // Parcurgem recursiv vecinii nodului de start
    for (int i = 0; i < n; ++i) {
        if (matrix[start][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

void Matrix::BreadthFirstSearch(int x) {
    std::vector<bool> visited(n);
    for(int i = 0; i<=n; i++){
        visited[i] = false;
    }
    int queue[100];
    int front = 0;
    int rear = 0;

    visited[x] = true;
    queue[rear++] = x;

    while (front < rear) {
        int currentNode = queue[front++];
        cout << currentNode << " ";

        for (int i = 0; i < n; i++) {
            if (matrix[currentNode][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    cout << endl;
}

bool Matrix::isBinaryTree() {
    int edges = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] == 1)
                edges++;
    edges /= 2;
    if (edges != n - 1)
        return false;

    for (int i = 0; i < n; i++) {
        int degree = 0;
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                degree++;
                if (degree > 2) {
                    return false;
                }
            }
        }
    }

    bool visited[100] = {false};
    int numVisited = 0;
    stack<int> stack;
    stack.push(0);
    while (!stack.empty()) {
        int node = stack.top();
        stack.pop();
        if (!visited[node]) {
            visited[node] = true;
            numVisited++;
            for (int i = 0; i < n; i++) {
                if (matrix[node][i] == 1) {
                    stack.push(i);
                }
            }
        }
    }
    if (numVisited != n) {
        return false;
    }
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    return true;
}
/*
    if (isCycle(0, visited, -1)) {
        return false;
    }
    return true;
}


bool Matrix::isCycle(int node, bool *visited, int parent) {
    visited[node] = true;
    for (int i = 0; i < n; i++) {
        if (matrix[node][i] == 1) {
            if (!visited[i]) {
                if (isCycle(i, visited, node)) {
                    return true;
                }
            } else if (i != parent) {
                return true;
            }
        }
    }
    return false;
}
 */