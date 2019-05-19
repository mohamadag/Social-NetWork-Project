#ifndef __USER_H
#define __USER_H

#include"BillBoard.h"
class User
{
public:
	 User(string name);
	 void showPosts()const ;
	 string getName()const ;
	 void addStatus(Status* status) ;
	 virtual ~User() {}; // so the class is abstarct 
protected:
	string name;
	BillBoard billBoard;
};
#endif __USER_H

