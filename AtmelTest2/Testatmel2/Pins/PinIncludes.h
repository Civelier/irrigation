/*
 * PinIncludes.h
 *
 * Created: 5/31/2019 4:26:56 PM
 *  Author: civel
 */ 


#ifndef PININCLUDES_H_
#define PININCLUDES_H_

//includes
#include "..\Defines.h"
#include "DigitalIOPin.h"
#include "AnalogPin.h"
#include "DigitalInterruptPin.h"
#include "PWMInterruptPin.h"
#include "DigitalPWMPin.h"

#ifdef NANO


//Pins
#define DIGITAL01_P 1
#define DIGITAL00_P 0
//#define RESET 3
//#define GROUND 4
#define D2_P 2 //INTERRUPT
#define D3_P 3 //INTERRUPT, PWM
#define D4_P 4 //I2C : SDA
#define D5_P 5 //PWM, I2C : SCL
#define D6_P 6 //PWM
#define D7_P 7
#define D8_P 8
#define D9_P 9 //PWM
#define D10_P 10 //PWM, SPI : SS
#define D11_P 11 //PWM, SPI : MOSI
#define D12_P 12 //SPI : MISO

#define D13_P 13 //LED, SPI : SCK
#define A0_P 14
#define A1_P 15
#define A2_P 16
#define A3_P 17
#define A4_P 18
#define A5_P 19
#define A6_P 20
#define A7_P 21




#endif //ifdef NANO



#endif /* PININCLUDES_H_ */