/* 
* WaterContainer.cpp
*
* Created: 5/30/2019 12:02:25 AM
* Author: civel
*/


#include "WaterContainer.h"
#include <Arduino.h>

// default constructor
WaterContainer::WaterContainer(IDistanceSensor* t_distSensor, float t_totalVolume /* = 20 */)
{
	m_DistSensor = t_distSensor;
	m_totalVolume = t_totalVolume;
} //WaterContainer

void WaterContainer::Refresh()
{
	float fDistance = m_DistSensor->GetMillimeters();
	fVolume = (fMaxDistance - m_DistSensor->GetMillimeters()) / (fMaxDistance - fMinDistance) * m_totalVolume;
}

float WaterContainer::GetVolume()
{
	Refresh();
	return fVolume;
}

// default destructor
WaterContainer::~WaterContainer()
{
	m_DistSensor->~IDistanceSensor();
	delete m_DistSensor;
} //~WaterContainer
