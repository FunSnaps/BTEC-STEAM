#include "User.h"

User::User(const std::string& username, const std::string& password, const std::string& created, const int& credit)
    : username(username), password(password), created(created), credit(credit)
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

const int& User::getCredit() const
{
    return credit;
}