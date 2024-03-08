#ifndef C2_MYSTRING_H
#define C2_MYSTRING_H


class MyString {
private:
    char* internalString;
    int length;

public:
    char* toCharArray();
    int getLength();
    MyString& concat(char* other);
};


#endif //C2_MYSTRING_H
