#include "User.h"

User::User(const std::string& username, const std::string& password, const std::string& created)
    : username(username), password(password), created(created)
{
}

User::~User()
{

}

const std::string& User::GetUsername() const
{
    return username;
}

const bool& User::GetUserStatus() const
{
    return userStatus;
}