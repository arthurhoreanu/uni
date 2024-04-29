#ifndef PHARMACY_CONTROLLER_H
#define PHARMACY_CONTROLLER_H
#include "../Domain/Medicine.h";
#include "../Repository/Repository.h"
class Controller {
private:
    Repository repo;
public:
    void add(Medicine medicine);
    void remove(Medicine medicine);
    void getByName(std::string name);
    void modify(Medicine medicine);
    void sortByExpirationDate();
    void showInsuficientProducts(int quantity);
    void showAll();
    void showFirstTenItems();

};


#endif //PHARMACY_CONTROLLER_H
