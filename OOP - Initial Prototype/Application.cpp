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

bool Application::LoginAccount(const std::string& email, const std::string& password, int& index)
{

    if (password == accounts.operator[](index)->GetPassword()) {
        currentAccount = accounts.operator[](index);
        return true;
    }
    else return false;
    

}

bool Application::LoginUser(const std::string& username, const std::string& password, int& index)
{

    if (password == currentAccount->users.operator[](index)->GetPassword()) {
        currentUser = currentAccount->users[index];


        return true;
    }
    else return false;
    
    
}

void Application::LogoutUser()
{
    currentUser = nullptr;
}

void Application::LogoutAccount() {
    currentAccount = nullptr;
}

void Application::addAccount(Account* account)
{
    this->accounts.addInFront(account);
}


List<Account*> Application::GetAccounts() const {
    return accounts;
}

bool Application::Load() 
{
    try{
        std::ifstream theFile("data2.txt");
        if (theFile.is_open()) {
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
                    int rating;
                    int likes;
                    int dislikes;

                    for (int i = 0; i < 7; i++) {
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
                            likes = std::stoi(line);
                            break;
                        case 6:
                            dislikes = std::stoi(line);
                            break;
                        default:
                            return false;
                            break;
                        }
                    }
                    
                    if (likes != 0 && dislikes != 0) {
                        rating = ((static_cast<double>(likes) / (static_cast<double>(dislikes) + static_cast<double>(likes))) * 100);
                    }
                    else if (likes > 0 && dislikes == 0) {
                        rating = 100;
                    }
                    else {
                        rating = 0;
                    }
                    GetStore().addGame(new Game(id, name, description, cost, ageRating, rating, likes, dislikes));
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
                            day = std::stoi(line.substr(7, line.find("-")));
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
                            day = std::stoi(line.substr(7, line.find("-")));
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

                            day = std::stoi(line.substr(7, line.find("-")));
                            month = std::stoi(line.substr(5, line.find("-")));
                            year = std::stoi(line.substr(0, line.find("-")));
                            break;
                        case 1:
                            email = line;
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
                            day = std::stoi(line.substr(7, line.find("-")));
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
        }
    }
    catch (const std::exception&) 
    {
        return false;
    }
}


void Application::Save()
{
    std::ofstream file;

    file.open("data2.txt", std::fstream::out | std::fstream::trunc);

    if (file.is_open())
    {
        if (GetStore().GetGames().length() > 0)
        {
            for (int i = 0; i < GetStore().GetGames().length(); i++) {
                file << "GAME" << std::endl;
                file << i << std::endl;
                file << GetStore().GetGames()[i]->GetName() << std::endl;
                file << GetStore().GetGames()[i]->GetDescription() << std::endl;
                file << GetStore().GetGames()[i]->GetCost() << std::endl;
                file << GetStore().GetGames()[i]->GetAgeRating() << std::endl;
                file << GetStore().GetGames()[i]->GetLikes() << std::endl;
                file << GetStore().GetGames()[i]->GetDislikes() << std::endl;
            }
        }
        if (accounts.length() > 0) {
            for (int i = 0; i < accounts.length(); i++)
            {
                file << "ACCOUNT" << std::endl;
                file << accounts[i]->GetCreated()->getYear() + "-" + accounts[i]->GetCreated()->getMonth() + "-" + accounts[i]->GetCreated()->getDay() << std::endl;
                file << accounts[i]->GetEmail() << std::endl;
                file << accounts[i]->GetPassword() << std::endl;

                if (accounts[i]->GetUsers().length() > 0)
                {
                    List<Player*> users = accounts[i]->GetUsers();

                    for (int y = 0; y < users.length(); y++)
                    {
                        if (accounts[i]->GetUsers()[y]->GetUserStatus()) {
                            file << "ACCOUNT-ADMIN" << std::endl;
                        }
                        else {
                            file << "ACCOUNT-PLAYER" << std::endl;
                        }
                        file << users[y]->GetCreated()->getYear() + "-" + users[y]->GetCreated()->getMonth() + "-" + users[y]->GetCreated()->getDay() << std::endl;
                        file << users[y]->GetUsername() << std::endl;
                        file << users[y]->GetPassword() << std::endl;
                        file << std::to_string(users[y]->GetCredit()) << std::endl;

                        if (dynamic_cast<Player*>(accounts[i]->GetUsers()[y])->getLibraryItems().size() > 0)
                        {
                            std::vector<LibraryItem*> libraryItems = dynamic_cast<Player*>(accounts[i]->GetUsers()[y])->getLibraryItems();
                            for (int j = 0; j < libraryItems.size(); j++)
                            {
                                file << "LIBRARY-ITEM" << std::endl;
                                file << std::to_string(libraryItems[j]->getGame().GetID()) << std::endl;
                                file << libraryItems[j]->GetDatePurchased()->getYear() + "-" + libraryItems[j]->GetDatePurchased()->getMonth() + "-" + libraryItems[j]->GetDatePurchased()->getDay() << std::endl;
                                file << std::to_string(libraryItems[j]->getHours()) << std::endl;
                            }
                        }
                    }
                }

            }
        }
    }
    file.close();
}

