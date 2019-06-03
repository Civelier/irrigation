/* 
* DigitalLED.cpp
*
* Created: 5/29/2019 10:15:50 PM
* Author: civel
*/


#include "DigitalLED.h"

// default constructor
DigitalLED::DigitalLED(IDigitalPin* t_pin)
{
	m_led = t_pin;
	m_led->SetAsOutput();
	bIsOn = false;
} //DigitalLED

void DigitalLED::SetState(bool t_state)
{
	bIsOn = t_state;
	m_led->SetValue(bIsOn);
}

void DigitalLED::Toggle()
{
	bIsOn = !bIsOn;
	m_led->Toggle();
}

void DigitalLED::TurnOn()
{
	bIsOn = true;
	m_led->SetValue(true);
}

void DigitalLED::TurnOff()
{
	bIsOn = false;
	m_led->SetValue(false);
}

// default destructor
DigitalLED::~DigitalLED()
{
	delete m_led;
} //~DigitalLED
