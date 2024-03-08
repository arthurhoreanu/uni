#include "Document.h"

int myVar;

// int add(int a, int b) {
//     return a + b;
// }

std::string Document::getTitle() {
    return this->title;
}

void Document::setTitle(std::string title) {
    this->title = title;
}

void Document::readTitle() {
    std::cin >> this->title;
}

void Document::copyTitles(std::string &newTitle) {
    newTitle = this->title;
}