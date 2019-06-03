/* 
* AverageBuffer.cpp
*
* Created: 6/1/2019 9:19:33 PM
* Author: civel
*/


#include "AverageBuffer.h"

// default constructor
AverageBuffer::AverageBuffer()
{
	for (int i = 0; i < SAMPLE_COUNT; i++)
	{
		m_buffer[i] = 0;
	}
} //AverageBuffer

void AverageBuffer::AddValue(unsigned long t_value)
{
	m_buffer[m_currentIndex] = t_value;
	MoveNext();
}

unsigned long AverageBuffer::GetAverage()
{
	unsigned long ulSum = 0;
	
	for (int i = 0; i < SAMPLE_COUNT; i++)
	{
		ulSum += m_buffer[i];
	}
	return ulSum / SAMPLE_COUNT;
}

void AverageBuffer::MoveNext()
{
	m_currentIndex++;
	if (m_currentIndex >= SAMPLE_COUNT) m_currentIndex = 0;
}

// default destructor
AverageBuffer::~AverageBuffer()
{
} //~AverageBuffer
