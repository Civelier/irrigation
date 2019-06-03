/* 
* HSVColor.h
*
* Created: 5/31/2019 10:59:31 PM
* Author: civel
*/


#ifndef __HSVCOLOR_H__
#define __HSVCOLOR_H__

#include "Arduino.h"

class HSVColor
{
//variables
public:
	float H, S, V;
protected:
private:

//functions
public:
	HSVColor(float t_hue, float t_saturation, float t_value);
	
	~HSVColor();
protected:
private:

}; //HSVColor

#endif //__HSVCOLOR_H__
