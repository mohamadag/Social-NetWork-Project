#ifndef __PRINTINGCOLORS_H
#define __PRINTINGCOLORS_H
//this header is just for set the color printing and to define a color 
// that used in status 
#include<Windows.h>
enum Color { BLACK, RED, GREEN, BLUE };
void setPrintingColor(Color status_color =BLACK);

#endif  __PRINTINGCOLORS_H