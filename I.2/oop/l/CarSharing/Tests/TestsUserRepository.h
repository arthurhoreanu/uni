#ifndef TESTSUSERREPOSITORY_H
#define TESTSUSERREPOSITORY_H

#include "../Repository/UserRepository.h"

class TestsUserRepository {
public:
    void testAllUR(); // Run all tests for UserRepository
private:
    void testCreateUser(UserRepository &repository); // Test creating a user
    void testUpdateUser(UserRepository &repository); // Test updating a user
    void testDeleteUser(UserRepository &repository); // Test deleting a user
    void testFindUserByEmail(UserRepository &repository); // Test finding a user by email
};

#endif // TESTSUSERREPOSITORY_H
