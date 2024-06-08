//
// Created by scoti on 27.05.2024.
//

#include "EmployeeController.h"



void EmployeeController::addEmployee(std::string &name, std::string &surname, std::string &email, std::string &password,
                                     std::string &position, std::string &birthdate, std::string &abbreviation,
                                     float salary, std::string &remarks) {
    //Employee newEmployee(name,surname,email,password,position,birthdate,abbreviation,salary,remarks);
    employeeRepo.createEmployee(name,surname,email,password,position,birthdate,abbreviation,salary,remarks);
}
//find by--> using getEmployeeByName from EmployeeRepository
void EmployeeController::updateEmployee(std::string &newEmail, std::string &name, std::string &surname,
                                        std::string &newPosition, std::string &newBirthdate, std::string &newAbbreviation,
                                        float newSalary, std::string &newRemarks) {

    Employee emp = employeeRepo.findEmployeeByName(name, surname);
    emp.setEmail(newEmail);
    emp.setPosition(newPosition);
    emp.setBirthdate(newBirthdate);
    emp.setAbbreviation(newAbbreviation);
    emp.setSalary(newSalary);
    emp.setRemarks(newRemarks);
    //push the updated data in repo
    employeeRepo.updateEmployee(emp);
}

void EmployeeController::deleteEmployee(std::string &name, std::string &surname) {
    employeeRepo.deleteEmployee(name, surname);
}

std::vector<Employee> EmployeeController::listAllEmployees()  {
    return employeeRepo.listAllEmployees();
}


//nu stiu cum sa o fac incat sa mearga pe findEmployeeByString e functia aia lambda nebuna, also nu mi merge ca parametru
/*
std::vector<Employee> EmployeeController::searchEmployeesByString(std::string searchString)  {
    return employeeRepo.findEmployeeByString(searchString);
}
*/

Employee EmployeeController::getEmployeeByName( std::string& name,  std::string& surname)  {
    return employeeRepo.findEmployeeByName(name, surname);
}

/*void EmployeeController::activateDeactivateEmployee(std::string& name,  std::string& surname) {
    Employee& emp = employeeRepo.findEmployeeByName(name, surname);
    emp.setIsActive(!emp.getIsActive());
    employeeRepo.updateEmployee(emp);
}

void EmployeeController::assignRemoveAdminRights(std::string& name,  std::string& surname) {
    Employee& emp = employeeRepo.findEmployeeByName(name, surname);
    emp.setIsAdmin(!emp.getIsAdmin());
    employeeRepo.updateEmployee(emp);
}

void EmployeeController::resetPassword(std::string& name,  std::string& surname) {
    Employee& emp = employeeRepo.findEmployeeByName(name, surname);
    std::string newPassword = "defaultPassword";
    emp.setPassword(newPassword);
    employeeRepo.updateEmployee(emp);
}
*/
void EmployeeController::updateProfile(std::string& name, std::string& surname , const std::string& newRemarks) {
    Employee emp = employeeRepo.findEmployeeByName(name, surname);
    emp.setRemarks(newRemarks);
    employeeRepo.updateEmployee(emp);
}
