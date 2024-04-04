#ifndef L2_DSM_H
#define L2_DSM_H
#include <vector>
#include <string>

using namespace std;

class DSM {
private:
    int elementCount; //the number of elements
    vector<string> elementNames; //the names of the elements
    vector<vector<float>> matrix; //the matrix with the links between the elements
public:
    DSM(int elementCount);
    DSM(vector<string> elementNames);
    int size();
    string getName(int id);
    void setElementName(int index, string name);
    void addLink(string fromElement, string toElement, float weight);
    void deleteLink(string fromElement, string toElement);
    bool haveLink(string fromElement, string toElement);
    float linkWeight(string fromElement, string toElement);
    int countToLinks(string elementName);
    int countFromLinks(string elementName);
    int countAllLinks();
    DSM(const DSM& other);
    ~DSM();
};

#endif //L2_DSM_H