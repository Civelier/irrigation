/* 
* MyRGBLED.cpp
*
* Created: 5/29/2019 10:45:02 PM
* Author: civel
*/


#include "MyRGBLED.h"

// default constructor
MyRGBLED::MyRGBLED(IPWM* t_redPin, IPWM* t_greenPin, IPWM* t_bluePin)
{
	m_red = t_redPin;
	m_green = t_greenPin;
	m_blue = t_bluePin;
} //MyRGBLED

void MyRGBLED::SetColor(float t_red, float t_green, float t_blue)
{
	m_red->SetPercent(t_red);
	m_green->SetPercent(t_green);
	m_blue->SetPercent(t_blue);
}

void MyRGBLED::SetColor(MyColor* t_color)
{
	m_red->SetPower(t_color->MyRGBColor->R);
	m_green->SetPower(t_color->MyRGBColor->G);
	m_blue->SetPower(t_color->MyRGBColor->B);
}

// default destructor
MyRGBLED::~MyRGBLED()
{
	delete m_green;
	delete m_red;
	delete m_blue;
} //~MyRGBLED
