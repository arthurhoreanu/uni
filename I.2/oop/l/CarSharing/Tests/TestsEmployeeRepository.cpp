#include "TestsEmployeeRepository.h"
#include <iostream>

void TestsEmployeeRepository::testAllER() {
    std::string fileName = "test_employees.csv";
    EmployeeRepository repository(fileName);

    testCreateEmployee(repository);
    testUpdateEmployee(repository);
    testDeleteEmployee(repository);
    testFindEmployeeByName(repository);
    testListAllEmployees(repository);
}

void TestsEmployeeRepository::testCreateEmployee(EmployeeRepository &repository) {
    repository.createEmployee("John", "Doe", "john.doe@example.com", "password123", "Manager", "1980-01-01", "JD", 5000.0, "new");

    auto employees = repository.listAllEmployees();
    if (employees.size() == 1 && employees[0].getEmail() == "john.doe@example.com") {
        std::cout << "testCreateEmployee passed.\n";
    } else {
        std::cout << "testCreateEmployee failed.\n";
    }
}

void TestsEmployeeRepository::testUpdateEmployee(EmployeeRepository &repository) {
    Employee updatedEmployee("John", "Doe", "john.doe@example.com", "newpassword", "CEO", "1980-01-01", "JD", 6000.0, "updated");
    repository.updateEmployee(updatedEmployee);

    auto employees = repository.listAllEmployees();
    if (employees.size() == 1 && employees[0].getPassword() == "newpassword" && employees[0].getPosition() == "CEO") {
        std::cout << "testUpdateEmployee passed.\n";
    } else {
        std::cout << "testUpdateEmployee failed.\n";
    }
}

void TestsEmployeeRepository::testDeleteEmployee(EmployeeRepository &repository) {
    std::string name = "John";
    std::string surname = "Doe";
    repository.deleteEmployee(name, surname);

    auto employees = repository.listAllEmployees();
    if (employees.empty()) {
        std::cout << "testDeleteEmployee passed.\n";
    } else {
        std::cout << "testDeleteEmployee failed.\n";
    }
}

void TestsEmployeeRepository::testFindEmployeeByName(EmployeeRepository &repository) {
    repository.createEmployee("Jane", "Doe", "jane.doe@example.com", "password456", "CTO", "1985-05-05", "JD", 7000.0, "new");

    try {
        Employee foundEmployee = repository.findEmployeeByName("Jane", "Doe");
        if (foundEmployee.getEmail() == "jane.doe@example.com") {
            std::cout << "testFindEmployeeByName passed.\n";
        } else {
            std::cout << "testFindEmployeeByName failed.\n";
        }
    } catch (std::runtime_error &e) {
        std::cout << "testFindEmployeeByName failed.\n";
    }
}

void TestsEmployeeRepository::testListAllEmployees(EmployeeRepository &repository) {
    repository.createEmployee("Alice", "Smith", "alice.smith@example.com", "password789", "Developer", "1990-10-10", "AS", 4000.0, "new");
    repository.createEmployee("Bob", "Johnson", "bob.johnson@example.com", "password101", "Tester", "1992-12-12", "BJ", 3500.0, "new");

    auto employees = repository.listAllEmployees();
    if (employees.size() == 2) {
        std::cout << "testListAllEmployees passed.\n";
    } else {
        std::cout << "testListAllEmployees failed.\n";
    }
}

int main() {
    TestsEmployeeRepository employeeTest;
    employeeTest.testAllER();

    TestsCarRepository carTest;
    carTest.testAllCarRepo();

    TestsCHR customerTest;
    customerTest.testALLCHR();

    return 0;
}
