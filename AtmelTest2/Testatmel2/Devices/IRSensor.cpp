/* 
* IRSensor.cpp
*
* Created: 5/29/2019 11:15:57 PM
* Author: civel
*/


#include "IRSensor.h"

// default constructor
IRSensor::IRSensor(AnalogPin* t_analogPin)
{
	m_ir = t_analogPin;
} //IRSensor

float IRSensor::GetValue()
{
	return m_ir->GetPercent();
}

// default destructor
IRSensor::~IRSensor()
{
	m_ir->~AnalogPin();
	delete m_ir;
} //~IRSensor
