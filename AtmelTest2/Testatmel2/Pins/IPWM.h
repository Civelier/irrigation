/* 
* IPWM.h
*
* Created: 5/31/2019 2:56:32 PM
* Author: civel
*/


#ifndef __IPWM_H__
#define __IPWM_H__

//includes
#include "IPin.h"
#include "IOutputPin.h"


class IPWM : virtual public IPin, virtual public IOutputPin
{
//variables
private:
	int m_power = 0;
//functions
public:
	void SetPower(uint8_t t_power)
	{
		analogWrite(GetPin(), t_power);
		m_power = t_power;
	}
	void SetPercent(float t_percent) { SetPower((int)(t_percent * 255)); }
	int GetPower() { return m_power; }
	float GetPercent() { return (float)GetPower() / 255; }
protected:
	IPWM() {}

}; //IPWM

#endif //__IPWM_H__
