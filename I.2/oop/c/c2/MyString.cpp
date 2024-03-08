#include "MyString.h"

char *MyString::toCharArray() {
    return length;
}

MyString &MyString::concat(char *other) {
    // todo
    length = length + strlen(other);

}
