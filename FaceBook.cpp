#include"FaceBook.h"

FaceBook::FaceBook()
{}

FaceBook::~FaceBook()
{
	for (int i = 0; i < (int)users.size(); i++)
		delete this->users[i];	
}

void FaceBook::addUser(User* new_user)
{
	this->users.push_back(new_user);

	if (typeid(*new_user) == typeid(Member))
		this->number_of_members += 1;
	else
		this->number_of_pages += 1;
}

int FaceBook:: getNumberOfUsers()const
{
	return (int)this->users.size();
}

vector<User*> FaceBook::getAllUsers() const
{
	return this->users;
}

void FaceBook::show() const
{
	cout << endl << "\t\t******PAGES******" << endl;
	if (this->number_of_pages)
	{
		int index = 1;
		for (int i = 0; i < (int)this->users.size(); i++)
		{
			if (typeid(*users[i]) == typeid(Page))
				cout << "\t\t(" << index++ << ")" << this->users[i]->getName() << endl;
		}
	}
	else
		cout << "\t\tNo Pages In FaceBook" << endl;
	cout << "\t\t*****MEMBERS*****" << endl;
	if (this->number_of_members)
	{
		int index = 1;
		for (int i = 0; i < (int)this->users.size(); i++)
		{
			if (typeid(*users[i]) == typeid(Member))
				cout << "\t\t(" << index++ << ")" << this->users[i]->getName() << endl;
		}
	}
	else
		cout << "\t\tNo Members In FaceBook" << endl;
}