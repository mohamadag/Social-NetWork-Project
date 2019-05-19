#include"Managment.h"
constexpr short int MAX_LEN = 256;
bool isLegalUserName(FaceBook& faceBook, string name,string className);
User* searchForUser(FaceBook& faceBook, string name, string className);
void run();
void setScreen();
void say(const char* text);
void showUserInterFace();
int getComand();
void executeCommand(int command, FaceBook& faceBook);
void addFriendToFaceBook(FaceBook& faceBook);
void addPageToFaceBook(FaceBook& faceBook);
void addStatusToFriend(FaceBook& faceBook);
void addStatusToPage(FaceBook& faceBook);
Date getFriendDate();
Status* getStatus(string name);
void showPagePosts(FaceBook& faceBook);
void showFriendPosts(FaceBook& faceBook);
void shoAllFriendsOfFriend(FaceBook& faceBook);
void showFollowersOfPage(FaceBook& faceBook);
void makeFriendship(FaceBook& faceBook);
void addFriendToPage(FaceBook& faceBook);
void showRecentTenPosts(FaceBook& faceBook);
void showLikedPageOfFriend(FaceBook& faceBook);
bool friendsBefor(vector<Member*> friends, string name);
bool addedToPageBefor(vector<Page*>liked_pages, string page_name);
void compareFriends(FaceBook& faceBook);
void comparePages(FaceBook& faceBook);
void compareFriendWithPage(FaceBook&faceBook);
void showCompareFriendsRes(Member* m1, Member*m2, short res);
void showComparePagesRes(Page* p1, Page*p2, short res);
void showCompareFriendWithPage(Member* m1, Page*p1, short res);
void sayGoodBye();

enum CommandType {
	EROR, ADD_FRIEND, ADD_PAGE, ADD_STATUS_FRIEND, ADD_STATUS_PAGE, SHOW_STATUS_PAGE
	, SHOW_STATUS_FRIEND, MAKE_FRIENDSHIP, ADD_FRIEND_TO_PAGE, SHOW_FACEBOOK, SHOW_FRIENDS_OF_FRIEND
	, SHOW_FOLLOWER_PAGE, SHOW_LIKEDPAGE_FRIEND, SHOW_RECENTTEN_FRIEND,COMPARE_FIRNDS,COMPARE_PAGES, COMPARE_FRIEND_PAGE,EXIT,START};
enum StatusType{ TEXT=1,IMAGE,VIDEO,TEXTIMAGE,TEXTVIDEO};
void run()
{
	say("welcome.wav");
	setScreen();
	FaceBook faceBook;
	int command = START;
	while (command != EXIT)
	{
		showUserInterFace();
		command = getComand();
		executeCommand(command, faceBook);
	}
}

void setScreen()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 750, 550, TRUE);
}

void say(const char* text)
{
	PlaySound(TEXT(text), NULL, SND_ASYNC);
	Sleep(800);
}

void showUserInterFace()
{
	setPrintingColor(BLUE);
	cout<<"_______________________________________________________________________________" << endl <<
	"_______________________________________________________________________________" << endl << endl;
	setPrintingColor(BLACK);
	cout << "\t\t***********************************************" << endl;
	cout << "\t\t*  (1)  Add Friend To FaceBook                *" << endl;
	cout << "\t\t*  (2)  Add Page To FaceBook                  *" << endl;
	cout << "\t\t*  (3)  Add Status To Friend                  *" << endl;
	cout << "\t\t*  (4)  Add Status To Page                    *" << endl;
	cout << "\t\t*  (5)  Show All The Staus Of Page            *" << endl;
	cout << "\t\t*  (6)  Show All The Status Of Friend         *" << endl;
	cout << "\t\t*  (7)  Make Friendship                       *" << endl;
	cout << "\t\t*  (8)  Add Friend To Page                    *" << endl;
	cout << "\t\t*  (9)  Show All Friends & Pages In FaceBook  *" << endl;
	cout << "\t\t*  (10) Show All Friends Of Member            *" << endl;
	cout << "\t\t*  (11) Show All The Followers Of Page        *" << endl;
	cout << "\t\t*  (12) Show LikedPage Of Friend              *" << endl;
	cout << "\t\t*  (13) Show Recent 10 Posts Of Friends       *" << endl;
	cout << "\t\t*  (14) Compare Between Two Friends           *" << endl;
	cout << "\t\t*  (15) Compare Between Two Pages             *" << endl;
	cout << "\t\t*  (16) Compare Between Friend And Page       *" << endl;
	cout << "\t\t*  (17) Exit                                  *" << endl;
	cout << "\t\t***********************************************" << endl;
	setPrintingColor(BLUE);
	cout << "_______________________________________________________________________________" << endl <<
	"_______________________________________________________________________________" << endl << endl;
	setPrintingColor();
}

int getComand()
{
	int command;
	setPrintingColor();
	cout << "Select Command->";
	setPrintingColor(GREEN);
	cin >> command;
	if (cin.fail() || command > EXIT || command < ADD_FRIEND)
	{
		cin.clear();
		cin.ignore(256, '\n');
		setPrintingColor(RED);
		cout << "Bad Input!! Insert a number from the Menu\n";
		return 0;
	}
	return command;
}

void executeCommand(int command, FaceBook& faceBook)
{
	switch (command)
	{
	case EROR:
		showUserInterFace();
		executeCommand(getComand(), faceBook);
		break;
	case ADD_FRIEND:
		addFriendToFaceBook(faceBook);
		break;
	case ADD_PAGE:
		addPageToFaceBook(faceBook);
		break;
	case ADD_STATUS_FRIEND:
		addStatusToFriend(faceBook);
		break;
	case ADD_STATUS_PAGE:
		addStatusToPage(faceBook);
		break;
	case SHOW_STATUS_PAGE:
		showPagePosts(faceBook);
		break;
	case SHOW_STATUS_FRIEND:
		showFriendPosts(faceBook);
		break;
	case MAKE_FRIENDSHIP:
		makeFriendship(faceBook);
		break;
	case ADD_FRIEND_TO_PAGE:
		addFriendToPage(faceBook);
		break;
	case SHOW_FACEBOOK:
		setPrintingColor();
		faceBook.show();
		break;
	case SHOW_FRIENDS_OF_FRIEND:
		shoAllFriendsOfFriend(faceBook);
		break;
	case SHOW_FOLLOWER_PAGE:
		showFollowersOfPage(faceBook);
		break;
	case SHOW_LIKEDPAGE_FRIEND:
		showLikedPageOfFriend(faceBook);
		break;
	case SHOW_RECENTTEN_FRIEND:
		showRecentTenPosts(faceBook);
		break;
	case COMPARE_FIRNDS:
		compareFriends(faceBook);
		break;
	case COMPARE_PAGES:
		comparePages(faceBook);
		break;
	case COMPARE_FRIEND_PAGE:
		compareFriendWithPage(faceBook);
		break;
	case EXIT:
		sayGoodBye();
		break;
	}
}
bool isLegalUserName(FaceBook& faceBook, string name,string className)
{
	int num_of_users = faceBook.getNumberOfUsers();
	vector<User*> users = faceBook.getAllUsers();
	for (int i = 0; i < num_of_users; i++)
	{
		if ((typeid(*users[i]).name()==className))
		{
			if (users[i]->getName()==name)
				return false;
		}
	}
	return true;
}

void addFriendToFaceBook(FaceBook& faceBook)
{
	char friend_name[MAX_LEN];
	setPrintingColor();
	say("enterfriendname.wav");
	cout << "\t\tFriend Name:";
	setPrintingColor(GREEN);
	cin.ignore();
	cin.getline(friend_name, MAX_LEN);
	setPrintingColor();
	if (isLegalUserName(faceBook, friend_name, typeid(Member).name()))
	{
		Date date = getFriendDate();
		User* member = new Member(friend_name, date);
		faceBook.addUser(member);
	}
	else
	{
		say("thatnameistaken.wav");
		setPrintingColor(RED);
		cout << "That Name Is Taken!!" << endl;
	}
}

Date getFriendDate()
{
	setPrintingColor();
	say("enterbirhdate.wav");
	short day, month, year;
	cout << "\t\tDay:";
	setPrintingColor(GREEN);
	cin >> day;
	setPrintingColor();
	cout << "\t\tMonth:";
	setPrintingColor(GREEN);
	cin >> month;
	setPrintingColor();
	cout << "\t\tYear:";
	setPrintingColor(GREEN);
	cin >> year;
	setPrintingColor();
	return Date(day, month, year);
}

void addPageToFaceBook(FaceBook& faceBook)
{
	char page_name[MAX_LEN];
	setPrintingColor();
	say("enterpagename.wav");
	cout << "\t\tPage Name:";
	setPrintingColor(GREEN);
	cin.ignore();
	cin.getline(page_name, MAX_LEN);
	setPrintingColor();
	if (isLegalUserName(faceBook, page_name,typeid(Page).name()))
	{
		User* page = new Page(page_name);
		faceBook.addUser(page);
	}
	else
	{
		say("thatnameistaken.wav");
		setPrintingColor(RED);
		cout << "That Name Is Taken!!" << endl;
	}
}
User* searchForUser(FaceBook& faceBook, string name, string className)
{
	int num_of_users = faceBook.getNumberOfUsers();
	vector<User*> users = faceBook.getAllUsers();
	for (int i = 0; i < num_of_users; i++)
	{
		if ((typeid(*users[i]).name()==className))
		{
			if (users[i]->getName()==name)
				return users[i];
		}
	}
	return NULL;
}

void addStatusToFriend(FaceBook& faceBook)
{
	char friend_name[MAX_LEN];
	setPrintingColor();
	say("enterfriendname.wav");
	cout << "\t\tFriend Name:";
	cin.ignore();
	setPrintingColor(GREEN);
	cin.getline(friend_name, MAX_LEN);
	User* user = searchForUser(faceBook, friend_name,typeid(Member).name());
	if (user)
	{
		Status* status = getStatus(friend_name);
		user->addStatus(status);
	}
	else
	{
		say("friendnamenotex.wav");
		setPrintingColor(RED);
		cout << "This Friend Not Found!!" << endl;
	}
}

Status* getStatus(string name)
{
	short type;
	short status_color;
	Status *status = nullptr;
	Color color = BLACK;
	setPrintingColor();
	cout << "\t(1)Text   (2)Image   (3)Video   (4)TextImage   (5)TextVideo" << endl;
	say("enterstatustype.wav");
	cout << "\t\tType:";
	setPrintingColor(GREEN);
	cin >> type;
	if (type!=TEXT)
	{
		setPrintingColor();
		cout << "\t(1)RED" << "    (2)GREEN" << "    (3)BLUE" << endl;
		say("enterstatuscolor.wav");
		cout << "\t\tColor:";
		setPrintingColor(GREEN);
		cin >> status_color;
		color = (Color)(status_color);
	}
	switch (type)
	{
	case TEXT:
		status = new Text(name, color);
		break;
	case IMAGE:
		status = new Image(name, color);
		break;
	case VIDEO:
		status = new Video(name, color);
		break;
	case TEXTIMAGE:
		status = new TextImage(name, color);
		break;
	case TEXTVIDEO:
		status = new TextVideo(name, color);
		break;
	default:
		break;
	}
	return status;
}

void addStatusToPage(FaceBook& faceBook)
{
	char page_name[MAX_LEN];
	setPrintingColor();
	say("enterpagename.wav");
	cout << "\t\tPage Name:";
	cin.ignore();
	setPrintingColor(GREEN);
	cin.getline(page_name, MAX_LEN);
	User* user = searchForUser(faceBook, page_name,typeid(Page).name());
	if (user)
	{
		Status* status = getStatus(page_name);
		user->addStatus(status);
	}
	else
	{
		say("pagenamenotex.wav");
		setPrintingColor(RED);
		cout << "This Page Not Found!!" << endl;
	}
}

void showPagePosts(FaceBook& faceBook)
{
	char page_name[MAX_LEN];
	setPrintingColor();
	say("enterpagename.wav");
	cout << "\t\tPage Name:";
	cin.ignore();
	setPrintingColor(GREEN);
	cin.getline(page_name, MAX_LEN);
	setPrintingColor();
	User* user = searchForUser(faceBook, page_name,typeid(Page).name());
	if (user)
		user->showPosts();
	else
	{
		say("pagenamenotex.wav");
		setPrintingColor(RED);
		cout << "This Page Not Found!!" << endl;
	}
}

void showFriendPosts(FaceBook& faceBook)
{
	char friend_name[MAX_LEN];
	setPrintingColor();
	say("enterfriendname.wav");
	cout << "\t\tFriend Name:";
	cin.ignore();
	setPrintingColor(GREEN);
	cin.getline(friend_name, MAX_LEN);
	setPrintingColor();

	User* user = searchForUser(faceBook, friend_name,typeid(Member).name());
	if (user)
		user->showPosts();
	else
	{
		say("friendnamenotex.wav");
		setPrintingColor(RED);
		cout << "This Friend Not Found!!" << endl;
	}
}

void shoAllFriendsOfFriend(FaceBook& faceBook)
{
	char friend_name[MAX_LEN];
	setPrintingColor();
	say("enterfriendname.wav");
	cout << "\t\tFriend Name:";
	cin.ignore();
	setPrintingColor(GREEN);
	cin.getline(friend_name, MAX_LEN);
	setPrintingColor();
	Member* member = (Member*)searchForUser(faceBook, friend_name,
		typeid(Member).name());
	if (member)
		member->showFriends();
	else
	{
		say("friendnamenotex.wav");
		setPrintingColor(RED);
		cout << "This Friend Not Found!!" << endl;
	}
}

void showFollowersOfPage(FaceBook& faceBook)
{
	char page_name[MAX_LEN];
	setPrintingColor();
	say("enterpagename.wav");
	cout << "\t\tPage Name:";
	cin.ignore();
	setPrintingColor(GREEN);
	cin.getline(page_name, MAX_LEN);
	setPrintingColor();
	User* page =searchForUser(faceBook, page_name,typeid(Page).name());
	if (page)
		((Page*)page)->showFollowers();
	else
	{
		say("pagenamenotex.wav");
		setPrintingColor(RED);
		cout << "This Page Not Found!!" << endl;
	}
}

void makeFriendship(FaceBook& faceBook)
{
	char friend_name1[MAX_LEN];
	char friend_name2[MAX_LEN];
	setPrintingColor();
	say("enterfriendname.wav");
	cout << "\t\tFriend1 Name:";
	cin.ignore();
	setPrintingColor(GREEN);
	cin.getline(friend_name1, MAX_LEN);
	setPrintingColor();
	say("enterfriendname.wav");
	cout << "\t\tFriend2 Name:";
	setPrintingColor(GREEN);
	cin.getline(friend_name2, MAX_LEN);
	Member* member1 = (Member*)searchForUser(faceBook, friend_name1,typeid(Member).name());
	Member* member2 = (Member*)searchForUser(faceBook, friend_name2, typeid(Member).name());
	if (member1)
	{
		if (member2)
		{
			if (!friendsBefor(member1->getFriends(), friend_name2))
			{
				if (!strcmp(friend_name1, friend_name2))
				{
					setPrintingColor(RED);
					cout << "A member canot add him self!!" << endl;
				}
				else
					*member2 += member1;
			}
			else
			{
				setPrintingColor(RED);
				cout  <<friend_name1 << " and " << friend_name2 << " Friends Befor" << endl;
			}
		}
		else
		{
			say("friendnamenotex.wav");
			setPrintingColor(RED);
			cout << "Friend2 Not Found!!" << endl;
		}
	}
	else
	{
		say("friendnamenotex.wav");
		setPrintingColor(RED);
		cout << "Friend1 Not Found!!" << endl;
	}
}

void addFriendToPage(FaceBook& faceBook)
{
	char friend_name[MAX_LEN];
	char page_name[MAX_LEN];
	setPrintingColor();
	say("enterfriendname.wav");
	cout << "\t\tFriend Name:";
	cin.ignore();
	setPrintingColor(GREEN);
	cin.getline(friend_name, MAX_LEN);
	setPrintingColor();
	say("enterpagename.wav");
	cout << "\t\tPage Name:";
	setPrintingColor(GREEN);
	cin.getline(page_name, MAX_LEN);
	Page* page = (Page*)searchForUser(faceBook, page_name,typeid(Page).name());
	Member* member = (Member*)searchForUser(faceBook, friend_name, 
		typeid(Member).name());
	if (member)
	{
		if (page)
		{
			if (!addedToPageBefor(member->getLikedPages(), page_name))
			{

				*page += member;
				*member += page;
			}
			else
			{
				setPrintingColor(RED);
				cout <<member->getName() << " Liked " << page->getName() << " page Befor!!" << endl;
			}
		}
		else
		{
			say("pagenamenotex.wav");
			setPrintingColor(RED);
			cout << "This Page Not Found!!" << endl;
		}
	}
	else
	{
		say("friendnamenotex.wav");
		setPrintingColor(RED);
		cout << "This Friend Not Found!!" << endl;
	}
}
void showLikedPageOfFriend(FaceBook& faceBook)
{
	char friend_name[MAX_LEN];
	setPrintingColor();
	say("enterfriendname.wav");
	cout << "\t\tFriend Name:";
	cin.ignore();
	setPrintingColor(GREEN);
	cin.getline(friend_name, MAX_LEN);
	setPrintingColor();
	Member* member = (Member*)searchForUser(faceBook, friend_name,
		typeid(Member).name());
	if (member)
		member->showLikedPages();
	else
	{
		say("friendnamenotex.wav");
		setPrintingColor(RED);
		cout << "This Friend Not Found!!" << endl;
	}
}

void showRecentTenPosts(FaceBook& faceBook)
{
	char friend_name[MAX_LEN];
	setPrintingColor();
	say("enterfriendname.wav");
	cout << "\t\tFriend Name:";
	cin.ignore();
	setPrintingColor(GREEN);
	cin.getline(friend_name, MAX_LEN);
	Member* member = (Member*)searchForUser(faceBook, friend_name,
		typeid(Member).name());
	if (member)
	{
		setPrintingColor();
		member->showRecentTenPostsOfFriends();
	}
	else
	{
		say("friendnamenotex.wav");
		setPrintingColor(RED);
		cout << "This Friend Not Found!!" << endl;
	}
}

bool friendsBefor(vector<Member*> friends, string name)
{
	for (int i = 0; i <(int) friends.size(); i++)
	{
		if (friends[i]->getName()==name)
			return true;
	}
	return false;
}

bool addedToPageBefor(vector<Page*>liked_pages, string page_name)
{
	for (int i = 0; i < (int)liked_pages.size(); i++)
	{
		if (liked_pages[i]->getName()==page_name)
			return true;
	}
	return false;
}

void compareFriends(FaceBook& faceBook)
{
	char friend_name1[MAX_LEN];
	char friend_name2[MAX_LEN];
	setPrintingColor();
	say("enterfriendname.wav");
	cout << "\t\t\tFriend1 Name:";
	cin.ignore();
	setPrintingColor(GREEN);
	cin.getline(friend_name1, MAX_LEN);
	setPrintingColor();
	say("enterfriendname.wav");
	cout << "\t\t\tFriend2 Name:";
	setPrintingColor(GREEN);
	cin.getline(friend_name2, MAX_LEN);
	Member* member1 = (Member*)searchForUser(faceBook, friend_name1,
		typeid(Member).name());
	Member* member2 = (Member*)searchForUser(faceBook, friend_name2,
		typeid(Member).name());
	if (member1)
	{
		if (member2)
		{
				if (!strcmp(friend_name1, friend_name2))
				{
					setPrintingColor(RED);
					cout << "A member canot make compare with him self!!" << endl;
				}
				else
				{
					short res = *member1 > member2;
					showCompareFriendsRes(member1, member2, res);
				}
		}
		else
		{
			say("friendnamenotex.wav");
			setPrintingColor(RED);
			cout << "Friend2 Not Found!!" << endl;
		}
	}
	else
	{
		say("friendnamenotex.wav");
		setPrintingColor(RED);
		cout << "Friend1 Not Found!!" << endl;
	}
}

void showCompareFriendsRes(Member* m1, Member*m2, short res)
{
	int this_num_friends = m1->getNumberOfFriends();
	int other_num_friends = m2->getNumberOfFriends();
	setPrintingColor();

	if (res>0)
	{
	cout << m1->getName() << " Has More Friends Than " << m2->getName() << endl;
	cout << m1->getName() << " Has:" << "(" << this_num_friends << ") Friends " << m2->getName() << " Has:" << "(" << other_num_friends << ") Friends" << endl;
	}
	else if (res<0)
	{
	cout << m2->getName() << " Has More Friends Than " << m1->getName() << endl;
	cout << m2->getName() << " Has:" << "(" << other_num_friends << ") Friends " << m1->getName() << " Has:" << "(" << this_num_friends << ") Friends" << endl;
	}
	else
	{
	cout << "Both Of " << m1->getName() << " And " << m2->getName() << " Have:" <<
		"(" << this_num_friends << ")" << " Friends" << endl;
	}
}

void comparePages(FaceBook& faceBook)
{
	char page1_name[MAX_LEN];
	char page2_name[MAX_LEN];
	setPrintingColor();
	say("enterpagename.wav");
	cout << "\t\tPage1 Name:";
	cin.ignore();
	setPrintingColor(GREEN);
	cin.getline(page1_name, MAX_LEN);
	setPrintingColor();
	say("enterpagename.wav");
	cout << "\t\tPage2 Name:";
	setPrintingColor(GREEN);
	cin.getline(page2_name, MAX_LEN);
	Page* page1 = (Page*)searchForUser(faceBook, page1_name,typeid(Page).name());
	Page* page2 = (Page*)searchForUser(faceBook, page2_name, typeid(Page).name());
	if (page1)
	{
		if (page2)
		{
			if (!strcmp(page1_name, page2_name))
			{
				setPrintingColor(RED);
				cout << "A Page canot make compare with him self!!" << endl;
			}
			else
			{
				short res = *page1 > page2;
				showComparePagesRes(page1, page2, res);
			}
		}
		else
		{
			say("pagenamenotex.wav");
			setPrintingColor(RED);
			cout << "Page2 Not Found!!" << endl;
		}
	}
	else
	{
		say("pagenamenotex.wav");
		setPrintingColor(RED);
		cout << "Page1 Not Found!!" << endl;
	}
}

void showComparePagesRes(Page* p1, Page*p2, short res)
{
	setPrintingColor();
	if (res > 0)
	{
		cout << p1->getName() << " Has More Followers Than " << p2->getName() << endl;
		cout << p1->getName() << " Has (" << p1->getFollowersNumber() << ") Followers "
			<< p2->getName() << " Has (" << p2->getFollowersNumber() << ") Followers" << endl;

	}
	else if (res < 0)
	{
		cout << p2->getName() << " Has More Followers Than " << p1->getName() << endl;
		cout << p2->getName() << " Has (" << p2->getFollowersNumber() << ") Followers "
			<< p1->getName() << " Has (" << p1->getFollowersNumber() << ") Followers" << endl;
	}
	else
	{
		cout << "Both " << p1->getName() << " And " << p2->getName() << " Has (" << p1->getFollowersNumber() << ") Followers" << endl;
	}
}
void compareFriendWithPage(FaceBook&faceBook)
{
	char friend_name[MAX_LEN];
	char page_name[MAX_LEN];
	setPrintingColor();
	say("enterfriendname.wav");
	cout << "\t\tFriend Name:";
	cin.ignore();
	setPrintingColor(GREEN);
	cin.getline(friend_name, MAX_LEN);
	setPrintingColor();
	say("enterpagename.wav");
	cout << "\t\tPage Name:";
	setPrintingColor(GREEN);
	cin.getline(page_name, MAX_LEN);
	Member* member = (Member*)searchForUser(faceBook, friend_name, 
		typeid(Member).name());
	Page* page = (Page*)searchForUser(faceBook, page_name, typeid(Page).name());
	if (member)
	{
		if (page)
		{
			short res = *member > page;
			showCompareFriendWithPage(member, page, res);
		}
		else
		{
			say("pagenamenotex.wav");
			setPrintingColor(RED);
			cout << "Page Not Found!!" << endl;
		}
	}
	else
	{
		say("friendnamenotex.wav");
		setPrintingColor(RED);
		cout << "Friend Not Found!!" << endl;
	}
}
void showCompareFriendWithPage(Member* m, Page*p, short res)
{
	setPrintingColor();
	if (res > 0)
	{
		cout << m->getName() << " Has More Friends Than " << p->getName()<<" Followers" << endl;
		cout << m->getName() << " Has (" << m->getNumberOfFriends() << ") Friends "
			<< p->getName() << " Has (" << p->getFollowersNumber() << ") Followers" << endl;
	}
	else if (res < 0)
	{
		cout << p->getName() << " Has More Followers Than " << m->getName()<<" Friends" << endl;
		cout << p->getName() << " Has (" << p->getFollowersNumber() << ") Followers "
			<< m->getName() << " Has (" << m->getNumberOfFriends() << ") friends" << endl;
	}
	else
	{
		cout << "Both " << m->getName() << " And " << p->getName() << " Has (" 
			<< p->getFollowersNumber() << ") Friends/Followers" << endl;
	}
}

void sayGoodBye()
{
	say("goodBye.wav");
	cout << "\t\t\t";
	setPrintingColor(RED);
	cout << "G";
	setPrintingColor(GREEN);
	cout << "O";
	setPrintingColor(BLUE);
	cout << "O";
	setPrintingColor(RED);
	cout << "D";
	setPrintingColor(GREEN);
	cout << "B";
	setPrintingColor(RED);
	cout << "Y";
	setPrintingColor(BLUE);
	cout << "E" << endl;
	setPrintingColor();
	Sleep(1000);
}
