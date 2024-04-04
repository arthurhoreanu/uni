#include "L2_dsm.h"
#include <vector>
#include <exception>
using namespace std;

//Constructor 1 (with int elementCount)
DSM::DSM(int elementCount) : elementCount(elementCount), elementNames(elementCount), matrix(elementCount, std::vector<float>(elementCount, 0.0f)) {}

//Constructor 2 (with vector<string> elementNames)
DSM::DSM(std::vector<std::string> elementNames) : elementCount(elementNames.size()), elementNames(elementNames), matrix(elementNames.size(), std::vector<float>(elementNames.size(), 0.0f)) {}

//Copy-Constructor
DSM::DSM(const DSM& other) : elementCount(other.elementCount), elementNames(other.elementNames), matrix(other.matrix) {}

//Function for the size of the matrix
int DSM::size(){
    return elementNames.size();
}

//Function for obtaining the name of an element
//If the id is not valid, throw exception
string DSM::getName(int id) {
    if (id < 0 || id >= size()) {
        throw exception();
    }
    return elementNames[id];
}

//Function for setting the name of an element
//If the id is not valid, throw exception
void DSM::setElementName(int index, string name) {
    if (index < 0 || index >= size()) {
        throw exception();
    }
    elementNames[index] = name;
}

//Method for adding a link between two elements
//We check to see if the link exist. If not, we add it and we also add its weight. If it does, we update the weight
void DSM::addLink(string fromElement, string toElement, float weight) {
    int elementOneId = -1, elementTwoId = -1;
    for (int i = 0; i < size(); i++) {
        if (elementNames[i] == fromElement) {
            elementOneId = i;
        }
        if (elementNames[i] == toElement) {
            elementTwoId = i;
        }
    }
    if (elementOneId != -1 && elementTwoId != -1) {
        matrix[elementOneId][elementTwoId] = weight;
    }
}

//Method for deleting a link between two elements
//We check to see if the link exist. If yes, we delete it
void DSM::deleteLink(string fromElement, string toElement) {
    int elementOneId = -1, elementTwoId = -1;
    for (int i = 0; i < size(); i++) {
        if (elementNames[i] == fromElement) {
            elementOneId = i;
        }
        if (elementNames[i] == toElement) {
            elementTwoId = i;
        }
    }
    if (elementOneId != -1 && elementTwoId != -1) {
        matrix[elementOneId][elementTwoId] = 0.0f;
    }
}

//Method for checking if there is a link between two elements
bool DSM::haveLink(string fromElement, string toElement) {
    int elementOneId = -1, elementTwoId = -1;
    for (int i = 0; i < size(); i++) {
        if (elementNames[i] == fromElement) {
            elementOneId = i;
        }
        if (elementNames[i] == toElement) {
            elementTwoId = i;
        }
    }
    if (elementOneId != -1 && elementTwoId != -1) {
        return matrix[elementOneId][elementTwoId] != 0.0f;
    }
    return false;
}

//Method for obtaining the weight of a link between two elements
//We check to see if the link exist. If yes, we return the weight
float DSM::linkWeight(string fromElement, string toElement) {
    int elementOneId = -1, elementTwoId = -1;
    for (int i = 0; i < size(); i++) {
        if (elementNames[i] == fromElement) {
            elementOneId = i;
        }
        if (elementNames[i] == toElement) {
            elementTwoId = i;
        }
    }
    if (elementOneId != -1 && elementTwoId != -1) {
        return matrix[elementOneId][elementTwoId];
    }
    return 0.0f;
}

//Function to count all links
int DSM::countAllLinks() {
    int cnt = 0;
    for (int i = 0; i < size(); ++i) {
        for (int j = 0; j < size(); ++j) {
            if (matrix[i][j] != 0.0f) {
                cnt++;
            }
        }
    }
    return 0;
}

//Function to count all links from an element
//We check to see if a link exist. If yes, we raise the counter
int DSM::countToLinks(string elementName) {
    int id = -1;
    for (int i = 0; i < size(); i++) {
        if (elementNames[i] == elementName) {
            id = i;
        }
    }
    if (id != -1) {
        int cnt = 0;
        for (int i = 0; i < size(); i++) {
            if (matrix[i][id] != 0.0f) {
                cnt++;
            }
        }
        return cnt;
    }
    return 0;
}

//Function to count all links to an element
//We check to see if a link exist. If yes, we raise the counter
int DSM::countFromLinks(string elementName) {
    int id = -1;
    for (int i = 0; i < size(); i++) {
        if (elementNames[i] == elementName) {
            id = i;
        }
    }
    if (id != -1) {
        int cnt = 0;
        for (int i = 0; i < size(); i++) {
            if (matrix[id][i] != 0.0f) {
                cnt++;
            }
        }
        return cnt;
    }
    return 0;
}

//Destructor
DSM::~DSM() {
    for(int i = 0; i < elementCount; i++)
        matrix.clear();}
