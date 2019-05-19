#ifndef __FAVORITES_H
#define __FAVORITES_H

#include"Page.h"
class Member;

class Favorites
{
public:
	Favorites();
	Favorites(const Favorites&) = delete;
	const Favorites& operator=(const Favorites&) = delete;
	~Favorites();
	void operator +=(Page* page); // follow page
	void operator +=(Member* member); // add friend to favorites
	void showLikedPages()const;
	void showFriends()const;
	vector<Member*> getAllFriend()const;
	vector<Page*> getFavoritesPages()const;
	int getNumOfFriends()const;
	int getNumOfFavoritesPages()const;
private:
	vector<Member*> friends;
	vector<Page*>liked_pages;
};
#endif __FAVORITES_H

