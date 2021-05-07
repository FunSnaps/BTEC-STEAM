#include "GameBuyMenu.h"

GameBuyMenu::GameBuyMenu(const std::string& title, Application* app, const int& index) : Menu(title, app), gameIndex(index)
{
    Paint();
}

void GameBuyMenu::OutputOptions()
{
    if (gameIndex == 'N')
    {
        for (int i = 5; i < app->GetStore().GetGames().length(); i++)
        {
            Option(i + 1, app->GetStore().getIndex(i).GetName());
        }
    }
    else
    {
        if (gameIndex < 5 || gameIndex > 4) {
            OptionInfo(app->GetStore().getIndex(gameIndex).GetDescription());
            OptionRating(std::to_string(app->GetStore().GetGames()[gameIndex]->GetRating()) + "%");
            Line();
            OptionPrice(app->GetStore().getIndex(gameIndex).GetCost());
            Line();
            Line("Current Credit: ");
            OptionCost(app->GetCurrentUser()->getCredit());
            Line();

            std::string b = app->GetStore().getIndex(gameIndex).GetName();

            for (int i = 0; i < app->GetCurrentUser()->getLibraryItems().size(); i++) {
                if (b == app->GetCurrentUser()->getLibraryItems().operator[](i)->getGame().GetName()) {
                    Line("You already own this game!");
                    line = true;
                }
            }

            if (!line) {
                Line("P) Purchase Game");
            }
            Line();
            Line("S) Search");
        }
    }
}


bool GameBuyMenu::HandleChoice(char choice)
{
    int index = choice - '1';
    if (index >= 5 && index < app->GetStore().GetGames().length())
    {
        std::string temp = app->GetStore().getIndex(index).GetName();
        GameBuyMenu(utils.ToUpper(temp), app, index);
    }

    switch (choice) {
    case 'P':
    {
        if (!line) {
            Date* date = d->CurrentDate();
            Game game = app->GetStore().getIndex(gameIndex);
            LibraryItem* item = new LibraryItem(date, game);
            app->GetCurrentUser()->buyGame(app->GetStore().getIndex(gameIndex).GetCost());
            app->GetCurrentUser()->addLibraryItem(item);
            Option(gameIndex + 1, app->GetStore().getIndex(gameIndex).GetName());

            PurchaseSuccessMenu("PURCHASE", app, gameIndex);

        }
    } break;
    case 'B':
    {
        SearchMenu("SEARCH", app);
    }
    default:
        break;
    }
    return false;
}

