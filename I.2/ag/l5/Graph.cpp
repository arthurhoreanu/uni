#include "Graph.h"
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

Graph::Graph(const std::string& filename) {
    ifstream f(filename);
    if (!f) {
        cerr << "Error opening file" << endl;
    }
    f >> n >> m;
    edgeList = nullptr;

    int node1, node2;
    for (int i = 0; i < m; ++i) {
        f >> node1 >> node2;
        insertEdge(edgeList, node1, node2);
        insertEdge(edgeList, node2, node1);
    }
}

void Graph::insertEdge(Edge*& head, int node1, int node2) {
    Edge* newNode = new Edge{node1, node2, head};
    head = newNode;
}

void Graph::print() {
    Edge* current = edgeList;
    while (current != nullptr) {
        cout << "(" << current->node1 << ", " << current->node2 << ")\n";
        current = current->next;
    }
}

void Graph::BFS(vector<int>& order) {
    vector<bool> visited(n, false);
    queue<int> q;
    int startNode = 0;

    visited[startNode] = true;
    q.push(startNode);
    order.push_back(startNode);

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        for (Edge* current = edgeList; current != nullptr; current = current->next) {
            if (current->node1 == currentNode && !visited[current->node2]) {
                visited[current->node2] = true;
                q.push(current->node2);
                order.push_back(current->node2);
            }
            else if (current->node2 == currentNode && !visited[current->node1]) {
                visited[current->node1] = true;
                q.push(current->node1);
                order.push_back(current->node1);
            }
        }
    }
}

void Graph::improvedColoring() {
    vector<int> order;
    BFS(order);
    vector<int> color(n, 0);
    color[order[0]] = 1;

    for (int i = 1; i < n; i++) {
        vector<bool> used(n, false);
        used[color[order[i - 1]]] = true;

        int minColor = 1;
        for (Edge* current = edgeList; current != nullptr; current = current->next) {
            if (current->node1 == order[i] || current->node2 == order[i]) {
                if(current->node1 == order[i]) {
                    int neighbor = current->node2;
                    used[color[neighbor]] = true; }
                else {
                    int neighbor = current->node1;
                    used[color[neighbor]] = true; }
            }
        }

        for (int j = 0; j <= n; j++) {
            if (!used[minColor]) {
                color[order[i]] = minColor;
                break;
            }
            minColor++;
        }

        if (minColor > n) {
            std::cout << "Error: Graph requires more than " << n << " colors for proper coloring." << endl;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "Node " << order[i] << ": Color " << color[order[i]] << endl;
    }
}