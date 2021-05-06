#include "Utils.h"


std::string Utils::getLineFromUser()
{
    std::string input;
    std::getline(std::cin, input);
    return input;
}

char Utils::getCharFromUser()
{
    return toupper(getLineFromUser()[0]);
}

std::string Utils::ToUpper(std::string& title)
{
    //std::transform(title.begin(), title.end(), title.begin(), ::toupper);

    std::string word = title;
    std::string upper;

    for (int i = 0; i < word.length(); i++)
    {
        if (word.at(i) >= 97 && word.at(i) <= 122)
        {
            upper += (word.at(i) - 32); //lower case ascii value of a is 97, sub 32 is uppercase A (65)
        }                               //idk how to return a putchar value 
        else {
            upper += word.at(i);
        }
    }

    return upper;
}

std::string Utils::ToUpperRec(std::string& title)
{
    //check if we have letters
    int i = 0;
    if (title[i] >= title.length())
    {
        title[i] = toupper(title[i]);
        i++;
    }
    return ToUpperRec(title);
}

