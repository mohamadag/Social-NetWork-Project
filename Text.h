#ifndef __TEXT_H
#define __TEXT_H

class Text : virtual public Status
{
public:
	Text(string auther_name, Color status_color = BLACK):
		Status(auther_name, status_color)	
	{}

	virtual void show(bool with_auther, bool with_date)const override
	{
		Status::show(with_auther,with_date);
		cout << "\t\t\t**************" << endl;
		cout << "\t\t\t*            *" << endl;
		cout << "\t\t\t* Show  Text *" << endl;
		cout << "\t\t\t*            *" << endl;
		cout << "\t\t\t**************" << endl;
	}
};
#endif __TEXT_H

