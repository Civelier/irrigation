/* 
* SimOnOffMotor.h
*
* Created: 5/30/2019 3:11:27 PM
* Author: civel
*/


#ifndef __SIMONOFFMOTOR_H__
#define __SIMONOFFMOTOR_H__

//includes
#include "IOnOffMotor.h"
#include "DigitalLED.h"

class SimOnOffMotor : public IOnOffMotor
{
//variables
public:
protected:
private:
	DigitalLED* m_led;

//functions
public:
	SimOnOffMotor(DigitalLED* t_led);
	
	virtual void TurnOn() override;
	virtual void TurnOff() override;
	
	~SimOnOffMotor();
protected:
private:

}; //SimOnOffMotor

#endif //__SIMONOFFMOTOR_H__
