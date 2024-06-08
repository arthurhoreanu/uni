#include "Matrix.h"
#include <exception>
#include <iostream>
using namespace std;

// Best, average and worst case: Theta(1)
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

// Best, average and worst case: Theta(n)
void Matrix::resize()
{
    int prevCapacity = table.m;
    table.m *= 2;
    Node** newHash = new Node * [table.m];
    for (int i = 0; i < table.m; i++)
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

// Best, average and worst case: Theta(n)
TElem Matrix::modify(int i, int j, TElem e) {
    if (0 <= i && i < lines && 0 <= j && j < columns) {
        if (e == NULL_TELEM) { //We remove this element
            Node *current;
            Node *prev = NULL_TELEM;
            int pos = hashFunction(i, j);
            current = table.T[pos];
            while (current != NULL_TELEM) {
                if (current->line == i && current->column == j) {
                    TElem old = current->value;
                    if (prev != NULL_TELEM) {
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
            while (current != NULL_TELEM) { // We modify the value
                if (current->line == i && current->column == j) {
                    TElem old = current->value;
                    current->value = e;
                    return old;
                }
                current = current->next;
            }
            if (table.size > 2 * table.m) {
                resize();
            }
            // We add a new value
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

// Best, average and worst case: Theta(n)
Matrix::~Matrix() {
    for (int i = 0; i < table.m; i++) {
        Node* current = table.T[i];
        while (current != NULL_TELEM) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] table.T;
}

// Best, average and worst case: Theta(n)
void Matrix::newDimension(int newLines, int newColumns) {
    if (newLines <= 0 || newColumns <= 0)
        throw exception();

    hashTable temporaryTable;
    temporaryTable.m = 10;
    temporaryTable.size = 0;
    temporaryTable.T = new Node*[temporaryTable.m];
    for (int i = 0; i < temporaryTable.m; i++) {
        temporaryTable.T[i] = NULL_TELEM;
    }

    // We iterate through already existing elements and rehash them into the temporary table
    for (int i = 0; i < lines; i++) {
        for (Node* current = table.T[i]; current != NULL_TELEM;) {
            Node* next = current->next;
            int newHash = hashFunction(current->line, current->column);
            current->next = temporaryTable.T[newHash];
            temporaryTable.T[newHash] = current;
            current = next;
        }
    }

    // We deallocate memory for the old hash table
    for (int i = 0; i < table.m; i++) {
        delete[] table.T[i];
    }
    delete[] table.T;

    // We update matrix dimensions and allocate memory for the new hash table
    lines = newLines;
    columns = newColumns;
    table.m = 10;
    table.size = 0;
    table.T = new Node*[table.m];
    for (int i = 0; i < table.m; i++) {
        table.T[i] = NULL_TELEM;
    }

    // We move the elements from the temporary table back to the resized matrix
    for (int i = 0; i < temporaryTable.m; i++) {
        for (Node* current = temporaryTable.T[i]; current != NULL_TELEM;) {
            Node* next = current->next;
            int newHash = hashFunction(current->line, current->column);
            current->next = table.T[newHash];
            table.T[newHash] = current;
            current = next;
        }
    }
}

// Helper method to print the new Matrix
// Best, average and worst case: Theta(n^2)
void Matrix::printMatrix() {
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            TElem value = element(i, j);
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}