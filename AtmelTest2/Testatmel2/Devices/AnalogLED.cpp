/* 
* AnalogLED.cpp
*
* Created: 5/29/2019 10:31:06 PM
* Author: civel
*/


#include "AnalogLED.h"

// default constructor
AnalogLED::AnalogLED(IPWM* t_pin)
{
	m_led = t_pin;
	m_led->SetAsOutput();
	fPower = 0;
} //AnalogLED

void AnalogLED::SetPower(float t_power)
{
	fPower = t_power;
	m_led->SetPercent(fPower);
}

void AnalogLED::SetPower(int t_power)
{
	m_led->SetPower(t_power);
	fPower = m_led->GetPercent();
}

void AnalogLED::TurnOn()
{
	SetPower(1.0f);
}

void AnalogLED::TurnOff()
{
	SetPower(0);
}

// default destructor
AnalogLED::~AnalogLED()
{
	delete m_led;
} //~AnalogLED
