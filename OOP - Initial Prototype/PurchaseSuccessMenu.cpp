#include "PurchaseSuccessMenu.h"

PurchaseSuccessMenu::PurchaseSuccessMenu(const std::string& title, Application* app, const int& index) : Menu(title, app), index(index)
{
    Paint();
}

void PurchaseSuccessMenu::OutputOptions()
{
    Line("You have purchased the game!");
    Line("-----------------------------");
    Line();
    Line();
    Line("Your new credit is: ");
    OptionCost(app->GetCurrentUser()->getCredit());
}

bool PurchaseSuccessMenu::HandleChoice(char choice)
{
    switch (choice) {
    case 'P':
    {
        Date* date = d->CurrentDate();
        Game game = app->GetStore().getIndex(index);
        LibraryItem* item = new LibraryItem(date, game);
        app->GetCurrentUser()->buyGame(app->GetStore().getIndex(index).GetCost());
        app->GetCurrentUser()->addLibraryItem(item);
        Option(index + 1, app->GetStore().getIndex(index).GetName());
    }   break;
    default:
        break;
    }

    return false;

}

