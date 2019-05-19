#ifndef __STATUS_H
#define __STATUS_H
#define _CRT_SECURE_NO_WARNINGS
#include"Date.h"
#include "Clock.h"
#include"PrintingColors.h"
#include<string>

class Status // there are 5 Kinds of Status
{
public:
	Status(string auther_name, Color status_color = BLACK);
	virtual ~Status();
	Date getPublishingDate()const;
	Clock getPublishingTime()const;
	virtual void show(bool with_auther = false,bool with_date = true)const = 0;
	// there are to shapes of showing the posts(status)
	// shape 1 : when the user want to see all the posts of certain member(friend)
	// there is no need to show the publisher name 
	// shape 2 : when the user want to see the recent 10 posts fo his friends
	// in these case the user want to know who published the post(status)
	bool operator==(const Status& other)const; // compare two status content
	bool operator!=(const Status& other)const; // check if two status are different
protected:
	const Date published_date;
	const Clock published_time;
	const Color status_color;
	string auther_name;
};
#endif __STATUS_H
