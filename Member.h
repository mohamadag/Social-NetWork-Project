#ifndef __MEMBER_H
#define __MEMBER_H

#include"Favorites.h"
#include"User.h"
class Page;

class Member : public User
{
private:
	Date birth_date;
	Favorites favorites;
public:
	Member(string name, Date& birth_day);
	Member(const Member&) = delete;
	const Member& operator=(const Member&) = delete;
	~Member();
	void showLikedPages()const;
	void showFriends()const;
	void showRecentTenPostsOfFriends()const;
	vector<Member*> getFriends()const;
	int getNumberOfFriends()const;
	vector<Page*> getLikedPages()const;
	int getNumOfLikedPages()const;
	int getNumOfPosts()const;
	vector<Status*> getPosts()const;
	void operator +=(Member* other); // add friend
	void operator +=(Page* page); // folow page
	short operator>(Member* other); // compare two friends
	short operator >(Page* page); // compare with page
};
#endif __MEMBER_H