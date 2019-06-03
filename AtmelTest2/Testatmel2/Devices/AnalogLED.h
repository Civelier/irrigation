/* 
* AnalogLED.h
*
* Created: 5/29/2019 10:31:06 PM
* Author: civel
*/


#ifndef __ANALOGLED_H__
#define __ANALOGLED_H__

//includes
#include "..\Pins\PinIncludes.h"

class AnalogLED
{
//variables
public:
	float fPower;
protected:
private:
	IPWM* m_led;

//functions
public:
	AnalogLED(IPWM* t_pin);
	
	void TurnOn();
	void TurnOff();
	void SetPower(float t_power);
	void SetPower(int t_power);
	
	~AnalogLED();
protected:
private:

}; //AnalogLED

#endif //__ANALOGLED_H__
