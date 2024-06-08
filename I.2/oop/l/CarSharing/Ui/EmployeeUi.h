#ifndef EMPLOYEE_UI_H
#define EMPLOYEE_UI_H

#include "../Controller/EmployeeController.h"
#include <iostream>
#include <string>

class EmployeeUi {
public:
    EmployeeUi(EmployeeController& controller);

    void displayMenu();
    void handleMenu();

private:
    EmployeeController& controller;

    void addEmployee();
    void updateEmployee();
    void deleteEmployee();
    void listAllEmployees();
    void getEmployeeByName();
    void updateProfile();
    // Uncomment the following if needed
    // void activateDeactivateEmployee();
    // void assignRemoveAdminRights();
    // void resetPassword();
};

#endif // EMPLOYEE_UI_H
