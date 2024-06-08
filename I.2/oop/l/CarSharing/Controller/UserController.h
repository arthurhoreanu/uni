//
// Created by Darius on 5/27/2024.
//

#ifndef CARSHARINGFINAL_USERCONTROLLER_H
#define CARSHARINGFINAL_USERCONTROLLER_H

#include "../Repository/UserRepository.h"

class UserController {
private:
    UserRepository userRepo;
public:
    UserController(const std::string &filename) : userRepo(filename) {}

    User findUserByEmail(std::string searchedEmail);

    void addUser(int id, std::string email, std::string password, std::string fisrtName, std::string lastName);

    void deleteUser(int userId);

    void updateUser(User &updatedUser);
};


#endif //CARSHARINGFINAL_USERCONTROLLER_H
