#include "TestsUserRepository.h"
#include <iostream>

void TestsUserRepository::testAllUR() {
    std::string fileName = "test_users.csv";
    UserRepository repository(fileName);

    testCreateUser(repository);
    testUpdateUser(repository);
    testDeleteUser(repository);
    testFindUserByEmail(repository);
}

void TestsUserRepository::testCreateUser(UserRepository &repository) {
    repository.createUser(1, "john.doe@example.com", "password123", "John", "Doe");

    User foundUser = repository.findUserByEmail("john.doe@example.com");
    if (foundUser.getUserId() == 1 && foundUser.getUserEmail() == "john.doe@example.com") {
        std::cout << "testCreateUser passed.\n";
    } else {
        std::cout << "testCreateUser failed.\n";
    }
}

void TestsUserRepository::testUpdateUser(UserRepository &repository) {
    User updatedUser(1, "john.doe@example.com", "newpassword", "John", "Doe");
    repository.updateUser(updatedUser);

    User foundUser = repository.findUserByEmail("john.doe@example.com");
    if (foundUser.getUserPassword() == "newpassword") {
        std::cout << "testUpdateUser passed.\n";
    } else {
        std::cout << "testUpdateUser failed.\n";
    }
}

void TestsUserRepository::testDeleteUser(UserRepository &repository) {
    repository.createUser(2, "jane.doe@example.com", "password456", "Jane", "Doe");
    repository.deleteUser(2);

    try {
        repository.findUserByEmail("jane.doe@example.com");
        std::cout << "testDeleteUser failed.\n";
    } catch (std::runtime_error &e) {
        std::cout << "testDeleteUser passed.\n";
    }
}

void TestsUserRepository::testFindUserByEmail(UserRepository &repository) {
    repository.createUser(3, "alice.smith@example.com", "password789", "Alice", "Smith");

    User foundUser = repository.findUserByEmail("alice.smith@example.com");
    if (foundUser.getUserId() == 3 && foundUser.getUserEmail() == "alice.smith@example.com") {
        std::cout << "testFindUserByEmail passed.\n";
    } else {
        std::cout << "testFindUserByEmail failed.\n";
    }
}

int main() {
    TestsUserRepository userTest;
    userTest.testAllUR();

    TestsOrderRepository orderTest;
    orderTest.testAllOR();

    TestsEmployeeRepository employeeTest;
    employeeTest.testAllER();

    TestsCarRepository carTest;
    carTest.testAllCarRepo();

    TestsCHR customerTest;
    customerTest.testALLCHR();

    return 0;
}
