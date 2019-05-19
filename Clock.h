#ifndef __CLOCK_H
#define __CLOCK_H
#include<Windows.h>
#include<iostream>
using namespace std;
class Clock  // this class is just to save a time of status publishing time
{
private:
	short hour, minutes, seconds;
public:
	Clock();
	short getHour()const;
	short getMinutes()const;
	short getSeconds()const;
	void show()const;
	bool operator >(const Clock&)const;
};
#endif __CLOCK_H

