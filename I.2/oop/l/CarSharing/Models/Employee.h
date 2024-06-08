//
// Created by scoti on 22.05.2024.
//

#ifndef CARSHARINGFINAL_EMPLOYEE_H
#define CARSHARINGFINAL_EMPLOYEE_H

#include <iostream>
#include <string>
#include <ctime>

class Employee {

protected:
    std::string name;
    std::string surname;
    std::string email;
    std::string password;
    std::string abbreviation;
    std::string remarks;
    std::string birthdate;
    float salary;
    std::string position;
    bool admin;
public:

    //constructor
    Employee(std::string name, std::string surname, std::string email,std::string password, std::string position, std::string birthdate,
             std::string abbreviation, float salary, std::string remarks);

    Employee();

    //getters
    std::string getName() const;

    std::string getSurname() const;

    std::string getEmail() const;

    std::string getPassword() const;

    std::string getPosition() const;

    std::string getAbbreviation() const;

    float getSalary() const;

    std::string getRemarks() const;

    std::string getBirthdate() const;

    bool isAdmin();

    //setters
    void setPosition(std::string newPosition);

    //birthdate given by user as DD MM YYY
    void setBirthdate( std::string newBirthdate);

    void setAbbreviation(std::string newAbbreviation);

    void setSalary(float newSalary);

    void setEmail(std::string newEmail);

    void setName(std::string newName);

    void setSurname(std::string newSurname);

    void setRemarks(std::string newRemarks);

    //method
    void updateProfile();



    void setAdmin(bool adminStatus);

    std::string toString();
};


#endif //CARSHARINGFINAL_EMPLOYEE_H
