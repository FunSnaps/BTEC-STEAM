#pragma once

#include "Utils.h"
#include "Application.h"
#include <sstream>
#include <iomanip>
#include <iostream>
#include <string>

class Menu
{
public:
    Menu(const std::string& title, Application* app);

    void Paint();

    virtual void OutputOptions() = 0;

    virtual bool HandleChoice(char) = 0;
protected:

    Application* app;                                  
                                                        
    void Line();										
    void Line(const std::string& text);					
    void Option(const int& id, const std::string& option);		
    void Option(const char& id, const std::string& option);	
    void OptionCost(const double& cost);                            
    void OptionPrice(const double& cost);
    void OptionInfo(const std::string& infoText);
    void OptionPlain(const std::string& plainText);
    void OptionRating(const std::string& infoText);
    std::string Question(const std::string& question);	
    void BlockingMessage(const std::string& message);	
private:
    std::string title;

    void Header();
    void Footer();
};