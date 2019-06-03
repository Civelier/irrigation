/* 
* UltraSoundSensor.cpp
*
* Created: 6/1/2019 7:42:00 PM
* Author: civel
*/


#include "UltraSoundSensor.h"

// default constructor
UltraSoundSensor::UltraSoundSensor(IDigitalPin* t_trigPin, IDigitalPin* t_echoPin)
{
	m_trigPin = t_trigPin;
	m_echoPin = t_echoPin;
	t_echoPin->SetAsInput();
	t_trigPin->SetAsOutput();
	m_buffer = new AverageBuffer();
} //UltraSoundSensor

void UltraSoundSensor::Refresh()
{
	unsigned long lSum = 0;
	
	m_trigPin->Off();
	delayMicroseconds(50);
	m_trigPin->On();
	delayMicroseconds(10);
	m_trigPin->Off();
		
	m_buffer->AddValue(pulseIn(m_echoPin->Pin, HIGH)); //* 1000000 / 343000;
	
	fMillimeters = m_buffer->GetAverage() / 5.83f;
}

UltraSoundSensor::~UltraSoundSensor()
{
	m_buffer->~AverageBuffer();
	delete m_buffer;
}