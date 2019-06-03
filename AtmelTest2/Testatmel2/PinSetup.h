/*
 * PinSetup.h
 *
 * Created: 5/28/2019 1:54:56 PM
 *  Author: civel
 */ 


#ifndef PINSETUP_H_
#define PINSETUP_H_

//includes
#include "Arduino.h"
#include "Pins\AnalogPin.h"
#include "Pins\DigitalIOPin.h"
#include "Defines.h"
#include "Devices\DigitalLED.h"
#include "Devices\AnalogLED.h"
#include "Devices\MyRGBLED.h"
#include "Devices\IRSensor.h"
#include "WaterContainer.h"
#include "Devices/IDistanceSensor.h"
#include "Devices/SimDistanceSensor.h"
#include "Devices/SimOnOffMotor.h"
#include "Devices/UltraSoundSensor.h"

DigitalIOPin* Digital00 = new DigitalIOPin(DIGITAL00_P);
DigitalIOPin* Digital01 = new DigitalIOPin(DIGITAL01_P);
DigitalInterruptPin* D2 = new DigitalInterruptPin(D2_P);
PWMInterruptPin* D3 = new PWMInterruptPin(D3_P);
DigitalIOPin* D4 = new DigitalIOPin(D4_P);
DigitalPWMPin* D5 = new DigitalPWMPin(D5_P);
DigitalPWMPin* D6 = new DigitalPWMPin(D6_P);
DigitalIOPin* D7 = new DigitalIOPin(D7_P);
DigitalIOPin* D8 = new DigitalIOPin(D8_P);
DigitalPWMPin* D9 = new DigitalPWMPin(D9_P);
DigitalPWMPin* D10 = new DigitalPWMPin(D10_P);
DigitalPWMPin* D11 = new DigitalPWMPin(D11_P);
DigitalIOPin* D12 = new DigitalIOPin(D12_P);

DigitalIOPin* D13 = new DigitalIOPin(D13_P);
AnalogPin* PA0 = new AnalogPin(A0_P);
AnalogPin* PA1 = new AnalogPin(A1_P);
AnalogPin* PA2 = new AnalogPin(A2_P);
AnalogPin* PA3 = new AnalogPin(A3_P);
AnalogPin* PA4 = new AnalogPin(A4_P);
AnalogPin* PA5 = new AnalogPin(A5_P);
AnalogPin* PA6 = new AnalogPin(A6_P);
AnalogPin* PA7 = new AnalogPin(A7_P);


//pins
DigitalLED* PumpLED = new DigitalLED(D12);
SimOnOffMotor* Pump = new SimOnOffMotor(PumpLED);
AnalogLED* GreenLEDFront = new AnalogLED(D3);
AnalogLED* GreenLEDBack = new AnalogLED(D5);
IRSensor* IRFront = new IRSensor(PA0);
IRSensor* IRBack = new IRSensor(PA1);
//SimDistanceSensor* DistFront = new SimDistanceSensor(IRFront);
//SimDistanceSensor* DistBack = new SimDistanceSensor(IRBack);
UltraSoundSensor* DistFront = new UltraSoundSensor(D6, D7);
UltraSoundSensor* DistBack = new UltraSoundSensor(D8, D9);
WaterContainer *FrontContainer = new WaterContainer(DistFront), *BackContainer = new WaterContainer(DistBack);

#endif /* PINSETUP_H_ */