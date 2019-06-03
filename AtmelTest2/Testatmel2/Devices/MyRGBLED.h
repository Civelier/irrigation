/* 
* MyRGBLED.h
*
* Created: 5/29/2019 10:45:02 PM
* Author: civel
*/


#ifndef __MYRGBLED_H__
#define __MYRGBLED_H__

#include "AnalogLED.h"
#include "..\MyColor.h"

class MyRGBLED
{
//variables
public:
protected:
private:
	IPWM *m_red, *m_green, *m_blue;

//functions
public:
	MyRGBLED(IPWM* t_redPin, IPWM* t_greenPin, IPWM* t_bluePin);
	
	void SetColor(float t_red, float t_green, float t_blue);
	void SetColor(MyColor* t_color);
	
	~MyRGBLED();
protected:
private:

}; //MyRGBLED

#endif //__MYRGBLED_H__
