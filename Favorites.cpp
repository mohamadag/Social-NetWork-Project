#include"Favorites.h"
#include"Member.h"

Favorites::Favorites()
{}

Favorites::~Favorites()
{}

int Favorites::getNumOfFriends()const
{
	return (int)this->friends.size();
}

vector<Member*> Favorites::getAllFriend()const
{
	return this->friends;
}

vector<Page*> Favorites::getFavoritesPages()const
{
	return this->liked_pages;
}

int Favorites::getNumOfFavoritesPages()const
{
	return (int)this->liked_pages.size();
}

void Favorites::operator +=(Page* new_page)
{
	this->liked_pages.push_back(new_page);
}

void Favorites::showLikedPages()const
{
	if ((int)liked_pages.size())
	{
		int i = 1;
		for (auto itr = liked_pages.begin(); itr != liked_pages.end(); ++itr)
			cout << "\t\t(" << i++ << ") " << (*itr)->getName() << endl;
	}
	else
		cout << "\t\t Doesn't Like Pages" << endl;
}

void Favorites ::operator +=(Member* member)
{
	this->friends.push_back(member);
}

void ::Favorites::showFriends()const
{
	if ((int)friends.size())
	{
		int i = 1;
		for (auto itr = friends.begin(); itr != friends.end(); ++itr)
			cout << "\t\t(" << i++ << ") " << (*itr)->getName() << endl;
	}
	else
		cout << "\t\t Doesn't Has Friends" << endl;
}