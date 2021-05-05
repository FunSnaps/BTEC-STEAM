#include "Application.h"

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

bool Application::LoginUser(const std::string& username, const std::string& password, int& index)
{

    // TODO: This currently always logs you in as the first user
    currentUser = currentAccount->users[index];

    return true;
}

void Application::LogoutUser()
{
    currentUser = nullptr;
}

//Account* Application::GetAccount(const int& index) const
//{
//    if (!(accounts.isEmpty() && accounts.length() < index))
//    {
//        return accounts.first();
//    }
//}

void Application::addAccount(Account* account)
{
    this->accounts.addInFront(account);
}

bool Application::Load()
{

    try
    {
        std::ifstream theFile("data.txt");
        if (theFile.is_open())
        {

            std::string line;

            std::string email = " ";
            std::string username = " ";
            std::string password = " ";
            int credit;

            while (getline(theFile, line)) {
                if (line == "GAME") {
                    int id;
                    std::string name;
                    std::string description;
                    int cost;
                    int ageRating;
                    int likes;
                    int dislikes;

                    for (int i = 0; i < 5; i++) {
                        getline(theFile, line);
                        switch (i) {
                        case 0:
                            id = std::stoi(line);
                            break;
                        case 1:
                            name = line;
                            break;
                        case 2:
                            description = line;
                            break;
                        case 3:
                            cost = std::stoi(line);
                            break;
                        case 4:
                            ageRating = std::stoi(line);
                            break;
                        case 5:
                            //likes = std::stoi(line);
                            break;
                        case 6:
                            //dislikes = std::stoi(line);
                            break;
                        default:
                            return false;
                            break;
                        }
                    }
                    GetStore().addGame(new Game(name, description, cost, ageRating));
                }
                else if (line == "ACCOUNT")
                {
                    int day, month, year;

                    for (int i = 0; i < 3; i++)
                    {
                        getline(theFile, line);
                        switch (i)
                        {
                        case 0:
                            day = std::stoi(line.substr(8, line.find("-")));
                            month = std::stoi(line.substr(5, line.find("-")));
                            year = std::stoi(line.substr(0, line.find("-")));
                            break;
                        case 1:
                            email = line;
                            break;
                        case 2:
                            password = line;
                            break;
                        default:
                            return false;
                            break;
                        }
                    }
                    Date* date = new Date(day, month, year);
                    accounts.addInFront(new Account(email, password, date));
                    LoginAccount(email, password);
                }
                else if (line == "LIBRARY-ITEM") {
                    int id, day, month, year, playTime;

                    for (int i = 0; i < 3; i++) {
                        getline(theFile, line);
                        switch (i) {
                        case 0:
                            id = std::stoi(line);
                            break;
                        case 1:
                            day = std::stoi(line.substr(8, line.find("-")));
                            month = std::stoi(line.substr(5, line.find("-")));
                            year = std::stoi(line.substr(0, line.find("-")));
                            break;
                        case 2:
                            playTime = std::stoi(line);
                            break;
                        default:
                            return false;
                            break;
                        }
                    }
                    Date* date = new Date(day, month, year);
                    Player* user = dynamic_cast<Player*>(accounts.first()->users.first());
                    Game game = Game(GetStore().getIndex(id));
                    LibraryItem* item = new LibraryItem(date, game);
                    user->addLibraryItem(item);
                }
                else if (line == "ACCOUNT-PLAYER")
                {
                    int day, month, year;
                    for (int i = 0; i < 4; i++) {
                        getline(theFile, line);
                        switch (i)
                        {
                        case 0:
                            day = std::stoi(line.substr(8, line.find("-")));
                            month = std::stoi(line.substr(5, line.find("-")));
                            year = std::stoi(line.substr(0, line.find("-")));
                            break;
                        case 1:
                            username = line;
                            break;
                        case 2:
                            password = line;
                            break;
                        case 3:
                            credit = std::stoi(line);
                            break;
                        default:
                            return false;
                            break;
                        }
                    }
                    Date* date = new Date(day, month, year);
                    Player* player = new Player(username, password, date, credit, false);
                    accounts.first()->users.addInFront(player);
                }
                else if (line == "ACCOUNT-ADMIN")
                {
                    int day;
                    int month;
                    int year;
                    for (int i = 0; i < 3; i++) {

                        getline(theFile, line);

                        switch (i)
                        {

                        case 0:
                            day = std::stoi(line.substr(8, line.find("-")));
                            month = std::stoi(line.substr(5, line.find("-")));
                            year = std::stoi(line.substr(0, line.find("-")));
                            break;
                        case 1:
                            username = line;
                            break;
                        case 2:
                            password = line;
                            break;
                        case 3:
                            credit = std::stoi(line);
                            break;
                        default:
                            return false;
                            break;
                        }
                    }
                    Date* date = new Date(day, month, year);
                    Player* player = new Admin(username, password, date, credit, true);
                    accounts.first()->users.addInFront(player);
                }
            }
            theFile.close();
            return true;
        }
    }
    catch (const std::exception&) // <---
    {
        return false;
    }

}
bool Application::Save()
{
    //try {

       //    std::ofstream data;
       //    data.open("sData.txt", std::fstream::out | std::fstream::trunc);

       //    if (data.is_open()) {

       //        List<Game*> games = GetStore().GetGames();

       //        for (int i = 0; i < games.length(); i++) {
       //            data << "GAME" << std::endl;
       //            data << i + 1 << std::endl;
       //            data << games[i]->GetName() << std::endl;
       //            data << games[i]->GetDescription() << std::endl;
       //            data << 0 << std::endl;
       //            data << games[i]->GetCost() << std::endl;
       //        }

       //        for (int i = 0; i < accounts.length(); i++) {
       //            data << "ACCOUNT" << std::endl;
       //            for (int y = 0; y < accounts[i]->users.length();y++) {
       //                /*
       //                if (accounts[i]->users) {
       //                    data << "ACCOUNT-PLAYER" << std::endl;
       //                }
       //                else
       //                {
       //                    data << "ACCOUNT-ADMIN" << std::endl;
       //                }
       //                data << accounts[i]->users[y]->GetUsername() << std::endl;
       //                data << accounts[i]->users[y]->GetUsername() << std::endl;
       //                */

       //            }

       //        }

       //    }

       //    data.close();

       //}
       //catch (...) {

       //}
    return false;
}