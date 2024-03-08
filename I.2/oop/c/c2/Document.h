#include <string>
#include <iostream>

#ifndef curs_2_Document_h
#define curs_2_Document_h

extern int myVar;

// int add(int a, int b);
//     // add declarations

class Document {
    private:
        std::string title;
        std::string content;

    public:
        std::string getTitle();
        void setTitle(std::string title);
        void readTitle();
        void copyTitles(std::string &newTitle);
};

#endif