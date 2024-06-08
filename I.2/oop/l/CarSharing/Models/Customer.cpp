//
// Created by demku on 5/22/2024.
//

#include "Customer.h"
#include "sstream"
#include <iostream>
#include <vector>

Customer:: Customer(std::string name, std::string surname, std::string customerEmail, std::string password,
                    std::string address, std::string remarks,std::string phone, bool gdprDeleted){
    this->name = name;
    this->surname = surname;
    this->customerEmail = customerEmail;
    this->password = password;
    this->address = address;
    this->remarks = remarks;
    this->phone = phone;
    this->gdprDeleted = gdprDeleted;



}
//default constructor?
Customer::Customer() {
    this->name = "";
    this->surname = "";
    this->phone = "";
    this->customerEmail = "";
    this->password = "";
    this->address = "";
    this->remarks = "";
    this->gdprDeleted = false;
    //this->favoriteCars = "";
}

std::string Customer::getName () const {
    return name;
}

std::string Customer::getSurname() const {
    return surname;
}

std::string Customer::getPhone() const{
    return phone;
}

std::string Customer::getAddress()const {
    return address;
}

std::string Customer::getRemarks() const{
    return remarks;
}

bool Customer::getGdprDeleted()const {
    return gdprDeleted;
}

std::string Customer::getPassword() const {
    return password;
}

std::vector<std::string> Customer::getFavoriteCars() const {
    return favoriteCars;
}

void Customer::setPassword(std::string newPassword) {
    this->password=newPassword;
}

void Customer::setFavoriteCars(std::vector<std::string> newFavoriteCars) {
    this->favoriteCars=newFavoriteCars;
}

void Customer::setName(std::string newName) {
    this->name = newName;
}

void Customer::setSurname(std::string newSurname) {
    this->surname = newSurname;
}

void Customer::setPhone(std::string newPhone) {
    this->phone = newPhone;
}

void Customer::setAddress(std::string newAddress) {
    this->address = newAddress;
}

void Customer::setRemarks(std::string newRemarks) {
    this->remarks = newRemarks;
}

void Customer::setGdprDeleted(bool newGdprDeleted) {
    this->gdprDeleted = newGdprDeleted;
}

std::string Customer::getEmail() const {
    return this->customerEmail;
}

std::string Customer::toString(){
    std::ostringstream oss;
    oss << "Name: " << name << "\n"
        << "Surname: " << surname << "\n"
        << "Phone: " << phone << "\n"
        << "Email: " << customerEmail << "\n"
        << "Password" << password << "\n"
        << "Address: " << address << "\n"
        << "Remarks: " << remarks << "\n"
        << "GDPR Deleted: " << (gdprDeleted ? "Yes" : "No") << "\n"
        << "Favorite Cars: ";
    for (const auto &car : favoriteCars) {
        oss << car << " ";
    }
    return oss.str();
}



