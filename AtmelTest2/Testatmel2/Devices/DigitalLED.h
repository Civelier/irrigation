/* 
* DigitalLED.h
*
* Created: 5/29/2019 10:15:50 PM
* Author: civel
*/


#ifndef __DIGITALLED_H__
#define __DIGITALLED_H__

//includes
#include "..\Pins\PinIncludes.h"

class DigitalLED
{
//variables
public:
	bool bIsOn;
protected:
private:
	IDigitalPin* m_led;

//functions
public:
	DigitalLED(IDigitalPin* t_pin);
	
	void TurnOn();
	void TurnOff();
	void Toggle();
	void SetState(bool t_state);
	
	~DigitalLED();
protected:
private:

}; //DigitalLED

#endif //__DIGITALLED_H__
