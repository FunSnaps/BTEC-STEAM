#include "User.h"

User::User(const std::string& username, const std::string& password, const Date& created, const int& something)
    : username(username), password(password), created(created), something(something)
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

const int& User::getSomething() const
{
    return something;
}