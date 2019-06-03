/* 
* IDigitalPin.h
*
* Created: 5/31/2019 2:58:06 PM
* Author: civel
*/


#ifndef __IDIGITALPIN_H__
#define __IDIGITALPIN_H__

//includes
#include "IInputPin.h"
#include "IOutputPin.h"

class IDigitalPin : virtual public IInputPin, virtual public IOutputPin, virtual public IPin
{
//functions
public:
	bool bIsOn = false;

	bool GetValue() { return digitalRead(IPin::GetPin()); }
	void SetValue(bool t_value)
	{
		bIsOn = t_value;
		digitalWrite(IPin::GetPin(), bIsOn);
	}
	
	void Toggle() { SetValue(!bIsOn); }
	
	void On() { SetValue(true); }
	void Off() { SetValue(false); }
		
protected:
	IDigitalPin() {}

}; //IDigitalPin

#endif //__IDIGITALPIN_H__
