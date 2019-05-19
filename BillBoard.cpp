#include"BillBoard.h"

BillBoard::BillBoard()
{}

BillBoard::~BillBoard()
{
	for (int i = 0; i < (int)this->posts.size(); i++)
		delete this->posts[i];
}

vector<Status*>BillBoard::getStatus()const
{
	return this->posts;
}

int BillBoard::getNumberOfPosts()const
{
	return (int)this->posts.size();
}

void BillBoard::show()const
{
	if (this->posts.size())
	{
		for (auto itr = this->posts.begin();
		itr != this->posts.end(); ++itr)
			(*itr)->show(false);
	}
	else
		cout << "\t\t No Posts" << endl;
}

void BillBoard::addStatus(Status* status)
{
	this->posts.push_back(status);
}
