#ifndef PHARMACY_REPOSITORY_H
#define PHARMACY_REPOSITORY_H
#include <iostream>
#include <list>
#include "../Domain/Medicine.h"

class Repository {
private:
    std::list<Medicine> container;
public:
    void add(Medicine medicine);
    void del(Medicine medicine);
    std::list<Medicine> getAll();
    void setAll(std::list<Medicine> list);
};


#endif //PHARMACY_REPOSITORY_H
