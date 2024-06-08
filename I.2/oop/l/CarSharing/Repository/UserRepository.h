//
// Created by Darius on 5/26/2024.
//

#ifndef CARSHARINGFINAL_USERREPOSITORY_H
#define CARSHARINGFINAL_USERREPOSITORY_H

#include "../Models/User.h"
#include "vector"

class UserRepository {
private:
    std::vector<User> users;
    std::string fileName;

    void readFromCsv();

    void writeToCsv();

public:
    UserRepository(std::string fileName);

    User findUserByEmail(std::string searchedEmail);

    void createUser(int id, std::string email, std::string password, std::string fisrtName, std::string lastName);

    void deleteUser(int userId);

    void updateUser(User& updatedUser);

};


#endif //CARSHARINGFINAL_USERREPOSITORY_H
