#ifndef __DATE_H
#define __DATE_H
#include<iostream>
#include<Windows.h>
using namespace std;
class Date /* this class is used in two cases:
		   (1) the date of status publishing, at these case the date is const
		   (2) the date of a member(friend) birthday
		   */
{
private:
	short day, month, year;
public:
	Date(short  day, short  month, short  year); // used at the case 2
	Date();// used at the case 1
	void show() const;
	short getDay() const;
	short getMonth() const;
	short getYear() const;
};
#endif __DATE_H

