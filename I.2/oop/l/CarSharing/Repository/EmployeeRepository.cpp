#include "EmployeeRepository.h"
#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <string>
#include "../Models/Employee.h"
#include "fstream"
#include "sstream"

EmployeeRepository::EmployeeRepository(std::string &fileName) {
    this->fileName = fileName;
    readFromCsv();
}


// Method to list all employees
std::vector<Employee> EmployeeRepository::listAllEmployees() {
    return employees;
}

// Method to find employees by any string (search through various attributes with partial matching)
std::vector<Employee> EmployeeRepository::findEmployeeByString(std::string searchString) {
    // Helper lambda function to convert a string to lowercase
    auto toLower = [](std::string str) {
        std::transform(str.begin(), str.end(), str.begin(), ::tolower); // Convert each character to lowercase
        return str; // Return the lowercase string
    };

    // Convert the search string to lowercase for case-insensitive comparison
    std::string lowerSearchString = toLower(searchString);

    // Vector to store matching employees
    std::vector<Employee> matchingEmployees;

    // Iterate over all employees in the repository
    for (auto employee : employees) {
        // Convert each employee attribute to lowercase and check if the search string is a substring
        if (toLower(employee.getName()).find(lowerSearchString) != std::string::npos || // Check if name contains the search string
            toLower(employee.getSurname()).find(lowerSearchString) != std::string::npos || // Check if surname contains the search string
            toLower(employee.getEmail()).find(lowerSearchString) != std::string::npos || // Check if email contains the search string
            toLower(employee.getPosition()).find(lowerSearchString) != std::string::npos || // Check if position contains the search string
            toLower(employee.getAbbreviation()).find(lowerSearchString) != std::string::npos || // Check if abbreviation contains the search string
            toLower(employee.getRemarks()).find(lowerSearchString) != std::string::npos) { // Check if remarks contain the search string
            // If any attribute contains the search string, add the employee to the matchingEmployees vector
            matchingEmployees.push_back(employee);
        }
    }

    // Return the vector of matching employees
    return matchingEmployees;
}

void EmployeeRepository::createEmployee(std::string name, std::string surname, std::string email, std::string password, std::string position, std::string birthdate,
                                        std::string abbreviation, float salary, std::string remarks) {
    Employee newEmployee(name, surname, email, password, position, birthdate, abbreviation, salary, remarks);
    employees.push_back(newEmployee);
    writeToCsv();  // Write to CSV after adding
}

Employee EmployeeRepository::findEmployeeByName(std::string employeeName, std::string employeeSurname) {
    for (auto current : employees) { // Go through employees and check current employee name and surname; if it matches => return it
        if (current.getName() == employeeName && current.getSurname() == employeeSurname) {
            return current;
        }
    }
    throw std::runtime_error("Employee not found");
}

void EmployeeRepository::deleteEmployee(std::string employeeName, std::string employeeSurname) {
    for(auto it = this->employees.begin();it != this->employees.end();++it){
        if(it->getName() == employeeName && it->getSurname() == employeeSurname){
            this->employees.erase(it);
            break;
        }

    }
    writeToCsv();
}

void EmployeeRepository::updateEmployee(Employee& updatedEmployee) {
    readFromCsv();

    for(auto &employee:this->employees){
        if(employee.getName() == updatedEmployee.getName() && employee.getSurname() == updatedEmployee.getSurname())
        {
            employee = updatedEmployee;

            writeToCsv();
            return;
        }
    }
    std::cerr <<"Employee with name" << updatedEmployee.getName() << "and surname"<<updatedEmployee.getSurname()<<"not found"<<std::endl;


}
EmployeeRepository::EmployeeRepository(std::string fileName) {
    this->fileName = fileName;
    readFromCsv();
}

void EmployeeRepository::readFromCsv() {
    this->employees.clear();
    std::ifstream  file(fileName);
    if(file.is_open()){
        std::string line;
        while(std::getline(file,line)){
            std::stringstream ss(line);
            std::string name, surname, email, password, position, birthdate, abrevation,salaryStr,remarks;
            std::getline(ss,name,',');
            std::getline(ss,surname,',');
            std::getline(ss,email,',');
            std::getline(ss,password,',');
            std::getline(ss,position,',');
            std::getline(ss,birthdate,',');
            std::getline(ss,abrevation,',');
            std::getline(ss,salaryStr,',');
            float salary = std::stof(salaryStr);
            std::getline(ss,remarks,',');
            employees.emplace_back(name,surname,email,password,position,birthdate,abrevation,salary,remarks);


        }
        file.close();
    } else{
        std::cerr<<"Unable to open file:"<<fileName<<std::endl;
    }
}

void EmployeeRepository::writeToCsv() {
    std::ofstream file(fileName);
    if(file.is_open()){
        for(Employee &employee : employees){
            file << employee.getName() << ","
            <<employee.getSurname()<<","
            <<employee.getEmail()<<","
            <<employee.getPassword()<<","
            <<employee.getPosition()<<","
            <<employee.getBirthdate()<<","
            <<employee.getAbbreviation()<<","
            <<employee.getSalary()<<","
            <<employee.getRemarks()<<std::endl;
        }
        file.close();
    }else{
        std::cerr << " Unable to open file: "<<fileName << std::endl;
    }
}

std::vector<Employee> EmployeeRepository::getEmployes() {
    return this->employees;
}
