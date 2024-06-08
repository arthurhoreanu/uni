#include "TestsCHR.h"
#include <iostream>

void TestsCHR::testAllCHR() {
    CustomerHandlingRepository repository("test_customers.csv");

    testCreateCustomer(repository);
    testUpdateCustomer(repository);
    testDeleteCustomer(repository);
    testFindCustomerByEmail(repository);
    testListAllCustomers(repository);
}

void TestsCHR::testCreateCustomer(CustomerHandlingRepository &repository) {
    repository.createCustomer("John", "Doe", "john.doe@example.com", "password123", "123 Main St", "new", "1234567890", false);

    auto customers = repository.geterCustomers();
    if (customers.size() == 1 && customers[0].getEmail() == "john.doe@example.com") {
        std::cout << "testCreateCustomer passed.\n";
    } else {
        std::cout << "testCreateCustomer failed.\n";
    }
}

void TestsCHR::testUpdateCustomer(CustomerHandlingRepository &repository) {
    Customer updatedCustomer("John", "Doe", "john.doe@example.com", "newpassword", "456 Main St", "updated", "0987654321", false);
    repository.updateCustomer(updatedCustomer);

    auto customers = repository.geterCustomers();
    if (customers.size() == 1 && customers[0].getPassword() == "newpassword" && customers[0].getAddress() == "456 Main St") {
        std::cout << "testUpdateCustomer passed.\n";
    } else {
        std::cout << "testUpdateCustomer failed.\n";
    }
}

void TestsCHR::testDeleteCustomer(CustomerHandlingRepository &repository) {
    std::string email = "john.doe@example.com";
    repository.deleteCustomer(email);

    auto customers = repository.geterCustomers();
    if (customers.empty()) {
        std::cout << "testDeleteCustomer passed.\n";
    } else {
        std::cout << "testDeleteCustomer failed.\n";
    }
}

void TestsCHR::testFindCustomerByEmail(CustomerHandlingRepository &repository) {
    repository.createCustomer("Jane", "Doe", "jane.doe@example.com", "password456", "789 Main St", "new", "1122334455", false);

    auto customers = repository.searchCustomersByEmail("jane.doe@example.com");
    if (customers.size() == 1 && customers[0].getEmail() == "jane.doe@example.com") {
        std::cout << "testFindCustomerByEmail passed.\n";
    } else {
        std::cout << "testFindCustomerByEmail failed.\n";
    }
}

void TestsCHR::testListAllCustomers(CustomerHandlingRepository &repository) {
    repository.createCustomer("Alice", "Smith", "alice.smith@example.com", "password789", "101 Main St", "new", "2233445566", false);
    repository.createCustomer("Bob", "Johnson", "bob.johnson@example.com", "password101", "202 Main St", "new", "3344556677", false);

    auto customers = repository.geterCustomers();
    if (customers.size() == 2) {
        std::cout << "testListAllCustomers passed.\n";
    } else {
        std::cout << "testListAllCustomers failed.\n";
    }
}

int main() {
    TestsCHR test;
    test.testAllCHR();
    return 0;
}
