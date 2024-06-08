//
// Created by sorin on 5/22/2024.
//

#ifndef CARSHARING_EMPLOYEEREPOSITORY_H
#define CARSHARING_EMPLOYEEREPOSITORY_H

#include <vector>
#include "../Models/Employee.h"
using namespace std;

class EmployeeRepository {
private:
    std::vector<Employee> employees;
    std::string fileName;

public:
    EmployeeRepository() { readFromCsv(); }
    EmployeeRepository(std::string &fileName);

    ~EmployeeRepository() {}

    std::vector<Employee> getEmployes();

    void createEmployee(std::string name, std::string surname, std::string email, std::string password, std::string position, std::string birthdate,
                        std::string abbreviation, float salary, std::string remarks);

    Employee findEmployeeByName(std::string employeeName,std::string employeeSurname);

    std::vector<Employee> findEmployeeByString(std::string searchString);



    void deleteEmployee(std::string employeeName, std::string employeeSurname);

    void updateEmployee(Employee &updatedEmployee);

    std::vector<Employee> listAllEmployees();

    void readFromCsv();

    void writeToCsv();

    EmployeeRepository(std::string filename);
};


#endif //CARSHARING_EMPLOYEEREPOSITORY_H
