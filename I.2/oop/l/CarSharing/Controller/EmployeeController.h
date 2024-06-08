//
// Created by scoti on 27.05.2024.
//

#ifndef CARSHARINGFINAL_EMPLOYEECONTROLLER_H
#define CARSHARINGFINAL_EMPLOYEECONTROLLER_H

#include "../Models/Employee.h"
#include "../Repository/EmployeeRepository.h"
#include <vector>
#include <iostream>

class EmployeeController {
private:
    EmployeeRepository employeeRepo;
public:
    EmployeeController(const std::string& filename) : employeeRepo(filename){}

    void addEmployee(std::string &name, std::string &surname, std::string &email,
                     std::string &password, std::string &position, std::string &birthdate,
                     std::string &abbreviation, float salary, std::string &remarks);

    void updateEmployee(std::string &newEmail, std::string &name, std::string &surname,
                        std::string &newPosition, std::string &newBirthdate, std::string &newAbbreviation,
                        float newSalary, std::string &newRemarks);

    std::vector<Employee> listAllEmployees();

    std::vector<Employee> searchEmployee(std::string& searchString);

    void deleteEmployee(std::string &name, std::string &surname);

    void activateDeactivateEmployee(std::string &name, std::string &surname );

    void assignRemoveAdminRights(std::string &name, std::string &surname);

    void resetPassword(std::string &name, std::string &surname);

    void updateProfile(std::string &name, std::string &surname, std::string &newRemarks);

    Employee getEmployeeByName( std::string& name,  std::string& surname) ;


    void updateProfile(string &name, string &surname, const string &newRemarks);
};


#endif //CARSHARINGFINAL_EMPLOYEECONTROLLER_H

