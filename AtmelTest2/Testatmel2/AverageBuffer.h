/* 
* AverageBuffer.h
*
* Created: 6/1/2019 9:19:33 PM
* Author: civel
*/


#ifndef __AVERAGEBUFFER_H__
#define __AVERAGEBUFFER_H__

#define SAMPLE_COUNT 50

class AverageBuffer
{
//variables
public:
protected:
private:
	int m_currentIndex = 0;
	unsigned long m_buffer[SAMPLE_COUNT];

//functions
public:
	AverageBuffer();
	
	void AddValue(unsigned long t_value);
	
	unsigned long GetAverage();
	
	~AverageBuffer();
protected:
private:
	void MoveNext();

}; //AverageBuffer

#endif //__AVERAGEBUFFER_H__
