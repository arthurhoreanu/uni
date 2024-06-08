#ifndef TESTSCHR_H
#define TESTSCHR_H

#include "../Repository/CustomerHandlingRepository.h"

class TestsCHR {
public:
    void testAllCHR();
private:
    void testCreateCustomer(CustomerHandlingRepository &repository); // Test creating a customer
    void testUpdateCustomer(CustomerHandlingRepository &repository); // Test updating a customer
    void testDeleteCustomer(CustomerHandlingRepository &repository); // Test deleting a customer
    void testFindCustomerByEmail(CustomerHandlingRepository &repository); // Test finding a customer by email
    void testListAllCustomers(CustomerHandlingRepository &repository); // Test listing all customers
};

#endif // TESTSCHR_H
