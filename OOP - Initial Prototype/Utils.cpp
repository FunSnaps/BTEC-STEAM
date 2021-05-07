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

    std::string word = title;
    std::string upper;

    for (int i = 0; i < word.length(); i++)
    {
        if (word.at(i) >= 97 && word.at(i) <= 122)
        {
            upper += (word.at(i) - 32);
        }

        else {
            upper += word.at(i);
        }
    }

    return upper;
}

std::string Utils::toLower(std::string name)
{
    std::for_each(name.begin(), name.end(), [](char& c) {
        c = ::tolower(c);
        });

    return name;
}

bool Utils::startsWith(std::string f, std::string s)
{
    return f.find(s);
}

std::vector<std::string> Utils::split(std::string s, std::string delimiter)
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

const std::string Utils::formatTime(double time, std::string name)
{
    std::stringstream timeString;
    if (time <= 60)
    {
        timeString << std::left << std::setfill(' ') << std::setw(15) << name << std::setprecision(2) << time << " minutes.";
    }
    else if (time >= 60 && time < 300)
    {
        double temp = time / 60.00f;
        timeString << std::left << std::setfill(' ') << std::setw(15) << name << std::setprecision(2) << temp << " hours.";
    }
    else if (time >= 300)
    {
        int temp = time / 60;
        timeString << std::left << std::setfill(' ') << std::setw(15) << name << std::setprecision(2) << temp << " hours.";
    }

    return timeString.str();
}

void Utils::ToUpperRec(char title[])
{
    if (title[0] == '\0') {
        return;
    }
    title[0] = toupper(title[0]);
    ToUpperRec(title + 1);
}