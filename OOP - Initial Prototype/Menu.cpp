#include "Menu.h"

Menu::Menu(const std::string& title, Application* app) 
    : title(title), app(app)
{
}

void Menu::Paint()
{
    bool readyToGoBack = false;

    while (!readyToGoBack)
    {
        Header();
        OutputOptions();
        Line();
        Option('B', "Back");
        Footer();

        char choice = Utils::getCharFromUser();

        if (choice == 'B')
        {
            readyToGoBack = true;
        }
        else
        {
            readyToGoBack = HandleChoice(choice);
        }
    }
}

void Menu::Line()
{
    std::cout << '\n';
}

void Menu::Line(const std::string& text)
{
    std::cout << "  " << text << "\n";
}

void Menu::Option(const char& id, const std::string& option)
{
    std::cout << "  " << id << ") " << option << '\n';
}

void Menu::Option(const int& id, const std::string& option)
{
    // shift the integer value up to the correct position in the ascii table
    char ascii = id + '0';
    Option(ascii, option);
}

std::string Menu::Question(const std::string& question)
{
    std::cout << "  " << question << ": ";
    return Utils::getLineFromUser();
}

void Menu::BlockingMessage(const std::string& message)
{
    std::cout << "  " << message;
    Utils::getLineFromUser();
}

void Menu::Header()
{

#if defined _WIN32 || defined _WIN64
    // we are running on windows so use CLS to clear the screen
    system("CLS");
#else
    // we are running on mac or linux so use CLEAR to clear the screen
    system("CLEAR");
#endif

    std::cout << '\n';
    std::cout << "  -= " << title << " =-  \n";
    std::cout << '\n';
}

void Menu::Footer()
{
    std::cout << '\n';
    std::cout << '\n';
    std::cout << "  >>> ";
}