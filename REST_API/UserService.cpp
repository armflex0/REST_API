#include "UserService.h"

UserRepository* userRepository = new UserRepository();

UserEntity* UserService::addUser(UserEntity* user) {
    return userRepository->addUser(user);
}

bool UserService::deleteUser(unsigned int id) {
    return userRepository->deleteUser(id);
}

std::map<unsigned int, UserEntity*> UserService::getAllUsers() {
    return userRepository->getAllUsers();
}

UserEntity* UserService::getUser(unsigned int id) {
    return userRepository->getUser(id);
}