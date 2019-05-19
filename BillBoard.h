#ifndef __BILLBOARD_H
#define __BILLBOARD_H

#include<vector>
#include"Status.h"
#include"Text.h"
#include"Image.h"
#include"Video.h"
#include"TextImage.h"
#include"TextVideo.h"

class BillBoard // this class is to save and show the posts(status) of users
{
public:
	BillBoard();
	BillBoard(const BillBoard&) = delete;
	const BillBoard& operator=(const BillBoard&) = delete;
	~BillBoard();
	void show()const;
	void addStatus(Status* status);
	int getNumberOfPosts()const;
	vector<Status*> getStatus()const;
private:
	vector<Status*>posts;
};
#endif  __BILLBOARD_H

