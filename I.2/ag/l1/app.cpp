#include "Graph.h"
#include "newGraph.h"
#include<iostream>
#include <fstream>

using namespace std;

int main(){
    Graph g;
    g.printGraph();
    g.isEdge(0,1);
    g.convertToAdjList();
    g.printAdjList();
    g.calculateMaxDegree();
    g.calculateMinDegree();
    g.minAndMax();
    newGraph h;
    h.printNewAdjList();
    h.calculateNewMinDegree();
    h.calculateNewMaxDegree();
    h.newMinAndMax();
    return 0;
}