#include "UserRepository.h"
#include "fstream"
#include "sstream"

void UserRepository::readFromCsv() {
    this->users.clear();
    std::ifstream file(fileName);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string id, email, password, firstName, lastName;
            std::getline(ss, id, ',');
            int idInt = std::stoi(id);
            std::getline(ss, email, ',');
            std::getline(ss, password, ',');
            std::getline(ss, firstName, ',');
            std::getline(ss, lastName, ',');

            users.emplace_back(idInt, email, password, firstName, lastName);

        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << fileName << std::endl;
    }
}

void UserRepository::writeToCsv() {
    std::ofstream file(fileName);
    if (file.is_open()) {
        for (User &user: users) {
            file << user.getUserId() << ","
                 << user.getUserEmail() << ","
                 << user.getUserPassword() << ","
                 << user.getUserFirstName() << ","
                 << user.getUserLastName() << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << fileName << std::endl;
    }
}


UserRepository::UserRepository(std::string fileName) {
    this->fileName = fileName;
    readFromCsv();
}


//iterates through user vector and searches for the target email
User UserRepository::findUserByEmail(std::string searchedEmail) {
    for (User obj: this->users) {
        if (obj.getUserEmail() == searchedEmail)
            return obj;
    }
}

void UserRepository::createUser(int id, std::string email, std::string password, std::string fisrtName,
                                std::string lastName) {
    User newUser(id, email, password, fisrtName, lastName);
    users.push_back(newUser);
    writeToCsv();

}

//iterates through user vector and deletes the searched user
void UserRepository::deleteUser(int userId) {
    for (auto it = this->users.begin(); it != this->users.end(); ++it) {
        if (it->getUserId() == userId) {
            this->users.erase(it);
            break;
        }
    }
    writeToCsv();
}

//iterates through user vector and modifies the attributes of a specified user
void UserRepository::updateUser(User &updatedUser) {
    readFromCsv();

    for(auto &user:users){
        if(user.getUserId() == updatedUser.getUserId()){
            user = updatedUser;

            writeToCsv();
            return;
        }
    }

    std::cerr << "User with id "<<updatedUser.getUserId() << " not found for updating." << std::endl;

}


