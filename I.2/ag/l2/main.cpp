#include <iostream>
#include "Graph.h"

int main() {
    Graph graph("graph.in");
    std::cout << "Input matrix: " << std::endl;
    graph.printGraph();
    std::cout << std::endl;
    std::cout << "Matrix^2: " << std::endl;
    std::vector<std::vector<int>> powerGraph = graph.power(2);
    graph.printPowerGraph(powerGraph);
    std::cout << std::endl;
    std::cout << "Is the graph connected? ";
    if(graph.isConnected()==1)
        std::cout << "YES";
    else
        std::cout << "NO";
    return 0;
}
