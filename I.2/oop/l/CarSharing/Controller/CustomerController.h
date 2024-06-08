//
// Created by Andra on 5/27/2024.
//

#ifndef CARSHARINGFINAL_CUSTOMERCONTROLLER_H
#define CARSHARINGFINAL_CUSTOMERCONTROLLER_H



#include "../Repository//CustomerHandlingRepository.h"
class CustomerController {
private:
    CustomerHandlingRepository customerRepo;
public:
    CustomerController(const std::string& fileName) : customerRepo(fileName) {}
    void addCustomer(const std::string& name, const std::string& surname, const std::string& customerEmail,const std::string& password, const std::string& address, const std::string& remarks, const std::string& phone, bool gdprDeleted);
    void deleteCustomer(std::string email);
    void updateCustomer(Customer& updatedCustomer);
    std::vector<Customer> listCustomersSorted();
    std::vector<Customer> searchCustomersByEmail(std::string email);
    std::vector<Customer> searchCustomersByPhoneNumber(std::string phoneNumber);
    std::vector<Customer> searchCustomersByName(std::string surname);
};


#endif //CARSHARINGFINAL_CUSTOMERCONTROLLER_H
