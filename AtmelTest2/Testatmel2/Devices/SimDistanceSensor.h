/* 
* SimDistanceSensor.h
*
* Created: 5/29/2019 11:52:24 PM
* Author: civel
*/


#ifndef __SIMDISTANCESENSOR_H__
#define __SIMDISTANCESENSOR_H__

//includes
#include "IDistanceSensor.h"
#include "IRSensor.h"

class SimDistanceSensor : public IDistanceSensor
{
//variables
public:
protected:
private:
	IRSensor* m_sensor;
	

//functions
public:
	SimDistanceSensor(IRSensor* t_sensor);
	
	virtual void Refresh() override;
	
	~SimDistanceSensor();
protected:
private:

}; //SimDistanceSensor

#endif //__SIMDISTANCESENSOR_H__
