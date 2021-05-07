#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cctype>
#include <algorithm>
#include <sstream>

class Utils
{
  public:
    static std::string getLineFromUser();
    static char getCharFromUser();
    
    static std::string ToUpper(std::string& title);
    static void ToUpperRec(char title[]);

    static std::string toLower(std::string name);
    static bool startsWith(std::string fullText, std::string searchText);
    static const std::string formatTime(double time, std::string name);
    static std::vector<std::string> split(std::string s, std::string delimiter);

};