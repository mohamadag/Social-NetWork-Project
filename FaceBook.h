#ifndef __FACEBOOK_H
#define __FACEBOOK_H

#include"Page.h"
#include"Member.h"
#include"User.h"

class FaceBook
{
public:
	FaceBook();
	FaceBook(const FaceBook&) = delete;
	const FaceBook& operator=(const FaceBook&) = delete;
	~FaceBook();
	int getNumberOfUsers()const;
	void addUser(User* new_user);
	void show()const;
	vector<User*> getAllUsers() const;

private:

	vector<User*>users;
	int number_of_pages = 0, number_of_members = 0; // just for inner uses for printing
};
#endif __FACEBOOK_H

