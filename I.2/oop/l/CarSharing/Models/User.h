//
// Created by Robert on 5/22/2024.
//

#ifndef CARSHARINGFINAL_USER_H
#define CARSHARINGFINAL_USER_H
#include <string>
#include "../Repository/CustomerHandlingRepository.h"
#include "../Repository/EmployeeRepository.h"
#include "../Models/Customer.h"
#include "../Models/Employee.h"


class User {
private:
    int id;
    std::string email;
    std::string password;
    std::string firstName;
    std::string lastName;

public:
    User(int id, std::string email, std::string password, std::string firstName, std::string lastName);
    User();

    //functie care returneaza true daca te ai logat corect Ppoate de mutat in controller
    int login();

    std::string getUserEmail() const;
    std::string getUserPassword() const;
    std::string getUserFirstName() const;
    std::string getUserLastName() const;
    int getUserId() const;

    void setUserFirstName(std::string newFirstName);
    void setUserLastName(std::string newLastName);
    void setUserPassword(std::string newPassword);
    void setUserEmail(std::string newEmail);

    std::string inputEmail();

    std::string inputPassword();





};


#endif //CARSHARINGFINAL_USER_H
