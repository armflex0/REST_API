#include "UserRepository.h"
class UserService {
public:
    UserEntity* addUser(UserEntity* user);
    UserEntity* getUser(unsigned int id);
    std::map<unsigned int, UserEntity*> getAllUsers();
    bool deleteUser(unsigned int id);
};