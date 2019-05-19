#ifndef __Video_H
#define __Video_H

class Video :virtual public Status
{
public:
	Video(string auther_name, Color status_color) :
		Status(auther_name, status_color)
	{}

	virtual void show(bool with_auther, bool with_date) const override
	{
		Status::show(with_auther,with_date);
		setPrintingColor(status_color);
		cout << "\t\t\t**************" << endl;
		cout << "\t\t\t*            *" << endl;
		cout << "\t\t\t* Show Video *" << endl;
		cout << "\t\t\t*            *" << endl;
		cout << "\t\t\t**************" << endl;
	}
};
#endif __Video_H


