#include "User.h"


User::User(const std::string& username, const std::string& password, Date* created, const int& credit, bool userStatus)
    : username(username), password(password), created(created), credit(credit), userStatus(userStatus)
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

const int& User::GetCredit() const
{
    return credit;
}

const std::string& User::GetPassword() const {
    return password;
}

Date* User::GetCreated() const{
    return created;
}