#include "Application.h"
#include <iostream>

Application::Application() : currentAccount(nullptr), currentUser(nullptr)
{
}

Application::~Application()
{
    for (int i = 0; i < 1; ++i)
    {
        delete accounts[i];
    }
}

bool Application::IsUserLoggedIn() const
{
    return currentUser != nullptr;
}

bool Application::IsAccountLoggedIn() const
{
    return currentAccount != nullptr;
}

Account* Application::GetCurrentAccount() const
{
    return currentAccount;
}

User* Application::GetCurrentUser() const
{
    return currentUser;
}

Store& Application::GetStore()
{
    return store;
}

bool Application::LoginAccount(const std::string& email, const std::string& password)
{
    // TODO: This currently always logs you in as the first account
    currentAccount = accounts[0];

    return true;
}

bool Application::LoginUser(const std::string& username, const std::string& password)
{
    // TODO: This currently always logs you in as the first user
    currentUser = currentAccount->users[0];

    return true;
}

void Application::LogoutUser()
{
    currentUser = nullptr;
}

void Application::Load() const
{
    Application app;

    std::vector<std::string> vec;
    std::ifstream file("data.txt");
    std::string string;

    while (file >> string)
    {    
        app.GetStore().games.addInFront(string);
        //put all items in txt to vector
    }

    for each (std::string stuff in app.GetStore().games)
    {
        std::cout << stuff << std::endl; 
    }
    
    //std::copy(app.GetStore().games2.begin(), app.GetStore().games2.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
}
void Application::Save()
{
}
