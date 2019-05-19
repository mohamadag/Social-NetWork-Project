#include"Member.h"
#include"Page.h"

constexpr short RECENT_POSTS = 10;
int getNumOfAllFriendsPosts(vector<Member*> friends, int num_of_friends);
void fillPosts(vector<Member*> friends, vector<Status*>* posts, int num_of_friends);
void sortPostsByTime(vector<Status*>* posts);
void swap(Status** s1, Status** s2);

Member::Member(string name, Date& birth_day) :User(name), birth_date(birth_day)
{}

Member::~Member()
{}

void Member:: operator +=(Page* page)
{
	this->favorites += page;
}

int Member::getNumberOfFriends()const
{
	return this->favorites.getNumOfFriends();
}

vector<Member*> Member::getFriends()const
{
	return this->favorites.getAllFriend();
}

vector<Page*> Member::getLikedPages()const
{
	return this->favorites.getFavoritesPages();
}

vector<Status*> Member::getPosts()const
{
	return this->billBoard.getStatus();
}

int Member::getNumOfLikedPages()const
{
	return this->favorites.getNumOfFavoritesPages();
}

int Member::getNumOfPosts()const
{
	return this->billBoard.getNumberOfPosts();
}

void Member::showLikedPages()const {

	cout << this->name << " Liked The Pages:" << endl;
	this->favorites.showLikedPages();
}

void Member:: operator +=(Member* member)
{
	this->favorites += member;
	member->favorites += this;
}

void Member::showFriends()const
{
	cout << this->name << "'s" " friends:" << endl;
	this->favorites.showFriends();
}

void Member::showRecentTenPostsOfFriends()const
{
	int num_of_all_posts = getNumOfAllFriendsPosts(this->getFriends(),
		this->getNumberOfFriends());
	vector<Status*> all_friends_status;
	fillPosts(this->getFriends(), &all_friends_status, this->getNumberOfFriends());
	sortPostsByTime(&all_friends_status);
	int how_posts_found = min(num_of_all_posts, RECENT_POSTS);
	if (how_posts_found < RECENT_POSTS)
	{
		cout <<endl<< "\t number of status that friends posted less than 10 there are:"
			<< how_posts_found << " Posts" << endl;
	}
	for (auto itr = all_friends_status.begin();itr!= all_friends_status.end(); ++itr)
		(*itr)->show(true);
	// שחרור זיכרון של הויקטור ?
}

int getNumOfAllFriendsPosts(vector<Member*> friends, int num_of_friends)
{
	int num_of_all_posts = 0;
	for (int i = 0; i < num_of_friends; i++)
		num_of_all_posts += friends[i]->getNumOfPosts();
	return num_of_all_posts;
}

void fillPosts(vector<Member*> friends, vector<Status*>* posts, int num_of_friends)
{
	vector<Status*> current_friend_status;
	for (int i = 0; i < num_of_friends; i++)
	{
		current_friend_status = friends[i]->getPosts();
		for (auto itr = current_friend_status.begin();
			itr!= current_friend_status.end();++itr)
			(*posts).push_back(*itr);
	}
}

void sortPostsByTime(vector<Status*>* posts)
{
	for (int i = 0; i < (int)(*posts).size()-1; i++)
	{
		for (int j = 0; j < (int)(*posts).size() - i-1; j++)
		{
			if ((*posts)[j+1]->getPublishingTime()>(*posts)[j]->getPublishingTime())
				swap(&(*posts)[j], &(*posts)[j+1]);
		}
	}
}

void swap(Status** s1, Status** s2)
{
	Status* tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

short Member:: operator>(Member* other)
{
	return (this->getNumberOfFriends() - other->getNumberOfFriends());
}

short Member::operator >(Page* page)
{
	return  (this->getNumberOfFriends() - page->getFollowersNumber());
}
