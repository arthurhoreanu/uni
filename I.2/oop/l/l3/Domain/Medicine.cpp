#include "Medicine.h"

///@param name
///@param origin
///@param expirationDate
///@param quantity
///@param price
//Constructor
Medicine::Medicine(std::string name, std::string origin, std::string expirationDate, int quantity, int price) {
    this->name = name;
    this->origin = origin;
    this->expirationDate = expirationDate;
    this->quantity = quantity;
    this->price = price;
}

//Getter for name
string Medicine::getName() {
    return name;
}

//Getter for origin
string Medicine::getOrigin() {
    return origin;
}

//Getter for price
int Medicine::getPrice() {
    return price;
}

//Getter for quantity
int Medicine::getQuantity() {
    return quantity;
}

//Getter for expiration date
string Medicine::getExpirationDate() {
    return expirationDate;
}

///@param q [in] new quantity
//Setter for quantity
void Medicine::setQuantity(int q) {
    quantity = q;
}

/**
 * setter for price
 * @param p
 */
void Medicine::setPrice(int p) {
    price = p;
}

///@param e [in] new expiration date
//Setter for expiration date
void Medicine::setExpDate(std::string e) {
    expirationDate = e;
}

///@param n [in] new name
//Setter for name
void Medicine::setName(std::string n) {
    name = n;
}

///@param o [in] new origin
//Setter for origin
void Medicine::setOrigin(std::string o) {
    origin = o;
}

//Function that shows the Product with all its info
void Medicine::showProduct() {
    std::cout << "Name: " << name << ", Origin: " << origin << ", Expiration Date: " << expirationDate << ", Quantity: " << quantity << ", Price: " << price;
}

///@param other
//Function used for the comparison of names
bool Medicine::operator<(Medicine &other) {
    return this->getName() < other.getName();
}

///@param Medicine1
///@param Medicine2
//Funtion used for the comparison of expiration dates
bool Medicine::compareByExp(Medicine Medicine1, Medicine Medicine2) {
    return Medicine1.getExpirationDate() < Medicine2.getExpirationDate();
}