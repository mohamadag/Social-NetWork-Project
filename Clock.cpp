#include"Clock.h"
constexpr short SECONDS = 60;

Clock::Clock()
{
	SYSTEMTIME now;
	GetLocalTime(&now);
	this->hour = now.wHour;
	this->minutes = now.wMinute;
	this->seconds = now.wSecond;
}

void Clock::show()const
{
	cout << this->hour << ":" << this->minutes << ":" << this->seconds;
}

short Clock::getHour()const
{
	return this->hour;
}

short Clock::getMinutes()const
{
	return this->minutes;
}

short Clock::getSeconds()const
{
	return this->seconds;
}

bool Clock:: operator >(const Clock& other)const
{
	// return true if this Clock more than the other Clock
	int total_this = 0, total_other = 0;
	total_this += this->hour * SECONDS * SECONDS + this->minutes * SECONDS + 
		this->seconds;
	total_other += other.hour * SECONDS * SECONDS + other.minutes * SECONDS + other.seconds;
	return(total_this > total_other);
}