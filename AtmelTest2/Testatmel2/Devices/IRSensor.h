/* 
* IRSensor.h
*
* Created: 5/29/2019 11:15:57 PM
* Author: civel
*/


#ifndef __IRSENSOR_H__
#define __IRSENSOR_H__

//includes
#include "..\Pins\PinIncludes.h"

class IRSensor
{
//variables
public:
protected:
private:
	AnalogPin* m_ir;

//functions
public:
	IRSensor(AnalogPin* t_analogPin);
	
	float GetValue();
	
	//float operator=(IRSensor* sensor) { return sensor->GetValue(); }
	
	~IRSensor();
protected:
private:

}; //IRSensor

#endif //__IRSENSOR_H__
