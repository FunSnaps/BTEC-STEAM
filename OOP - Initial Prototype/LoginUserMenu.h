#pragma once

#include "Menu.h"
#include "ListT.h"
#include "StoreMenu.h"
#include "MainMenu.h"

class LoginUserMenu : public Menu
{
public:
    LoginUserMenu(const std::string& title, Application* app);
    void OutputOptions() final;
    bool HandleChoice(char choice) final;
};

