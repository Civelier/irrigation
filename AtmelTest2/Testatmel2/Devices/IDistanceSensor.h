/* 
* IDistanceSensor.h
*
* Created: 5/29/2019 11:40:03 PM
* Author: civel
*/


#ifndef __IDISTANCESENSOR_H__
#define __IDISTANCESENSOR_H__

//includes



class IDistanceSensor
{
//variables
public:
	float fMillimeters;
protected:
	unsigned int m_samples = 5;

//functions
public:
	float GetMillimeters() 
	{ 
		Refresh();
		return fMillimeters; 
	}
	float GetCentimeters() { return GetMillimeters() / 10; }
	float GetMeters() { return GetMillimeters() / 1000; }
	float GetInches() { return GetMillimeters() / 25.4; }
	float GetFeet() { return GetInches() / 12; }
		
	void SetSampleCount(unsigned int t_samples) { m_samples = t_samples; }
	
	virtual ~IDistanceSensor() {}
	
protected:
	virtual void Refresh();
}; //IDistanceSensor

#endif //__IDISTANCESENSOR_H__
