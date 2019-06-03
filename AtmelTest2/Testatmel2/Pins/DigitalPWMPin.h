/* 
* DigitalPWMPin.h
*
* Created: 5/31/2019 4:30:59 PM
* Author: civel
*/


#ifndef __DIGITALPWMPIN_H__
#define __DIGITALPWMPIN_H__

//includes
#include "IPin.h"
#include "IPWM.h"
#include "IDigitalPin.h"

class DigitalPWMPin : virtual public IPin, public IDigitalPin, public IPWM
{
//functions
public:
	DigitalPWMPin(uint8_t t_pin) { IPin::SetPin(t_pin); }

}; //DigitalPWMPin

#endif //__DIGITALPWMPIN_H__
