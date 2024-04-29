#include "UserRepository.h"

std::map<unsigned int, UserEntity*> users;

UserEntity* UserRepository::addUser(UserEntity* user) {
    unsigned int id = !users.empty() ? users.rbegin()->first + 1 : 0;

    user->setId(id);
    users[id] = user;
    return user;
}

bool UserRepository::deleteUser(unsigned int id) {
    return users.erase(id);
}

std::map<unsigned int, UserEntity*> UserRepository::getAllUsers() {
    return users;
}

UserEntity* UserRepository::getUser(unsigned int id) {
    return !users.empty() ? users[id] : nullptr;
}