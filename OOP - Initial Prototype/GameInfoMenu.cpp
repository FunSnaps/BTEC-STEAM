#include "GameInfoMenu.h"

GameInfoMenu::GameInfoMenu(const std::string& title, Application* app, const int& index) : Menu(title, app), gameIndex(index)

{
    Paint();
}

void GameInfoMenu::OutputOptions()
{
    if (gameIndex == 'N')
    {
        for (int i = 5; i < app->GetStore().GetGames().length(); i++)
        {
            Option(i + 1, app->GetStore().getIndex(i).GetName());           
        }                                                                   
        Line();
    }
    else
    {
        if (gameIndex < 5 || gameIndex > 4) {
            OptionInfo(app->GetStore().getIndex(gameIndex).GetDescription());
            Line();
            OptionRating(std::to_string(app->GetStore().GetGames()[gameIndex]->GetRating()) + "%");
            OptionCost(app->GetStore().getIndex(gameIndex).GetCost());
        }
    }
}

bool GameInfoMenu::HandleChoice(char choice)
{
    int index = choice - '1';
    if (index >= 5 && index < app->GetStore().GetGames().length())
    {
        std::string temp = app->GetStore().getIndex(index).GetName();
        GameInfoMenu(utils.ToUpper(temp), app, index);                      
    }

    return false;
}