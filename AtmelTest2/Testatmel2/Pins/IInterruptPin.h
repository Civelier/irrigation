/* 
* IInterruptPin.h
*
* Created: 5/31/2019 2:59:19 PM
* Author: civel
*/


#ifndef __IINTERRUPTPIN_H__
#define __IINTERRUPTPIN_H__

//includes
#include "IDigitalPin.h"
#include "..\Enums.h"

class IInterruptPin : virtual public IDigitalPin, virtual public IPin
{
//functions
public:
	void AttachInterrupt(void(*t_ISR)(void), InterruptMode t_mode) { attachInterrupt(digitalPinToInterrupt(GetPin()), t_ISR, t_mode); }
		
protected:
	IInterruptPin() {}

}; //IInterruptPin

#endif //__IINTERRUPTPIN_H__
