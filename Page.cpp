#include"Page.h"
#include"Member.h"

Page::Page(string name) :User(name)
{}

Page::~Page()
{}

int Page:: getFollowersNumber()const
{
	return (int)this->followers.size();
}

void Page:: operator += (Member* follower)
{
	this->followers.push_back(follower);
}

void Page::showFollowers()const
{
	cout << this->name << "'s" << " Followers:" << endl;
	if ((int)this->followers.size())
	{
		for (int i = 0; i < (int)this->followers.size(); i++)
			cout << "\t\t(" << i + 1 << ")" << followers[i]->getName() << endl;
	}
	else
		cout << "\t\t No Followers" << endl;
}

short Page:: operator >(Page* other)
{
	// return positive number if this Page has more followers than other Page
	// 0 if they have the same number of followers othwewise negative number
	return((int)this->followers.size() - (int)other->followers.size());
}