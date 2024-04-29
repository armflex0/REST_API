#include "UserEntity.h"

UserEntity::UserEntity(unsigned int id, std::string name, unsigned int age)
{
    _id = id;
    _name = name;
    _age = age;
}

UserEntity::UserEntity(std::string name, unsigned int age)
{
    _id = -1;
    _name = name;
    _age = age;
}
void UserEntity::setId(unsigned int id) {
    _id = id;
}

std::string UserEntity::toString()
{
    return "Id: " + std::to_string(_id) + "" + ", Name: " + _name + ", Age: " + std::to_string(_age);
}
