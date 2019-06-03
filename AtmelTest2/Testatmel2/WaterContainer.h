/* 
* WaterContainer.h
*
* Created: 5/30/2019 12:02:25 AM
* Author: civel
*/


#ifndef __WATERCONTAINER_H__
#define __WATERCONTAINER_H__

//includes
#include "Devices/IDistanceSensor.h"
#include "Devices/IOnOffMotor.h"

class WaterContainer
{
//variables
public:
	float fVolume; //Liters
	float fMin, fMax, fMinDistance = 0, fMaxDistance = 1000; //Millimeters
	protected:
private:
	IDistanceSensor* m_DistSensor;
	float m_totalVolume = 20; //Liters

//functions
public:
	WaterContainer(IDistanceSensor* t_distSensor, float t_totalVolume = 20);
	
	void Refresh();
	
	float GetVolume();
	
	~WaterContainer();
protected:
private:

}; //WaterContainer

#endif //__WATERCONTAINER_H__
