#ifndef PHARMACY_MEDICINE_H
#define PHARMACY_MEDICINE_H
#include <string>
#include <iostream>
using namespace std;

class Medicine {
private:
    string name;
    string origin;
    string expirationDate;
    int quantity;
    int price;
public:
    Medicine(string name, string origin, string expirationDate, int quantity, int price);
    string getName();
    int getPrice();
    string getOrigin();
    string getExpirationDate();
    int getQuantity();
    void setPrice(int p);
    void setQuantity(int q);
    void setOrigin(string o);
    void setName(string n);
    void setExpDate(string e);
    void showProduct();
    bool operator< (Medicine &other);
    static bool compareByExp(Medicine Medicine1, Medicine Medicine2);
};


#endif //PHARMACY_MEDICINE_H
