/* 
* UltraSoundSensor.h
*
* Created: 6/1/2019 7:42:00 PM
* Author: civel
*/


#ifndef __ULTRASOUNDSENSOR_H__
#define __ULTRASOUNDSENSOR_H__

//includes
#include "IDistanceSensor.h"
#include "..\Pins\PinIncludes.h"
#include "..\Defines.h"
#include "..\AverageBuffer.h"

class UltraSoundSensor : public IDistanceSensor
{
//variables
public:
protected:
private:
	IDigitalPin* m_trigPin;
	IDigitalPin* m_echoPin;
	AverageBuffer* m_buffer;

//functions
public:
	UltraSoundSensor(IDigitalPin* t_trigPin, IDigitalPin* t_echoPin);
	
	~UltraSoundSensor();
	
protected:
	virtual void Refresh() override;

private:

}; //UltraSoundSensor

#endif //__ULTRASOUNDSENSOR_H__
