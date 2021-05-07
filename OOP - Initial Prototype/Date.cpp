#include "Date.h"

Date::Date() : day(0), month(0), year(0) 
{
}

Date::Date(int dd, int mm, int yyyy) : day(dd), month(mm), year(yyyy)
{
	assert(isValid()); 
}

Date::Date(const Date& d) : day(d.day), month(d.month), year(d.year) 
{

}

Date::~Date()
{
}

const std::string Date::getYear() const
{
	return std::to_string(year);
}

const std::string Date::getMonth() const
{
	return std::to_string(month);
}

const std::string Date::getDay() const
{
	return std::to_string(day);
}

bool Date::isBefore(const Date& other) const
{
	if (other.year < year) {
		return true;
	}
	else if (other.year == year && other.month < month) {
		return true;
	}
	else if (other.year == year && other.month == month && other.day < day) {
		return true;
	}

	return false;
}

bool Date::operator<(const Date& other) const 
{
	if (other.year < year) {
		return true;
	}
	else if (other.year == year && other.month < month) {
		return true;
	}
	else if (other.year == year && other.month == month && other.day < day) {
		return true;
	}

	return false;
}

bool Date::isAfter(const Date& other) const
{
	if (other.year > year) {
		return true;
	}
	else if (other.year == year && other.month > month) {
		return true;
	}
	else if (other.year == year && other.month == month && other.day > day) {
		return true;
	}

	return false;
}

bool Date::operator>(const Date& other) const 
{
	if (other.year > year) {
		return true;
	}
	else if (other.year == year && other.month > month) {
		return true;
	}
	else if (other.year == year && other.month == month && other.day > day) {
		return true;
	}

	return false;
}

bool Date::isSame(const Date& other) const
{
	if (other.day == day && other.month == year && other.year == year) {
		return true;
	}
	else {
		return false;
	}
}

bool Date::operator==(const Date& other) const 
{
	if (other.day == day && other.month == year && other.year == year) {
		return true;
	}
	else {
		return false;
	}
}

bool Date::isDifferent(const Date& other) const
{
	if (other.day != day && other.month != month && other.year != year) {
		return true;
	}
	return false;
}

bool Date::operator!=(const Date& other) const 
{
	if (other.day != day && other.month != month && other.year != year) {
		return true;
	}
	return false;
}

bool Date::isValid() const
{
	if ((day > 0 && day <= 31) && (month > 0 && month <= 12) && (year > 0 && year <= 2030)) {
		return true;
	}
	return false;
}

void Date::setDate(int dd, int mm, int yyyy)
{
	day = dd;
	month = mm;
	year = yyyy;
}

const std::string& Date::getDate() const
{
	std::string temp = getYear() + "-" + getMonth() + "-" + getDay();
	return temp;
}



#pragma warning(disable : 4996)
Date* Date::CurrentDate() {

	time_t now = time(0);
	tm* ltm = localtime(&now);
	int year = 1900 + ltm->tm_year;
	int month = 1 + ltm->tm_mon;
	int day = ltm->tm_mday;
	Date* date = new Date(day, month, year);
	return date;
}