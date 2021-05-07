#pragma once
#include "assert.h"
#include <iostream>
#include <ctime>
#include <string>
class Date
{
public:
	Date(); 
	Date(int dd, int mm, int yyyy);
	Date(const Date&); 
	~Date(); 

	const std::string getYear() const;
	const std::string getMonth() const;
	const std::string getDay() const;

	bool isBefore(const Date& other) const;
	bool operator < (const Date& other) const; 

	bool isAfter(const Date& other) const;
	bool operator > (const Date& other) const; 

	bool isSame(const Date& other) const;
	bool operator == (const Date& other) const; 

	bool isDifferent(const Date& other) const;
	bool operator != (const Date& other) const; 

	bool isValid() const;
	void setDate(int dd, int mm, int yy);
	const std::string& getDate() const;
	Date* CurrentDate();
private:
	int year, month, day;
};

