/* 
* RGBColor.h
*
* Created: 5/31/2019 10:59:12 PM
* Author: civel
*/


#ifndef __RGBCOLOR_H__
#define __RGBCOLOR_H__

#include "Arduino.h"

class RGBColor
{
//variables
public:
	uint8_t R, G, B;
protected:
private:

//functions
public:
	RGBColor(uint8_t t_red, uint8_t t_green, uint8_t t_blue);
	~RGBColor();
protected:
private:

}; //RGBColor

#endif //__RGBCOLOR_H__
