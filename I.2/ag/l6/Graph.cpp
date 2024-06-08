//
// Created by Arthur Horeanu on 07.06.2024.
//

#include "Graph.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

Graph::Graph(std::string filename) {
    ifstream f;
    f.open(filename);
    f >> n >> m;
    f >> s >> t;

    int x, y, cap, fl;
    for (int i = 0; i < m; i++) {
        f >> x >> y >> cap >> fl;
        capacity[x][y] = cap;
        flow[x][y] = fl;
    }
    f.close();
}

bool Graph::isValid() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (flow[i][j] > capacity[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool Graph::BFS(int source, int sink, std::vector<int>& parent) {
    std::vector<bool> visited(n, false);
    std::queue<int> queue;
    queue.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();

        for (int v = 0; v < n; v++) {
            if (!visited[v] && capacity[u][v] - flow[u][v] > 0) {
                queue.push(v);
                visited[v] = true;
                parent[v] = u;

                // If we reach the sink, the BFS is correct
                if (v == sink) {
                    return true;
                }
            }
        }
    }
    return false; // No path found
}

/*
void Graph::edmondsKarp(int source, int sink) {
    int maxFlow = 0;
    while (BFS(source, sink, parent)) {
}
 */