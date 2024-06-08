//
// Created by Andra on 5/27/2024.
//

#include "CustomerController.h"


#include <stdexcept>

void CustomerController::addCustomer(const std::string& name, const std::string& surname, const std::string& customerEmail,const std::string& password, const std::string& address, const std::string& remarks, const std::string& phone, bool gdprDeleted) {
    Customer newCustomer(name, surname,  customerEmail,password, address, remarks,phone, gdprDeleted);
    customerRepo.createCustomer(name, surname, customerEmail,password, address, remarks, phone, gdprDeleted);
    if (customerRepo.checkUniqueEmail(newCustomer) && customerRepo.checkFormatEmail(newCustomer) && customerRepo.checkFormatPhoneNumber(newCustomer)) {
        if (customerRepo.validateProfileByGDPR(newCustomer)) {
            customerRepo.createCustomer(name, surname, customerEmail,password, address, remarks, phone, gdprDeleted);
        } else {
            throw std::invalid_argument("Invalid customer profile according to GDPR.");
        }
    } else {
        throw std::invalid_argument("Invalid email/phone format or non-unique email.");
    }
}

void CustomerController::deleteCustomer(std::string email) {
    customerRepo.deleteCustomer(email);
}

void CustomerController::updateCustomer(Customer &updatedCustomer) {
    customerRepo.updateCustomer(updatedCustomer);

}

std::vector<Customer> CustomerController::listCustomersSorted() {
    return customerRepo.listCustomersSortedByName();
}

std::vector<Customer> CustomerController::searchCustomersByEmail(std::string email) {
    return customerRepo.searchCustomersByEmail(email);
}

std::vector<Customer> CustomerController::searchCustomersByPhoneNumber(std::string phoneNumber) {
    return customerRepo.searchCustomersByPhoneNumber(phoneNumber);
}

std::vector<Customer> CustomerController::searchCustomersByName(std::string surname) {
    return customerRepo.searchCustomersByName(surname);
}



