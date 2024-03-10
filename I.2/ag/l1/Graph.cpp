#include "Graph.h"
#include <fstream>
#include <iostream>
using namespace std;

Graph::Graph(){
    ifstream f;
    f.open("data.in");
    f >> n;
    f >> m;
    int x,y;
    for(int i=0; i<m; i++){
        f>>x>>y;
        addEdge(x,y);
    }
}

void Graph::addEdge(int x, int y){
    matrix[x][y] = 1;
    matrix[y][x] = 1;
}

void Graph::printGraph() {
    for(int i = 0; i<n; i++)
    {for(int j = 0; j<n; j++)
            std::cout << matrix[i][j] << " ";
            std::cout << endl;}
}

void Graph::isEdge(int x, int y){
    cout << "Is [0][1] an edge? ";
    if (matrix[x][y] == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

void Graph::convertToAdjList(){
    adjList.resize(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == 1){
                adjList[i].push_back(j);
            }
        }
    }
}

void Graph::printAdjList() {
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        for (auto neighbour : adjList[i]) {
            cout << neighbour << " ";
        }
        cout << endl;
    }
}

int Graph::calculateMaxDegree(){
    maxDegree = INT_MIN;
    for(int i=0; i<n; i++){
        int degree = 0;
        for(int j=0; j<n; j++){
            if(matrix[i][j] == 1){
                degree++;
            }
        }
        if(degree > maxDegree){
            maxDegree = degree;
        }
    }
    return maxDegree;
}

int Graph::calculateMinDegree() {
    minDegree = INT_MAX;
    for (int i = 0; i < n; i++) {
        int degree = 0;
        for (auto neighbour : adjList[i]) {
            degree++;
        }
        minDegree = min(minDegree, degree);
    }
    return minDegree;
}

void Graph::minAndMax(){
    cout<<"Max: " << maxDegree<<endl;
    cout<<"Min: " << minDegree<<endl;
}