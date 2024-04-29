#include "Graph.h"
#include <fstream>
#include <iostream>

Graph::Graph(std::string filename){
    std::ifstream f;
    f.open(filename);
    f >> n;
    f >> m;
    adjList.resize(n);
    int x,y;
    for(int i=0; i<m; i++){
        f>>x>>y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
}

void Graph::printGraph(){
    for (int i=0; i<n; i++){
        std::cout << "Node " << i << ": ";
        for(int j=0; j<adjList[i].size(); j++){
            std::cout<<adjList[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

bool Graph::isBinaryTree(int x) {
    if (m != n-1) // verificam daca este arbore
        return false;

    for(int i = 0; i<n; i++){ // verificam daca toate nodurile au maximum 2 noduri vecine
        int count=0;
        while(!adjList[i].empty())
            count++;
        if(count>2)
            return false;}

    std::vector<bool> visitedNodes(n);
    for(int i = 0; i<n; i++){
        visitedNodes[i] = false;
    }

    return DFS(x, visitedNodes, -1); // -1 va fi parintele radacinei
}

bool Graph::DFS(int x, std::vector<bool> visitedNodes, int parent) {
    visitedNodes[x] = true; // radacina e marcata
    int countChild=0;
    for (int neighbor : adjList[x]) { // verificam daca nodul are mai mult de 2 copii
        if (!visitedNodes[neighbor]) {
            countChild++;
            if (countChild > 2)
                return false;
            if (neighbor != parent) { // verificam daca vecinul nu este parintele ca sa evitam cicluri
                if (!DFS(neighbor, visitedNodes, x))
                    return false;
            }
        }
}
    if(countChild <=2)
        return true;
    else
        return false;}