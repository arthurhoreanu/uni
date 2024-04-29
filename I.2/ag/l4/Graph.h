#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Edge {
    int node1;
    int node2;
    Edge* next;
    Edge(int n1, int n2) : node1(n1), node2(n2), next(nullptr) {}
};

class Graph {
private:
    int Knoten; // Numărul de noduri
    int Kanten; // Numărul de muchii
    vector<Edge> kantenListe; // Lista de muchii

public:
    Graph(const string& filename);
    void addEdge(int Knote1, int Knote2);
    void kantenzug();
};