/* 
* SimDistanceSensor.cpp
*
* Created: 5/29/2019 11:52:24 PM
* Author: civel
*/


#include "SimDistanceSensor.h"

// default constructor
SimDistanceSensor::SimDistanceSensor(IRSensor* t_sensor)
{
	m_sensor = t_sensor;
	fMillimeters = 0;
} //SimDistanceSensor

void SimDistanceSensor::Refresh()
{
	fMillimeters = (1 - m_sensor->GetValue()) * 1000;
}

// default destructor
SimDistanceSensor::~SimDistanceSensor()
{
	m_sensor->~IRSensor();
	delete m_sensor;
} //~SimDistanceSensor
