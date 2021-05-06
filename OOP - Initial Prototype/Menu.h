#pragma once

#include "Utils.h"
#include "Application.h"

#include <iostream>
#include <string>

class Menu
{
public:
    Menu(const std::string& title, Application* app);

    void Paint();

    // Use this function to output all the options specific to your menu
    virtual void OutputOptions() = 0;

    // Use this function to handle the possible choices from your menu
    // Returning true means you are ready to go back to the previous menu
    // Returning false means you will stay on the same menu
    virtual bool HandleChoice(char) = 0;

protected:
    Application* app;                                           // each menu will store a pointer to the main application
                                                                // this way menus can access all the data required

    void Line();										        // output blank line
    void Line(const std::string& text);					        // output a message
    void Option(const int& id, const std::string& option);		// output menu option
    void Option(const char& id, const std::string& option);	    // output menu option
    void Option(const int& cost);                               // output menu option int
    void Option(const std::string& text);
    void printInt(const int& num);
    std::string Question(const std::string& question);	        // output a question and return the user's input
    void BlockingMessage(const std::string& message);	        // output message and wait for the user to press enter

private:
    std::string title;

    void Header();
    void Footer();
};