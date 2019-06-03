/* 
* SimOnOffMotor.cpp
*
* Created: 5/30/2019 3:11:27 PM
* Author: civel
*/


#include "SimOnOffMotor.h"

// default constructor
SimOnOffMotor::SimOnOffMotor(DigitalLED* t_led)
{
	m_led = t_led;
} //SimOnOffMotor

void SimOnOffMotor::TurnOn()
{
	bIsOn = true;
	m_led->TurnOn();
}

void SimOnOffMotor::TurnOff()
{
	bIsOn = false;
	m_led->TurnOff();
}

// default destructor
SimOnOffMotor::~SimOnOffMotor()
{
	m_led->~DigitalLED();
	delete m_led;
} //~SimOnOffMotor
