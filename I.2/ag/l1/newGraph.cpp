#include "newGraph.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

newGraph::newGraph(){
    ifstream f;
    f.open("data.in");
    f >> n;
    newAdjList.resize(n);
    f >> m;
    int x,y;
    for(int i=0; i<m; i++){
        f>>x>>y;
        newAdjList[x].push_back(y);
        newAdjList[y].push_back(x);
    }
}

void newGraph::printNewAdjList() {
    cout << "[";
    for (int i = 0; i < newAdjList.size(); i++) {
        cout << "<";
        for (int neighbor : newAdjList[i]) {
            cout << neighbor << " ";
        }
        cout << ">";
        if (i < newAdjList.size() - 1) {
            cout << ",";
        }
    }
    cout << "]";
}


int newGraph::calculateNewMinDegree() {
    minDegree = INT_MAX;
    for (int i = 0; i < n; i++) {
        int degree = 0;
        for (auto neighbour : newAdjList[i]) {
            degree++;
        }
        minDegree = min(minDegree, degree);
    }
    return minDegree;
}

int newGraph::calculateNewMaxDegree() {
    maxDegree = INT_MIN;
    for (int i = 0; i < n; i++) {
        int degree = 0;
        for (auto neighbour : newAdjList[i]) {
            degree++;
        }
        maxDegree = max(maxDegree, degree);
    }
    return maxDegree;
}

void newGraph::newMinAndMax(){
    cout << endl;
    cout<<"Max: " << maxDegree<<endl;
    cout<<"Min: " << minDegree<<endl;
}