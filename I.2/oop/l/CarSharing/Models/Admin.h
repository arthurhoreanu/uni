#ifndef ADMIN_H
#define ADMIN_H
#include "Employee.h"

class Admin : public Employee {
public:
    //constructor
    Admin(std::string name, std::string surname, std::string email,std::string password, std::string position, std::string birthdate,
          std::string abbreviation, float salary, std::string remarks);

    //getters
    std::string getName();
    std::string getSurname();
    std::string getEmail();
    std::string getPassword();
    std::string getPosition();
    std::string getAbbreviation();
    float getSalary();
    std::string getRemarks();
    std::string getBirthdate();

    //setters
    void setPosition(std::string newPosition);
    void setBirthdate(std::string newBirthdate);
    void setAbbreviation(std::string newAbbreviation);
    void setSalary(float newSalary);
    void setEmail(std::string newEmail);
    void setPassword(std::string newPassword);
    void setName(std::string newName);
    void setSurname(std::string newSurname);
    void setRemarks(std::string newRemarks);
};

#endif // ADMIN_H