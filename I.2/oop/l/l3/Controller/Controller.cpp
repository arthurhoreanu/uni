#include "Controller.h"

///@param medicine
//Function for adding a medicine
void Controller::add(Medicine medicine) {
    repo.add(medicine);
}

///@param medicine
//Function for removing a medicine
void Controller::remove(Medicine medicine) {
    repo.del(medicine);
}

///@param name
//Function for searching for a medicine with a letter sequence
void Controller::getByName(std::string name) {
    std::list<Medicine> repository = repo.getAll();
    if (name == "~"){
        for(Medicine i: repository) {
            i.showProduct();
            cout << "\n";
        }
    }
    for(Medicine i: repository){
        if (i.getName() == name || i.getOrigin() == name){
            i.showProduct();
            cout << "\n";
        }
    }
}

//Function for sorting the medicine by their expiration date
void Controller::sortByExpirationDate() {
    std::list<Medicine> repository = repo.getAll();
    repository.sort(Medicine::compareByExp);
    for (Medicine i: repository){
        i.showProduct();
        cout << "\n";
    }
}

///@param quantity [in] quantity for finding the products that are insufficient
//Function which compares the quantity of all products with the one given and returns the ones who don't have enough
void Controller::showInsuficientProducts(int quantity) {
    std::list<Medicine> repository = repo.getAll();
    for (Medicine i: repository){
        if (i.getQuantity() < quantity){
            i.showProduct();
            cout << "\n";
        }
    }
}

///@param medicine [in] medicine
//Function that deals with the modification of a medicine
void Controller::modify(Medicine medicine){
    Medicine newMedicine = medicine;
    std::list<Medicine> listForModify = repo.getAll();
    std::list<Medicine> newListForModify;
    for (Medicine i: listForModify){
        if (i.getName() == medicine.getName() && i.getOrigin() == medicine.getOrigin()){
            newListForModify.push_back(newMedicine);
        } else {
            newListForModify.push_back(i);
        }
    }
    repo.setAll(newListForModify);
}

//Function that shows all medicine
void Controller::showAll() {
    std::list<Medicine> repository = repo.getAll();
    for (Medicine i: repository){
        i.showProduct();
        cout << "\n";
    }
}

//Function that shows first 10 medicine (used for menu)
void Controller::showFirstTenItems() {
    std::list<Medicine> repository = repo.getAll();
    int j = 0;
    for (Medicine i: repository){
        i.showProduct();
        cout << "\n";
        j++;
        if (j >= 10){
            break;
        }
    }
}