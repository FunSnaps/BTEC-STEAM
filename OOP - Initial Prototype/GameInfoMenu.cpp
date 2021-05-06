#include "GameInfoMenu.h"

GameInfoMenu::GameInfoMenu(const std::string& title, Application* app, const int& index) : Menu(title, app), index(index)
{
    Paint();
}

void GameInfoMenu::OutputOptions()
{
    if (index == 'N')
    {
        for (int i = 5; i < app->GetStore().GetGames().length(); i++)
        {
            Option(i + 1, app->GetStore().getIndex(i).GetName());           // 2 hours :D -marcus
        }                                                                   // + 4 hours :)
        Line();
    }
    else
    {
        if (index < 5 || index > 4) {
            Option(app->GetStore().getIndex(index).GetDescription());
            Line();
            Option(app->GetStore().getIndex(index).GetCost());
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