/*
 * Enums.h
 *
 * Created: 5/28/2019 1:03:17 PM
 *  Author: civel
 */ 


#ifndef ENUMS_H_
#define ENUMS_H_

//includes
#include "Arduino.h"

//enums
enum PinType
{
	PTDigital,
	PTAnalog
};

enum PinIO
{
	PIIn = INPUT,
	PIOut = OUTPUT,
	PIInPullUp = INPUT_PULLUP
};

enum InterruptMode
{
	IMLow = LOW,
	IMChange = CHANGE,
	IMRising = RISING,
	IMFalling = FALLING
};

#endif /* ENUMS_H_ */