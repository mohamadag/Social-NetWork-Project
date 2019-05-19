#include"PrintingColors.h"

void changeColorToGreen()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
}

void changeColorToBlack()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void changeColorToRed()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
}

void changeColorToBlue()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
}

void setPrintingColor(Color status_color)
{
	if (status_color == RED)
		changeColorToRed();
	else if (status_color == GREEN)
		changeColorToGreen();
	else if (status_color == BLUE)
		changeColorToBlue();
	else
		changeColorToBlack();
}
