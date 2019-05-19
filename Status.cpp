#include"Status.h"

Status::Status(string auther_name, Color status_color) :
	auther_name(auther_name),published_date(Date()), published_time(Clock())
	,status_color(status_color)
{}

Status::~Status()
{}

 void Status:: show(bool with_auther, bool with_date )const
{
	 if (with_date == false)
		 return;
	 else
	 {
		 setPrintingColor();
		 cout << "Publishing Date:";
		 this->getPublishingDate().show();
		 cout << "\tPublishing Time:";
		 this->getPublishingTime().show();
	 }
	if (with_auther)
		cout << "    Publisher:" << this->auther_name;	
	cout << endl;
}

Date Status::getPublishingDate()const
{
	return this->published_date;
}

Clock Status::getPublishingTime()const
{
	return this->published_time;
}

bool Status:: operator==(const Status& other)const
{
	//return true if this status kind same as the other status kind
	return (typeid(*this).name()==typeid(other).name());
}

bool Status:: operator!=(const Status& other)const
{
	return !(*this == other);
}
