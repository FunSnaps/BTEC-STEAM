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
    //add try catch
    std::ifstream file("data.txt");
    std::string string;
    std::string email = " ";
    std::string username = " ";
    std::string password = " ";
    int credit;

    while (getline(file, string))
    {
        if (string == "GAME")
        {
            std::string name;
            std::string description;
            int id;
            int cost;
            int ageRating;

            for (int i = 0; i < 5; i++)
            {
                getline(file, string);
                switch (i)
                {
                case 0: 
                    id = std::stoi(string); //should be ID but dunno where to use maybe search?
                    break;
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
                    minutes = std::stoi(string); //needs to be somewhere 
                    break;
                default:
                    //return false;
                    break;
                }
            }
            Date date = Date(day, month, year);
            Game game = Game(GetStore().getIndex(id));
            Player* player = dynamic_cast<Player*>(accounts[0]->users[0]); //in order to access the player's add func.
            LibraryItem* item = new LibraryItem(date, game);
            player->addLibraryItem(item);
        }
        else if (string == "ACCOUNT-PLAYER")
        {
            int day, month, year;

            for (int i = 0; i < 4; i++) {
                getline(file, string);
                switch (i)
                {
                case 0:
                    day = std::stoi(string.substr(0, string.find('-')));
                    month = std::stoi(string.substr(5, string.find('-')));
                    year = std::stoi(string.substr(8, string.find('-')));
                    break;
                case 1:
                    username = string;
                    break;
                case 2:
                    password = string;
                    break;
                case 3:
                    credit = std::stoi(string);
                    break;
                default:
                    //return false;
                    break;
                }
            }
            Date date(day, month, year);
            Player* player = new Player(username, password, date, credit);
            accounts[0]->users.addInFront(player);
        }
        else if (string == "ACCOUNT-ADMIN")
        {
            int day;
            int month;
            int year;

            for (int i = 0; i < 3; i++) {

                getline(file, string);

                switch (i)
                {

                case 0:
                    day = std::stoi(string.substr(0, string.find('-')));
                    month = std::stoi(string.substr(5, string.find('-')));
                    year = std::stoi(string.substr(8, string.find('-')));
                    break;
                case 1:
                    username = string;
                    break;
                case 2:
                    password = string;
                    break;
                case 3:
                    credit = std::stoi(string);
                    break;
                default:
                    //return false;
                    break;
                }
            }
            Date date(day, month, year);
            Player* player = new Player(username, password, date, credit);
            accounts[0]->users.addInFront(player);
        }
    }
    file.close();
}
void Application::Save()
{
}
