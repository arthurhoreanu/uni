#ifndef TESTSEMPLOYEEREPOSITORY_H
#define TESTSEMPLOYEEREPOSITORY_H

#include "../Repository/EmployeeRepository.h"

class TestsEmployeeRepository {
public:
    void testAllER();
private:
    void testCreateEmployee(EmployeeRepository &repository); // Test creating an employee
    void testUpdateEmployee(EmployeeRepository &repository); // Test updating an employee
    void testDeleteEmployee(EmployeeRepository &repository); // Test deleting an employee
    void testFindEmployeeByName(EmployeeRepository &repository); // Test finding an employee by name
    void testListAllEmployees(EmployeeRepository &repository); // Test listing all employees
};

#endif // TESTSEMPLOYEEREPOSITORY_H
