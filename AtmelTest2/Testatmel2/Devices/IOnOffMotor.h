/* 
* IOnOffMotor.h
*
* Created: 5/30/2019 3:05:01 PM
* Author: civel
*/


#ifndef __IONOFFMOTOR_H__
#define __IONOFFMOTOR_H__

//includes
#include "..\Pins\DigitalIOPin.h"

class IOnOffMotor
{
//variables
public:
	bool bIsOn;
protected:
private:

//functions
public:
	virtual void TurnOn();
	virtual void TurnOff();
	void SetState(bool t_state)
	{
		if (t_state) TurnOn();
		else TurnOff();
	}
	
	void Toggle()
	{
		SetState(!bIsOn);
	}
	
	virtual ~IOnOffMotor();
protected:
	IOnOffMotor() { bIsOn = false; }
private:

}; //IOnOffMotor

#endif //__IONOFFMOTOR_H__
