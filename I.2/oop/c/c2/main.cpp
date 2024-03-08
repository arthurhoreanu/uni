// pipeline --> first step: preprocessor (--> #include <iostream> where #incluce copies the whole dictionary iostream)
#include <iostream>
#include "Document.h"
#include "Document.h"

using namespace std;


int main() {
    Document d;
    d.readTitle();
    cout << "You provided " << d.getTitle() << " with length " << d.getTitle().length() << endl;
    
    string anotherTitle;
    d.copyTitles(anotherTitle);
    cout << "The new title is " << anotherTitle;
    return 0;
}

// API --> Application Programming Interface
// public --> EVERYBODY sees it
// private --> ONLY classes see it (by default is EVERYTHING private)
// protected --> for Inheritances
// ein Kontruktor ist ein spezieller Funktion, die initialisiert die Instancen