//
// Created by stefa on 27/05/2024.
//

#include "CustomerHandlingUI.h"
#include <iostream>

void CustomerHandlingUI::printMenu() {
    std::cout << "Customer Management System" << std::endl;
    std::cout << "1. Add Customer" << std::endl;
    std::cout << "2. Delete Customer" << std::endl;
    std::cout << "3. Update Customer" << std::endl;
    std::cout << "4. List Customers" << std::endl;
    std::cout << "5. Search Customer by Email" << std::endl;
    std::cout << "6. Search Customer by Phone Number" << std::endl;
    std::cout << "7. Search Customer by Name" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

void CustomerHandlingUI::handleAddCustomer() {
    std::string name, surname, email, address, remarks, phone,password;
    bool gdprDeleted;

    std::cout << "Enter Name: ";
    std::cin >> name;
    std::cout << "Enter Surname: ";
    std::cin >> surname;
    std::cout << "Enter Email: ";
    std::cin >> email;
    std::cout << "Enter Password";
    std::cin >> password;
    std::cout << "Enter Address: ";
    std::cin >> address;
    std::cout << "Enter Remarks: ";
    std::cin >> remarks;
    std::cout << "Enter Phone: ";
    std::cin >> phone;
    std::cout << "Is GDPR Deleted (1 for Yes, 0 for No): ";
    std::cin >> gdprDeleted;

    try {
        customerController.addCustomer(name, surname, email, password, address, remarks, phone, gdprDeleted);
        std::cout << "Customer added successfully!" << std::endl;
    } catch (std::invalid_argument e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void CustomerHandlingUI::handleDeleteCustomer() {
    std::string email;

    std::cout << "Enter Email of the customer to delete: ";
    std::cin >> email;

    customerController.deleteCustomer(email);
    std::cout << "Customer deleted successfully!" << std::endl;
}

void CustomerHandlingUI::handleUpdateCustomer() {
    std::string name, surname, email, address, remarks, phone,password,favoriteCars;
    bool gdprDeleted;

    std::cout << "Enter Email of the customer to update: ";
    std::cin >> email;
    std::cout << "Enter new Name: ";
    std::cin >> password;
    std::cout << "Enter new Password";
    std::cin >> name;
    std::cout << "Enter new Surname: ";
    std::cin >> surname;
    std::cout << "Enter new Address: ";
    std::cin >> address;
    std::cout << "Enter new Remarks: ";
    std::cin >> remarks;
    std::cout << "Enter new Phone: ";
    std::cin >> phone;
    std::cout << "Is GDPR Deleted (1 for Yes, 0 for No): ";
    std::cin >> gdprDeleted;

    Customer updatedCustomer(name, surname, email, password, address, remarks, phone, gdprDeleted);

    try {
        customerController.updateCustomer(updatedCustomer);
        std::cout << "Customer updated successfully!" << std::endl;
    } catch (std::invalid_argument e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void CustomerHandlingUI::handleListCustomers() {
    std::vector<Customer> customers = customerController.listCustomersSorted();
    for (auto customer : customers) {
        std::cout << customer.toString() << std::endl;
    }
}

void CustomerHandlingUI::handleSearchCustomerByEmail() {
    std::string email;

    std::cout << "Enter Email to search: ";
    std::cin >> email;

    std::vector<Customer> results = customerController.searchCustomersByEmail(email);
    if (results.empty()) {
        std::cout << "No customers found with the given email." << std::endl;
    } else {
        for (auto customer : results) {
            std::cout << customer.toString() << std::endl;
        }
    }
}

void CustomerHandlingUI::handleSearchCustomerByPhoneNumber() {
    std::string phoneNumber;

    std::cout << "Enter Phone Number to search: ";
    std::cin >> phoneNumber;

    std::vector<Customer> results = customerController.searchCustomersByPhoneNumber(phoneNumber);
    if (results.empty()) {
        std::cout << "No customers found with the given phone number." << std::endl;
    } else {
        for (auto customer : results) {
            std::cout << customer.toString() << std::endl;
        }
    }
}

void CustomerHandlingUI::handleSearchCustomerByName() {
    std::string surname;

    std::cout << "Enter Surname to search: ";
    std::cin >> surname;

    std::vector<Customer> results = customerController.searchCustomersByName(surname);
    if (results.empty()) {
        std::cout << "No customers found with the given surname." << std::endl;
    } else {
        for (auto customer : results) {
            std::cout << customer.toString() << std::endl;
        }
    }
}

void CustomerHandlingUI::run() {
    int choice;
    do {
        printMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                handleAddCustomer();
                break;
            case 2:
                handleDeleteCustomer();
                break;
            case 3:
                handleUpdateCustomer();
                break;
            case 4:
                handleListCustomers();
                break;
            case 5:
                handleSearchCustomerByEmail();
                break;
            case 6:
                handleSearchCustomerByPhoneNumber();
                break;
            case 7:
                handleSearchCustomerByName();
                break;
            case 0:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cerr << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 0);
}