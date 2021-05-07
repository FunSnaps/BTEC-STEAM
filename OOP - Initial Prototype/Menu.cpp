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

void Menu::OptionCost(const double& cost)
{
    std::stringstream format;
    std::cout << format.str() << "  " << "Credit: " << std::setprecision(5) << cost / 1.00f << '\n';
}

void Menu::OptionPrice(const double& cost)
{
    std::stringstream format;
    std::cout << format.str() << "  " << "Price: " << std::setprecision(5) << cost / 100.00f << '\n';
}

void Menu::OptionInfo(const std::string& infoText)
{
    std::cout << "  " << "Info:" << infoText << '\n';
}

void Menu::OptionPlain(const std::string& plainText)
{
    std::cout << "  " << plainText << '\n';
}

void Menu::OptionRating(const std::string& infoText)
{
    std::cout << "  " << "Rating: " << infoText << '\n';
}

void Menu::Option(const int& id, const std::string& option)
{
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
    system("CLS");
#else
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

