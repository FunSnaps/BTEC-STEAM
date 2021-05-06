#pragma once
#include "assert.h"
#include <iostream>
#include <ctime>
class Date
{
public:
	//constructors + destructor
	Date(); //default
	Date(int dd, int mm, int yyyy);
	Date(const Date&); //copy
	~Date(); //destructor

	//query
	int getYear() const;
	int getMonth() const;
	int getDay() const;

	bool isBefore(const Date& other) const;
	bool operator < (const Date& other) const; //operator overload for isBefore

	bool isAfter(const Date& other) const;
	bool operator > (const Date& other) const; //operator overload for isAfter

	bool isSame(const Date& other) const;
	bool operator == (const Date& other) const; //operator overload for isSame

	bool isDifferent(const Date& other) const;
	bool operator != (const Date& other) const; //operator overload for isDifferent

	bool isValid() const;
	//mutate
	void setDate(int dd, int mm, int yy);

	Date* CurrentDate();
private:
	int year, month, day;
};

