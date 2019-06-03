/* 
* PWMInterruptPin.h
*
* Created: 5/31/2019 3:09:35 PM
* Author: civel
*/


#ifndef __PWMINTERRUPTPIN_H__
#define __PWMINTERRUPTPIN_H__

//includes
#include "IPWM.h"
#include "IPin.h"
#include "IInterruptPin.h"

class PWMInterruptPin : virtual public IPWM, virtual public IInterruptPin, virtual public IDigitalPin, virtual public IPin, virtual public IInputPin, virtual public IOutputPin
{
//functions
public:
	PWMInterruptPin(uint8_t t_pin) { SetPin(t_pin); }

}; //PWMInterruptPin

#endif //__PWMINTERRUPTPIN_H__
