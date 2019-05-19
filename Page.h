#ifndef __PAGE_H
#define __PAGE_H

#include"User.h"
class Member;

class Page : public User
{
public:
	Page(string name);
	Page(const Page&) = delete;
	const Page& operator=(const Page&) = delete;
	~Page();
	int getFollowersNumber()const;
	void showFollowers()const;
	void operator += (Member* follower); // add follower
	short operator >(Page* other); // compare Pages according to number of followers
private:
	vector<Member*> followers;
};
#endif __PAGE_H

