#include "GameBuyMenu.h"

GameBuyMenu::GameBuyMenu(const std::string& title, Application* app, const int& index) : Menu(title, app), index(index)
{
    Paint();
}

void GameBuyMenu::OutputOptions()
{
    Option(app->GetStore().getIndex(index).GetDescription());
    Line();
    Option("Cost - ");
    printInt(app->GetStore().getIndex(index).GetCost());
    Line();
    Option("Current Credit - ");
    printInt(app->GetCurrentUser()->getCredit());
    Line();
    Line();
    Option("P) Purchase Game");
}


bool GameBuyMenu::HandleChoice(char choice)
{
    switch (choice) {
    case 'P':
    {
        system("CLS");
        //create instance of library item to push into users library
        Date* date = d->CurrentDate();
        Game game = app->GetStore().getIndex(index);
        LibraryItem* item = new LibraryItem(date, game);

        //take cost away from users balance
        app->GetCurrentUser()->buyGame(app->GetStore().getIndex(index).GetCost());

        //push to users library
        app->GetCurrentUser()->addLibraryItem(item);

        Option("You have purchased the game!");
        Option("-----------------------------");
        Line();
        Line();
        Option("Your new credit is - ");
        printInt(app->GetCurrentUser()->getCredit());
        Line();
        Line();
        Option("B) Back");

        Utils::getCharFromUser();
        return true;

    } break;
    default:
        break;
    }
    return false;
}