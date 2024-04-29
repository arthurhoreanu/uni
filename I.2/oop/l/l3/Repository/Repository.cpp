#include "Repository.h"

///@param medicine
//Function used for adding a new medicine to the repo
//First it checks to see if the medicine exists already
//If it does exist, it raises the quantity, if not, the medicine is added
void Repository::add(Medicine medicine) {
    int a = 0;
    for (Medicine i: container){
        if (i.getName() == medicine.getName() && i.getOrigin() == medicine.getOrigin()){
            a = 1;
        }
    }
    if (a == 0){
        container.push_back(medicine);
    } else {
        std::list<Medicine> newList;
        for (Medicine i: container){
            if (i.getName() != medicine.getName() || i.getOrigin() != medicine.getOrigin()){
            newList.push_back(i);
            } else {
                i.setQuantity(i.getQuantity() + 1);
                newList.push_back(i);
            }
        }
        container = newList;
    }
}

///@param medicine
//Function that deletes a medicine if it exists already
void Repository::del(Medicine medicine) {
    std::list<Medicine> newContainer;
    for (Medicine i: container){
        if (i.getName() != medicine.getName() || i.getOrigin() != medicine.getOrigin()){
            newContainer.push_back(i);
        }
    }
    container = newContainer;
}

//Function that returns the content of the container
std::list<Medicine> Repository::getAll() {
    return container;
}

///@param list [in] list with Medicine for modifying
//Function that sets the content of the container
void Repository::setAll(std::list<Medicine> list) {
    container = list;
}