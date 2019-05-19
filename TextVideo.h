#ifndef __TEXTVIDEO_H
#define __TEXTVIDEO_H

class TextVideo :public Text,public Video
{
public:
	TextVideo(string auther_name, Color status_color) :
		Status(auther_name, status_color), Text(auther_name, status_color),
		Video(auther_name, status_color)
	{}

	virtual void show(bool with_auther,bool with_date)const override
	{
		Status::show(with_auther);
		setPrintingColor();
		Text::show(with_auther, false);
		setPrintingColor(status_color);
		Video::show(with_auther, false);
	}
};
#endif __TEXTVIDEO_H

