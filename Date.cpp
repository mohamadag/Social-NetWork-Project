#include"Date.h"
constexpr short MONTH = 30;
constexpr short YEAR = 365;
Date::Date(short  day, short month, short year) :day(day), month(month), year(year)
{}

Date::Date()
{
	SYSTEMTIME now;
	GetLocalTime(&now);
	this->day = now.wDay;
	this->month = now.wMonth;
	this->year = now.wYear;
}

void Date::show() const
{
	cout << this->getDay() << "/" << this->getMonth() << "/" << this->getYear();
}

short Date::getDay() const
{
	return this->day;
}

short Date::getMonth() const
{
	return this->month;
}

short Date::getYear() const
{
	return this->year;
}
