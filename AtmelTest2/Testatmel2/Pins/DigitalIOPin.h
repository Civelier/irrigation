/* 
* DigitalIOPin.h
*
* Created: 5/31/2019 3:01:06 PM
* Author: civel
*/


#ifndef __DIGITALIOPIN_H__
#define __DIGITALIOPIN_H__

//includes
#include "IDigitalPin.h"
#include "IInputPin.h"
#include "IOutputPin.h"
#include "IPin.h"
#include "../Defines.h"

class DigitalIOPin :  virtual public IPin, public IDigitalPin
{
//variables
public:
protected:
private:

//functions
public:
	DigitalIOPin(uint8_t t_pin) { IPin::SetPin(t_pin); }
	~DigitalIOPin() {}
protected:
private:

}; //DigitalIOPin

#endif //__DIGITALIOPIN_H__
