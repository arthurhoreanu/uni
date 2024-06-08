//
// Created by Robert on 5/22/2024.
//

#include "User.h"
#include "sstream"

User::User(int id, std::string email, std::string password, std::string firstName, std::string lastName) {
    this->id = id;
    this->email = email;
    this->password = password;
    this->firstName = firstName;
    this->lastName = lastName;
}

std::string User::getUserFirstName() const {
    return this->firstName;
}

std::string User::getUserEmail() const {
    return this->email;
}

std::string User::getUserLastName() const {
    return this->lastName;
}

std::string User::getUserPassword() const {
    return this->password;
}

int User::getUserId() const {
    return this->id;
}

void User::setUserFirstName(std::string newFirstName) {
    this->firstName = newFirstName;
}

void User::setUserLastName(std::string newLastName) {
    this->lastName = newLastName;
}

void User::setUserEmail(std::string newEmail) {
    this->email = newEmail;
}

void User::setUserPassword(std::string newPassword) {
    this->password = newPassword;
}



std::string User::inputEmail() {
    std::string email;
    std::cout<<"Enter email";
    std::cin>>email;
    return email;
}

std::string User::inputPassword() {
    std::string password;
    std::cout<<"Enter password";
    std::cin>>password;
    return password;
}


int User::login() {
    CustomerHandlingRepository customerRepo("Customers.csv");
    EmployeeRepository emplyeeRepo("acum.csv");
    std::string email = inputEmail();
    std::string password = inputPassword();
    customerRepo.readFromCsv();
    emplyeeRepo.readFromCsv();

    std::vector<Customer> customers = customerRepo.geterCustomers();
    std::vector<Employee> employes = emplyeeRepo.getEmployes();
    std::cout<<employes[0].getPassword();


    int userType = -1;

    for(int i = 0; i<customers.size();i++)
        if(email == customers[i].getEmail() && password == customers[i].getPassword()){
            std::cout<<"You're logged in as a Customer";
            userType = 1;
            return userType;
        }
    for(int i = 0; i<employes.size();i++)
        if(email == employes[i].getEmail() && password == employes[i].getPassword()){
            std::cout<<"You're an Employee"<<"\n";
            if (employes[i].getPosition() == "Admin") {
                userType = 3;
                return userType;
            }

            userType = 2;
            return userType;
        }

    std::cout<<"Email or Password wrong!";
    //return login();

}

User::User() {}
