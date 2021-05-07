#include <iostream>
#include <string>
#include "Application.h"
#include "Account.h"
#include "User.h"
#include "Player.h"
#include "Admin.h"
#include "Utils.h"


#include "MainMenu.h"
#include "Source.h"

void main()
{	
	Application app;

	app.Load();
	
	MainMenu("MAIN MENU", &app); 

	app.Save();
}