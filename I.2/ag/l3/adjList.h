#include <vector>
#include <string>
#include <map>

class AdjList {
private:
    int n;
    int m;
    std::vector<int> adjList[100];
    std::map<int, bool> visited;

public:
    AdjList();
    AdjList(std::string filename);
    void addEdge(int x, int y);
    void printGraph();
    void BFS(int start);
    void DFS(int start);

};


#endif //AGEXERSARE_ADJLIST_H
