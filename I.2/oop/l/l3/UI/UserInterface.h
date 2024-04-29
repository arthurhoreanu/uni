#ifndef FRUITAPP_USERINTERFACE_H
#define FRUITAPP_USERINTERFACE_H
#include "../Controller/Controller.h"
#include "../Repository/Repository.h"

class UserInterface {
    Controller action;
public:
    void menu();
    void showMenu();
    void showFirstTenItems();
    void showCRUDOptions();
//    void addNewFruit(Medicine Medicine, string name, string origin, string exdate, int quantity, int price);
    void populateData(Controller &action) const;

    void removeFruit();

    void addFruit();
};


#endif //FRUITAPP_USERINTERFACE_H
