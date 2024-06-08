//
// Created by Darius on 5/27/2024.
//

#include "UserController.h"

User UserController::findUserByEmail(std::string searchedEmail) {
    return this->userRepo.findUserByEmail(searchedEmail);
}

void UserController::addUser(int id, std::string email, std::string password, std::string fisrtName, std::string lastName) {
    this->userRepo.createUser(id, email, password, fisrtName, lastName);
}

void UserController::deleteUser(int userId) {
    this->userRepo.deleteUser(userId);
}

void UserController::updateUser(User &updatedUser) {
    this->userRepo.updateUser(updatedUser);
}
