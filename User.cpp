#define _CRT_SECURE_NO_WARNINGS
#include"User.h"
#include<iostream>

User::User(string name) : name(name)
{}

string  User::getName()const
{
	return this->name;
}

void  User::showPosts()const
{
	this->billBoard.show();
}

void User::addStatus(Status* status)
{
	this->billBoard.addStatus(status);
}