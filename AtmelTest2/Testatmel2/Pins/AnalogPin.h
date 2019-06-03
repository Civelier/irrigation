/* 
* AnalogPin.h
*
* Created: 5/28/2019 1:33:49 PM
* Author: civel
*/


#ifndef __ANALOGPIN_H__
#define __ANALOGPIN_H__

//includes
#include "IAnalogInput.h"

class AnalogPin : public IAnalogInput, virtual public IPin
{
//functions
public:
	AnalogPin(uint8_t t_pin) : IPin(t_pin) {}

}; //AnalogPin

#endif //__ANALOGPIN_H__
