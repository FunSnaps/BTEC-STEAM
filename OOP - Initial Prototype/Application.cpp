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

void Application::Load() 
{
    std::ifstream theFile("data.txt");
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
                    break;
                }
            }
            int rating;
            if (likes != 0 && dislikes != 0) {
                rating = (likes / (likes + dislikes)) * 100;
            }
            else {
                rating = 0;
            }
            GetStore().addGame(new Game(name, description, cost, ageRating, rating));
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
                    //return false;
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
                    day = std::stoi(line.substr(8, line.find("-")));
                    month = std::stoi(line.substr(5, line.find("-")));
                    year = std::stoi(line.substr(0, line.find("-")));
                    break;
                case 2:
                    playTime = std::stoi(line);
                    break;
                default:
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
                    //return false;
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
                //return false;
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
void Application::Save()
{
}
