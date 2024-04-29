#include "UserInterface.h"
#include <string>

//Shows menu for CRUD options
void UserInterface::showCRUDOptions() {
    cout << "Choose an option:\n"
            "1. ADD a product\n"
            "2. REMOVE a product\n"
            "3. MODIFY a product\n"
            "4. See ALL products\n";
}

//Shows start menu
void UserInterface::showMenu() {
    cout << "Choose an option:\n"
            "1. ADD, REMOVE or MODIFY a product\n"
            "2. Search for a product\n"
            "3. Look for current products with smaller quantity than needed\n"
            "4. See current products sorted by their expiration date\n";
}

//Function that deals with the behavior of the app regarding the choice
void UserInterface::menu() {
    populateData(action);

    int choice = 0;
    while (choice != 9){
        showMenu();
        std::cin >> choice;
        if (choice == 1){
            int choice2 = 0;
            showCRUDOptions();
            cin >> choice2;
            if (choice2 == 1){
                addFruit();
            }
            if (choice2 == 2){
                removeFruit();
            }
            if (choice2 == 3){
                string name;
                string origin;
                string expDate;
                int quantity;
                int price;
                Medicine fr = Medicine("Name", "Origin", "ExDate", 0, 0);
                cin >> name;
                fr.setName(name);
                cin >> origin;
                fr.setOrigin(origin);
                cin >> expDate;
                fr.setExpDate(expDate);
                cin >> quantity;
                fr.setQuantity(quantity);
                cin >> price;
                fr.setPrice(price);
//                addNewFruit(fr);
                action.modify(fr);
            }
            if (choice2 == 4){
                action.showAll();
            }
        }
        if (choice == 2){
            string name;
            cin >> name;
            action.getByName(name);
        }
        if (choice == 3){
            int quantity;
            cin >> quantity;
            action.showInsuficientProducts(quantity);
        }
        if (choice == 4){
            action.sortByExpirationDate();
        }
    }

}

void UserInterface::addFruit() {
    string name;
    string origin;
    string expDate;
    int quantity;
    int price;
    Medicine fr = Medicine("Name", "Origin", "ExDate", 0, 0);
    cin >> name;
    fr.setName(name);
    cin >> origin;
    fr.setOrigin(origin);
    cin >> expDate;
    fr.setExpDate(expDate);
    cin >> quantity;
    fr.setQuantity(quantity);
    cin >> price;
    fr.setPrice(price);
    action.add(fr);
}

void UserInterface::removeFruit() {
    string name;
    string origin;
    string expDate;
    int quantity;
    int price;
    Medicine fr = Medicine("Name", "Origin", "ExDate", 0, 0);
    cin >> name;
    fr.setName(name);
    cin >> origin;
    fr.setOrigin(origin);
    cin >> expDate;
    fr.setExpDate(expDate);
    cin >> quantity;
    fr.setQuantity(quantity);
    cin >> price;
    fr.setPrice(price);
//                addNewFruit(fr);
    action.remove(fr);
}

void UserInterface::populateData(Controller &action) const {
    Medicine m1 = Medicine("Aspenter", "Terapia", "2025", 4, 15);
    Medicine m2 = Medicine("Aspirin", "Bayer", "2024", 15, 16.49);
    Medicine m3 = Medicine("Biofen", "Biofarm", "2025", 20, 11.99);
    action.add(m1);
    action.add(m2);
    action.add(m3);
    action.showFirstTenItems();
}
