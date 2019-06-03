/* 
* IAnalogInput.h
*
* Created: 5/31/2019 3:19:10 PM
* Author: civel
*/


#ifndef __IANALOGINPUT_H__
#define __IANALOGINPUT_H__

//includes
#include "IInputPin.h"

class IAnalogInput : virtual public IPin, virtual public IInputPin
{
//functions
public:
	int GetValue() { return analogRead(IPin::GetPin()); }
	
	float GetPercent() { return (float)GetValue() / 1024.0f; }

protected:
	IAnalogInput() {}
}; //IAnalogInput

#endif //__IANALOGINPUT_H__
