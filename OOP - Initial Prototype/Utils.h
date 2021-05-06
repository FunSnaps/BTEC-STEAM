#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <cctype>

class Utils
{
  public:
    static std::string getLineFromUser();
    static char getCharFromUser();
    
    static std::string ToUpper(std::string& title);
    static std::string ToUpperRec(std::string& title);
};