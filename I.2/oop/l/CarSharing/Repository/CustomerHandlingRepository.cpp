//
// Created by Andrei on 25.05.2024.
//

#include "CustomerHandlingRepository.h"
#include <regex>
#include <algorithm>
#include "../Models/Customer.h"
#include <iostream>

CustomerHandlingRepository::CustomerHandlingRepository(const std::string &fileName) {
    this->fileName = fileName;
    readFromCsv();
}

void CustomerHandlingRepository::readFromCsv() {
    this->Customers.clear();
    std::ifstream file(fileName);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            // Parse each line and create Cufstomer objects
            // Assuming your CSV format is comma-separated
            std::stringstream ss(line);
            std::string name, surname, email, password, address, remarks, phone, gdprDeletedStr;
            std::getline(ss, name, ',');
            std::getline(ss, surname, ',');
            std::getline(ss, email, ',');
            std::getline(ss, password, ',');
            std::getline(ss, address, ',');
            std::getline(ss, remarks, ',');
            std::getline(ss, phone, ',');
            std::getline(ss, gdprDeletedStr, ',');

            // Convert gdprDeleted from string to bool
            bool gdprDeleted = (gdprDeletedStr == "1" || gdprDeletedStr == "true");


            // Create Customer object and add to vector
            Customers.emplace_back(name, surname, email, password, address, remarks, phone, gdprDeleted);
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << fileName << std::endl;
    }

}

void CustomerHandlingRepository::writeToCsv() {
    std::ofstream file(fileName);
    if (file.is_open()) {
        for (Customer &customer: Customers) {
            // Write each customer's data in CSV format
            file << customer.getName() << ","
                 << customer.getSurname() << ","
                 << customer.getEmail() << ","
                 << customer.getPassword() << ","
                 << customer.getAddress() << ","
                 << customer.getRemarks() << ","
                 << customer.getPhone() << ","
                 << (customer.getGdprDeleted() ? "1" : "0") << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << fileName << std::endl;
    }
}

void CustomerHandlingRepository::createCustomer(std::string name, std::string surname, std::string customerEmail,
                                                std::string password, std::string address, std::string remarks,
                                                std::string phone, bool gdprDeleted) {
    Customer newCustomer(name, surname, customerEmail, password, address, remarks, phone, gdprDeleted);
    Customers.push_back(newCustomer);
    writeToCsv();
}

void CustomerHandlingRepository::deleteCustomer(std::string email) {
    for(auto it = this->Customers.begin();it != this->Customers.end();++it){
        if(it->getEmail() == email){
            this->Customers.erase(it);
            break;
        }
    }
    writeToCsv();
}

void CustomerHandlingRepository::updateCustomer(Customer &updatedCustomer) {
    readFromCsv();

    for (auto &customer: Customers) {
        if (customer.getEmail() == updatedCustomer.getEmail()) {
                //update customers information
                customer = updatedCustomer;

                writeToCsv();
                return;
        }
    }
    // Customer not found, display error or handle accordingly
    std::cerr << "Customer with email " << updatedCustomer.getEmail() << " not found for updating." << std::endl;
}

bool CustomerHandlingRepository::checkFormatEmail(Customer c) {
    std::string email = c.getEmail();
    bool has_at = false;
    bool ends_with_com = false;

    for (size_t i = 0; i < email.length(); ++i) {
        if (email[i] == '@') {
            if (has_at || i == 0 || i == email.length() - 1) {
                return false;
            }
            has_at = true;
        } else if (i > email.length() - 4 && email.substr(i) == ".com") {
            ends_with_com = true;
        }
    }

    return has_at && ends_with_com;
}

bool CustomerHandlingRepository::checkFormatPhoneNumber(Customer c) {
    std::string phone = c.getPhone();

    // Remove all non-digit and space characters
    std::string digits = "";
    for (char ch : phone) {
        if (isdigit(ch)) {
            digits += ch;
        }
    }

    // Check if the length is between 9 and 11 (inclusive)
    return digits.length() >= 9 && digits.length() <= 11;
}

bool CustomerHandlingRepository::checkUniqueEmail(Customer c) {
    std::string email = c.getEmail();


    for (auto current: Customers) {
        if (current.getEmail() == email) {
            return false;
        }
    }

   return true;
}


//see header for details
bool CustomerHandlingRepository::validateProfileByGDPR(Customer c) {
    bool gdprDeleted = c.getGdprDeleted();

    //if gdpr is deleted
    if (gdprDeleted) {
        if (c.getSurname().empty() || c.getName().empty()) {
            return false;
        } else {
            return true;
        }

    } else {
        if (c.getSurname().empty() || c.getName().empty() || c.getEmail().empty() ||
            c.getPhone().empty() || c.getAddress().empty()) {
            return false;
        } else {
            return true;
        }
    }

    //use case in UI:
    //if method returns false => display message : Error in creating customer. One/several mandatory fields must be completed according to GDPR

}

std::vector<Customer> CustomerHandlingRepository::listCustomersSortedByName() {
    std::vector<Customer> sortedCustomers = Customers; // Create a copy of the Customers vector
    std::sort(sortedCustomers.begin(), sortedCustomers.end(), [](const Customer &a, const Customer &b) {
        return a.getName() < b.getName();
    });
    return sortedCustomers; // Return the sorted vector
}

std::vector<Customer> CustomerHandlingRepository::searchCustomersByEmail(std::string email) {
    std::vector<Customer> results;
    for (auto &customer: Customers) {
        if (customer.getEmail() == email) {
            results.push_back(customer);
        }
    }
    return results;
}

std::vector<Customer> CustomerHandlingRepository::searchCustomersByPhoneNumber(std::string phoneNumber) {
    std::vector<Customer> results;
    for (auto &customer: Customers) {
        if (customer.getPhone() == phoneNumber) {
            results.push_back(customer);
        }
    }
    return results;
}

std::vector<Customer> CustomerHandlingRepository::searchCustomersByName(std::string surname) {
    std::vector<Customer> results;
    for (auto &customer: Customers) {
        if (customer.getSurname() == surname) {
            results.push_back(customer);
        }
    }
    return results;
}

std::vector<Customer> CustomerHandlingRepository::geterCustomers() {
    return this->Customers;
}





void CustomerHandlingRepository::changeCustomerPassword(std::string newPassword, std::string emailToSearchBy) {
    for (auto customer: Customers) {
        if (customer.getEmail() == emailToSearchBy) {
            customer.setPassword(newPassword);
        }
    }
    writeToCsv();
}

void CustomerHandlingRepository::changeCustomerRemarks(std::string newRemarks, std::string emailToearchBy) {
    for (auto customer: Customers) {
        if (customer.getEmail() == emailToearchBy) {
            customer.setRemarks(newRemarks);
        }
    }
    writeToCsv();
}

void CustomerHandlingRepository::addFavouriteCar(Car newCar) {
    favouriteCars.push_back(newCar);
}

void CustomerHandlingRepository::removeFavoriteCar(Car carToRemove) {
    for (int i = 0; i < favouriteCars.size(); i++) {
        auto current = favouriteCars[i];
        if (current.getLicensePlate() == carToRemove.getLicensePlate() &&
            current.getModel() == carToRemove.getModel() &&
            current.getBrand() == carToRemove.getBrand() &&
            current.getYearOfFirstRegistration() == carToRemove.getYearOfFirstRegistration() &&
            current.getMileage() == carToRemove.getMileage() && current.getDailyRate() == carToRemove.getDailyRate() &&
            current.getFuelType() == carToRemove.getFuelType() &&
            current.getTransmission() == carToRemove.getTransmission() &&
            current.getColor() == carToRemove.getColor() && current.getisActive() == carToRemove.getisActive()) {

            favouriteCars.erase(favouriteCars.begin() + 1);
        }
    }
}

void CustomerHandlingRepository::viewFavouriteCars() {
    for (auto current: favouriteCars) {
        std::cout << current.getLicensePlate() << " " << current.getModel() << " " << current.getBrand() << " "
                  << current.getYearOfFirstRegistration() << " " << current.getMileage() << " "
                  << current.getDailyRate() << " " << current.getFuelType() << " " << current.getTransmission()
                  << current.getColor() << " " << current.getRemarks() << " " << current.getisActive() << '\n';
    }
}

std::string CustomerHandlingRepository::getFileName() {
    return fileName;
}
