#include <map>
#include "UserEntity.h"

class UserRepository {
public:
    UserEntity* addUser(UserEntity* user);
    UserEntity* getUser(unsigned int id);
    std::map<unsigned int, UserEntity*> getAllUsers();
    bool deleteUser(unsigned int id);
};