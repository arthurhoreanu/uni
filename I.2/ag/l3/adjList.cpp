#include "AdjList.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <list>

AdjList::AdjList(std::string filename){
    std::ifstream f;
    f.open(filename);
    f >> n;
    f >> m;
    int x,y;
    for(int i=0; i<m; i++){
        f>>x>>y;
        addEdge(x,y);
    }
}
AdjList::AdjList() {
    int n = 0;
    int m = 0;
}
void AdjList::addEdge(int x, int y) {
    adjList[x].push_back(y);
    adjList[y].push_back(x);
}

void AdjList::printGraph(){
    for (int i=0; i<n; i++){
        std::cout << "Node " << i << ": ";
        for(int j=0; j<adjList[i].size(); j++){
            std::cout<<adjList[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

void AdjList::BFS(int start) {
    std::vector<bool> visited(n);
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    std::queue<int> queue;

    visited[start] = true;
    queue.push(start);

    while (!queue.empty()) {
        int s = queue.front();
        std::cout << s << " ";
        queue.pop();

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                queue.push(i);
            }
        }
    }
}


void AdjList::DFS(int start) {

    visited[start] = true;
    std::cout << start << " "; // afisam nodul de la care incepem

    //parcurgem recursiv fiecare pereche din kantenliste
    for (int i : adjList[start]) {
        if (!visited[i]){
            DFS(i);
        }
    }
}