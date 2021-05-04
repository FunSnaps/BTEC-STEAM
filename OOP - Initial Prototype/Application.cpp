#include "Application.h"
#include <iostream>

Application::Application()
    : currentAccount(nullptr), currentUser(nullptr)
{
}

Application::~Application()
{

    for (int i = 0; i < 1; ++i)
    {
        accounts.deleteFirst();
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

Player* Application::GetCurrentUser() const
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
    currentAccount = accounts.first();


    return true;
}

bool Application::LoginUser(const std::string& username, const std::string& password)
{
    // TODO: This currently always logs you in as the first user
    //currentUser = currentAccount->users[0];

    return true;
}

void Application::LogoutUser()
{
    currentUser = nullptr;
}

Account* Application::GetAccount(const int& index) const
{
    if (!(accounts.isEmpty() && accounts.length() < index))
    {
        return accounts[index];
    }
}

void Application::addAccount(Account* account)
{
    this->accounts.addInFront(account);
}

void Application::Load()
{

    std::ifstream file("data.txt");
    std::string string;

    while (getline(file, string))
    {
        if (string == "GAME")
        {
            std::string name;
            std::string description;
            int cost;
            int ageRating;

            for (int i = 0; i < 5; i++)
            {
                getline(file, string);
                switch (i)
                {
                case 0: break;
                case 1:
                    name = string;
                    break;
                case 2:
                    description = string;
                    break;
                case 3:
                    ageRating = std::stoi(string);
                    break;
                case 4:
                    cost = std::stoi(string);
                    break;

                default:
                    //return false;
                    break;
                }
            }
            GetStore().addGame(new Game(name, description, cost, ageRating));
        }
        else if (string == "ACCOUNT")
        {
            int day, month, year;

            std::string email = " ";
            std::string password = " ";

            for (int i = 0; i < 3; i++)
            {
                getline(file, string);
                switch (i)
                {
                case 0:
                    day = std::stoi(string.substr(0, string.find("-")));
                    month = std::stoi(string.substr(5, string.find("-")));
                    year = std::stoi(string.substr(8, string.find("-")));
                    break;
                case 1:
                    email = string;
                    break;
                case 2:
                    password = string;
                    break;
                default:
                    //return false;
                    break;
                }
            }
            Date date(day, month, year);
            accounts.addInFront(new Account(email, password, date));
        }
        else if (string == "LIBRARY-ITEM")
        {
            int id, day, month, year, minutes;
            for (int i = 0; i < 3; i++)
            {
                getline(file, string);
                switch (i)
                {
                case 0:
                    id = std::stoi(string);
                case 1:
                    day = std::stoi(string.substr(0, string.find("-")));
                    month = std::stoi(string.substr(5, string.find("-")));
                    year = std::stoi(string.substr(8, string.find("-")));
                    break;
                case 2:
                    minutes = std::stoi(string);
                    break;
                default:
                    //return false;
                    break;
                }
            }
            Date date = Date(day, month, year);
            
        }
    }




    /*for each (std::string stuff in app.GetStore().games)
    {
        std::cout << stuff << std::endl;
    }*/
}
void Application::Save()
{
}
