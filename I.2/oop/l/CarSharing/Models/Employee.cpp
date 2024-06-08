//
// Created by scoti on 22.05.2024.
//

#include <iomanip>
#include "Employee.h"
#include "sstream"
#include<stdexcept>


Employee::Employee(std::string name, std::string surname, std::string email, std::string password,std::string position,  std::string birthdate,
                   std::string abbreviation, float salary, std::string remarks) {

    this->name = name;
    this->surname = surname;
    this->email = email;
    this->password = password;
    this->position = position;
    this->birthdate = birthdate;
    this->abbreviation = abbreviation;
    this->salary = salary;
    this->remarks = remarks;
    this->admin = false;
}

Employee::Employee() : admin(false){}

//getters

std::string Employee::getName() const {
    return this->name;
}

std::string Employee::getSurname() const{
    return this->surname;
}

std::string Employee::getEmail() const{
    return this->email;
}

std::string Employee::getPassword() const{
    return this->password;
}

std::string Employee::getAbbreviation() const{
    return this->abbreviation;
}

std::string Employee::getRemarks() const{
    return this->remarks;
}

std::string Employee::getBirthdate() const{
    return this->birthdate;
}

float Employee::getSalary() const{
    return salary;
}

std::string Employee::getPosition() const {
    return this->position;
}

bool Employee::isAdmin() {
    return admin;
}

//setters

void Employee::setName(std::string newName) {
    this->name = newName;
}

void Employee::setSurname(std::string newSurname) {
    this->surname = newSurname;
}

void Employee::setEmail(std::string newEmail) {
    this->email = newEmail;
}

void Employee::setPosition(std::string newPosition) {
    this->position = newPosition;
}

void Employee::setBirthdate( std::string newBirthdate) {
    this->birthdate = newBirthdate;
}

void Employee::setAbbreviation(std::string newAbbreviation) {
    this->abbreviation = newAbbreviation;
}

void Employee::setSalary(float newSalary) {
    this->salary = newSalary;
}

void Employee::setRemarks(std::string newRemarks) {
    this->remarks = newRemarks;
}

//an Employee should only be able to update his--> remarks and password
void Employee::updateProfile() {

}

void Employee::setAdmin(bool adminStatus) {
    admin = adminStatus;
}
std::string Employee::toString(){
    std::ostringstream oss;
    oss << "Name: " << name << "\n"
        << "Surname: " << surname << "\n"
        << "Email: " << email << "\n"
        << "Position: " << position << "\n"
        << "Birthdate: " << birthdate << "\n"
        << "Abbreviation: " << abbreviation << "\n"
        << "Salary: " << salary << "\n"
        << "Remarks: " << remarks;
    return oss.str();
}





