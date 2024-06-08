#include "Admin.h"

// Constructor
Admin::Admin(std::string name, std::string surname, std::string email, std::string password, std::string position, std::string birthdate,
             std::string abbreviation, float salary, std::string remarks)
        : Employee(name, surname, email, password, position, birthdate, abbreviation, salary, remarks) {}

//getters
std::string Admin::getName() {
    return this->name;
}

std::string Admin::getSurname() {
    return this->surname;
}

std::string Admin::getEmail() {
    return this->email;
}

std::string Admin::getAbbreviation() {
    return this->abbreviation;
}

std::string Admin::getRemarks() {
    return this->remarks;
}

std::string Admin::getBirthdate() {
    return this->birthdate;
}

float Admin::getSalary() {
    return salary;
}

std::string Admin::getPosition() {
    return this->position;
}

//setters
void Admin::setName(std::string newName) {
    this->name = newName;
}

void Admin::setSurname(std::string newSurname) {
    this->surname = newSurname;
}

void Admin::setEmail(std::string newEmail) {
    this->email = newEmail;
}

void Admin::setPosition(std::string newPosition) {
    this->position = newPosition;
}

void Admin::setBirthdate(std::string newBirthdate) {
    this->birthdate = newBirthdate;
}

void Admin::setAbbreviation(std::string newAbbreviation) {
    this->abbreviation = newAbbreviation;
}

void Admin::setSalary(float newSalary) {
    this->salary = newSalary;
}

void Admin::setRemarks(std::string newRemarks) {
    this->remarks = newRemarks;
}