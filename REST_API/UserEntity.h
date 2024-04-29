#include <string>

class UserEntity {
public:
    UserEntity(unsigned int id, std::string name, unsigned int age);
    UserEntity(std::string name, unsigned int age);
    std::string toString();
    void setId(unsigned int id);

private:
    unsigned int _id;
    std::string _name;
    unsigned int _age;
};