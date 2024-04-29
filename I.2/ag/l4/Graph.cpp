#include "Graph.h"
#include <stack>

Graph::Graph(const string& filename) {
    ifstream file(filename);
    int node1, node2;
    file >> Knoten >> Kanten;
    while (file >> node1 >> node2) {
        addEdge(node1, node2);
        addEdge(node2, node1);
    }
    file.close();
}

void Graph::addEdge(int node1, int node2) {
    Edge newEdge(node1, node2);
    kantenListe.push_back(newEdge);
}

void Graph::kantenzug() {
    vector<bool> visited(Knoten, false);
    stack<int> currentPfad;
    int startKnote = 0;

    currentPfad.push(startKnote);
    visited[startKnote] = true;

    while (!currentPfad.empty()) {
        int currentKnote = currentPfad.top();

        // cautam vecini nevizitati
        int nextKnote = -1;
        for (const Edge& edge : kantenListe) {
            if (edge.node1 == currentKnote && !visited[edge.node2]) {
                nextKnote = edge.node2;
                break;
            } else if (edge.node2 == currentKnote && !visited[edge.node1]) {
                nextKnote = edge.node1;
                break;
            }
        }

        // daca gasim, ii adaugam la drum si ii marcam ca vizitati
        if (nextKnote != -1) {
            currentPfad.push(nextKnote);
            visited[nextKnote] = true;
        } else {
            if (currentKnote == startKnote && currentPfad.size() > 2) {
                cout << "Eulershen Kantenzug: ";
            }
        }
    }

    cout << "Kein eulerschen Kantenzug." << endl;
}