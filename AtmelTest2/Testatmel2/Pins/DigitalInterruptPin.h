/* 
* DigitalInterruptPin.h
*
* Created: 5/31/2019 4:24:11 PM
* Author: civel
*/


#ifndef __DIGITALINTERRUPTPIN_H__
#define __DIGITALINTERRUPTPIN_H__

//includes
#include "IInterruptPin.h"

class DigitalInterruptPin : public IInterruptPin, virtual public IPin
{
//functions
public:
	DigitalInterruptPin(uint8_t t_pin) : IPin(t_pin) {}

}; //DigitalInterruptPin

#endif //__DIGITALINTERRUPTPIN_H__
