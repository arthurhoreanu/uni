//
// Created by Andrei on 25.05.2024.
//

#ifndef CARSHARINGFINAL_CUSTOMERHANDLINGREPOSITORY_H
#define CARSHARINGFINAL_CUSTOMERHANDLINGREPOSITORY_H

#include <vector>
#include <fstream>
#include "../Models/Customer.h"
#include "../Models/Car.h"

class CustomerHandlingRepository {
private:
    std::vector<Customer> Customers;
    std::string fileName;
    std::vector<Car> favouriteCars;


public:



    std::vector<Customer> geterCustomers();

    void readFromCsv();

    void writeToCsv();

    CustomerHandlingRepository(const std::string& fileName);

    CustomerHandlingRepository(){readFromCsv();}

    // Only Employees are allowed to create, delete and update clients
    // Only Employees are allowed to see Client related data

    // Client Handling functions
    void createCustomer(std::string name, std::string surname, std::string customerEmail,
                        std::string password, std::string address, std::string remarks,
                        std::string phone, bool gdprDeleted);

    void deleteCustomer(std::string email);

    void updateCustomer(Customer& updatedCustomer);

    // GDPR related functions
    void anonymizeCustomer();

    // Listing functions
    std::vector<Customer> listCustomersSortedByName();

    // Search functions
    std::vector<Customer> searchCustomersByEmail(std::string email);

    std::vector<Customer> searchCustomersByPhoneNumber(std::string phoneNumber);

    std::vector<Customer> searchCustomersByName(std::string surname);

    //customer setter methods
    void changeCustomerPassword(std::string newPassword, std::string emailToSearchBy);

    void changeCustomerRemarks(std::string newRemarks, std::string emailToearchBy);

    void addFavouriteCar(Car newCar);

    void removeFavoriteCar(Car carToRemove);

    void viewFavouriteCars();

    //Validation functions

    bool checkUniqueEmail(Customer c);

    //email format: firstname.lastname@smth.com
    bool checkFormatEmail(Customer c);

    //phone format: +00 123456789
    bool checkFormatPhoneNumber(Customer c);

    //if gdprDeleted == true => only name and surname MUST be completed
    //if gdprDeleted == false => everything MUST be completed, except remarks
    //method returns true if customer has attribs completed accordingly, else false
    //false path to be used in UI to display error message accordingly
    bool validateProfileByGDPR(Customer c);

    std::string getFileName();

};


#endif //CARSHARINGFINAL_CUSTOMERHANDLINGREPOSITORY_H
