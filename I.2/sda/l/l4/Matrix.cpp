#include "Matrix.h"
#include <exception>
#include <iostream>
using namespace std;

int Matrix::hashFunction(int line, int column) const
{
    return (line * columns + column) % table.m;
}

// Best, average and worst case: Theta(n)
Matrix::Matrix(int nrLines, int nrCols) {
    this->lines = nrLines;
    this->columns = nrCols;
    table.m = 111;
    table.size = 0;
    table.T = new Node * [table.m];
    for (int i = 0; i < table.m; ++i)
        table.T[i] = NULL_TELEM;
}

void Matrix::resize()
{
    int prevCapacity = table.m;
    table.m *= 2;
    Node** newHash = new Node * [table.m];
    for (int i = 0; i <table.m; i++)
        newHash[i] = NULL_TELEM;
    for (int i = 0; i < prevCapacity; i++)
    {
        Node* currentNode = table.T[i];
        while (currentNode != NULL_TELEM)
        {
            Node* next = currentNode->next;
            int pos = hashFunction(currentNode->line, currentNode->column);
            currentNode->next = newHash[pos];
            newHash[pos] = currentNode;
            currentNode = next;
        }
    }
    delete[] table.T;
    table.T = newHash;
}

// Best, average and worst case: Theta(1)
int Matrix::nrLines() const {
    return lines;
}

// Best, average and worst case: Theta(1)
int Matrix::nrColumns() const {
    return columns;
}

// Best, average and worst case: Theta(n)
TElem Matrix::element(int i, int j) const {
    if (i >= this->lines || j >= this->columns || i < 0 || j < 0) throw exception();
    for (int pos = 0; pos < table.m; ++pos)
    {
        Node* current = table.T[pos];
        while (current)
        {
            if (current->line == i && current->column == j) {
                return current->value; }
            current = current->next;
        }
    }
    return NULL_TELEM;
}

// Best, average and worst case: Theta(n), because we call the element method that also has Theta(n) best, average and worst case
TElem Matrix::modify(int i, int j, TElem e) {
    //BEST CASE: Θ(1)
    //AVERAGE CASE: Θ(n)
    //WORST CASE: Θ(n)
    //GESAMT: O(n)
    if (0 <= i && i < lines && 0 <= j && j < columns) {
        if (e == NULL_TELEM) {
            Node *current;
            Node *prev = nullptr;
            int pos = hashFunction(i, j);
            current = table.T[pos];
            while (current != nullptr) {
                if (current->line == i && current->column == j) {
                    //remove
                    TElem old = current->value;
                    if (prev != nullptr) {
                        prev->next = current->next;
                    } else {
                        table.T[pos] = current->next;
                    }
                    table.size--;
                    return old;
                }
                prev = current;
                current = current->next;
            }

            return NULL_TELEM;
        } else {
            Node *current;
            int pos = hashFunction(i, j);

            current = table.T[pos];
            while (current != nullptr) {
                if (current->line == i && current->column == j) {
                    //modify
                    TElem old = current->value;
                    current->value = e;
                    return old;

                }
                current = current->next;
            }

            //add
            if (table.size > 2 * table.m) {
                resize();
            }
            Node *newNode = new Node;
            newNode->value = e;
            newNode->column = j;
            newNode->line = i;
            newNode->next = table.T[pos];
            table.T[pos] = newNode;
            table.size++;
            return NULL_TELEM;
        }
    } else {
        throw exception();
    }
}

// Best, average and worst case: Theta(n), n is nrLines * nrCols
Matrix::~Matrix() {
    for (int i = 0; i < table.m; i++) {
        Node* current = table.T[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] table.T;
}