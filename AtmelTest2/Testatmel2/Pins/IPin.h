/* 
* IPin.h
*
* Created: 5/28/2019 1:01:47 PM
* Author: civel
*/


#ifndef __IPIN_H__
#define __IPIN_H__

//includes
#include "../Enums.h"
#include <Arduino.h>

class IPin
{
//variables
private:
	

//functions
public:
	~IPin();
	uint8_t Pin;
	
	
protected: 
	IPin(){}
	IPin(uint8_t t_pin) { Pin = t_pin; }
	
	void SetPin(uint8_t t_pin) { Pin = t_pin; }
	uint8_t GetPin() { return Pin; }
	
	//PinType m_type;
	
	PinIO m_IO;
	
}; //IPin



#endif //__IPIN_H__
