#ifndef __IMAGE_H
#define __IMAGE_H

class Image : virtual public Status
{
public:
	Image(string auther_name, Color status_color) 
		:Status(auther_name, status_color)
	{}

	virtual void show(bool with_auther,bool with_date)const override
	{
		Status::show(with_auther,with_date);
		setPrintingColor(status_color);
		cout << "\t\t\t**************" << endl;
		cout << "\t\t\t*            *" << endl;
		cout << "\t\t\t* Show Image *" << endl;
		cout << "\t\t\t*            *" << endl;
		cout << "\t\t\t**************" << endl;
	}
};
#endif __IMAGE_H


