//
// Created by scoti on 27.05.2024.
//

#include "EmployeeUi.h"

EmployeeUi::EmployeeUi(EmployeeController& controller) : controller(controller) {}

void EmployeeUi::displayMenu() {
    std::cout << "Employee Management System" << std::endl;
    std::cout << "1. Add Employee" << std::endl;
    std::cout << "2. Update Employee" << std::endl;
    std::cout << "3. Delete Employee" << std::endl;
    std::cout << "4. List All Employees" << std::endl;
    std::cout << "5. Get Employee By Name" << std::endl;
    std::cout << "6. Update Profile" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

void EmployeeUi::handleMenu() {
    int choice;
    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                updateEmployee();
                break;
            case 3:
                deleteEmployee();
                break;
            case 4:
                listAllEmployees();
                break;
            case 5:
                getEmployeeByName();
                break;
            case 6:
                //updateProfile();
                break;
            case 0:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 0);
}

void EmployeeUi::addEmployee() {
    std::string name, surname, email, password, position, birthdate, abbreviation, remarks;
    float salary;

    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    std::cout << "Enter surname: ";
    std::getline(std::cin, surname);
    std::cout << "Enter email: ";
    std::getline(std::cin, email);
    std::cout << "Enter password: ";
    std::getline(std::cin, password);
    std::cout << "Enter position: ";
    std::getline(std::cin, position);
    std::cout << "Enter birthdate: ";
    std::getline(std::cin, birthdate);
    std::cout << "Enter abbreviation: ";
    std::getline(std::cin, abbreviation);
    std::cout << "Enter salary: ";
    std::cin >> salary;
    std::cin.ignore();
    std::cout << "Enter remarks: ";
    std::getline(std::cin, remarks);

    controller.addEmployee(name, surname, email, password, position, birthdate, abbreviation, salary, remarks);
}

void EmployeeUi::updateEmployee() {
    std::string name, surname, newEmail, newPosition, newBirthdate, newAbbreviation, newRemarks;
    float newSalary;

    std::cout << "Enter current name: ";
    std::getline(std::cin, name);
    std::cout << "Enter current surname: ";
    std::getline(std::cin, surname);
    std::cout << "Enter new email: ";
    std::getline(std::cin, newEmail);
    std::cout << "Enter new position: ";
    std::getline(std::cin, newPosition);
    std::cout << "Enter new birthdate: ";
    std::getline(std::cin, newBirthdate);
    std::cout << "Enter new abbreviation: ";
    std::getline(std::cin, newAbbreviation);
    std::cout << "Enter new salary: ";
    std::cin >> newSalary;
    std::cin.ignore();
    std::cout << "Enter new remarks: ";
    std::getline(std::cin, newRemarks);

    controller.updateEmployee(newEmail, name, surname, newPosition, newBirthdate, newAbbreviation, newSalary, newRemarks);
}

void EmployeeUi::deleteEmployee() {
    std::string name, surname;

    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    std::cout << "Enter surname: ";
    std::getline(std::cin, surname);

    controller.deleteEmployee(name, surname);
}

void EmployeeUi::listAllEmployees() {
    std::vector<Employee> employees = controller.listAllEmployees();
    for (auto emp : employees) {
        std::cout << emp.toString() << std::endl;
    }
}

void EmployeeUi::getEmployeeByName() {
    std::string name, surname;

    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    std::cout << "Enter surname: ";
    std::getline(std::cin, surname);

    Employee emp = controller.getEmployeeByName(name, surname);
    std::cout << emp.toString() << std::endl;
}

//de vazut aici
//void EmployeeUi::updateProfile() {
//    std::string name, surname, newRemarks;
//
//    std::cout << "Enter name: ";
//    std::getline(std::cin, name);
//    std::cout << "Enter surname: ";
//    std::getline(std::cin, surname);
//    std::cout << "Enter new remarks: ";
//    std::getline(std::cin, newRemarks);
//
//    controller.updateProfile(name, surname, newRemarks);
//}

// Uncomment and implement the following if needed
/*
void EmployeeUi::activateDeactivateEmployee() {
    std::string name, surname;

    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    std::cout << "Enter surname: ";
    std::getline(std::cin, surname);

    controller.activateDeactivateEmployee(name, surname);
}

void EmployeeUi::assignRemoveAdminRights() {
    std::string name, surname;

    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    std::cout << "Enter surname: ";
    std::getline(std::cin, surname);

    controller.assignRemoveAdminRights(name, surname);
}

void EmployeeUi::resetPassword() {
    std::string name, surname;

    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    std::cout << "Enter surname: ";
    std::getline(std::cin, surname);

    controller.resetPassword(name, surname);
}
*/
