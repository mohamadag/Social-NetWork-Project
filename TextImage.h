#ifndef __TEXTIMAGE_H
#define __TEXTIMAGE_H

class TextImage :public Text,public Image
{
public:
	TextImage(string auther_name, Color status_color) :
		Status(auther_name, status_color), Text(auther_name, status_color),
		Image(auther_name, status_color)
	{}

	 virtual void show(bool with_auther, bool with_date)const override
	{
		Status::show(with_auther,with_date);
		setPrintingColor();
		Text::show(with_auther, false);
		setPrintingColor(status_color);
		Image::show(with_auther, false);
	}
};
#endif __TEXTIMAGE_H
