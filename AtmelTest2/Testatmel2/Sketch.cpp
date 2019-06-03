/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */

//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio

#include "Pins/PinIncludes.h"
#include "PinSetup.h"
#include "Defines.h"
#include "Buffer.h"
#include "MyColor.h"
#include "HSVColor.h"
#include "RGBColor.h"

//Buffer<float>* FrontBuffer = new Buffer<float>(10);
//Buffer<float>* BackBuffer = new Buffer<float>(10);


void setup() 
{
	// put your setup code here, to run once:
	Serial.begin(9600);
}

void loop() 
{
	// put your main code here, to run repeatedly:
	for (int i = 0; i < 100; i++)
	{
		GreenLEDFront->SetPower(DistFront->GetMeters() / 2);
		GreenLEDBack->SetPower(DistBack->GetMeters() / 2);
 		if (i == 0)
 		{
			 //FrontBuffer->SetNext(FrontContainer->GetVolume());
			 Write("Volume front: ");
			 Write(FrontContainer->GetVolume());
			 WriteLine("L");
			 Write("Volume back: ");
			 Write(BackContainer->GetVolume());
			 WriteLine("L");
 		}
		//GreenLED->SetPower(IR->GetValue());
		
		if (Pump->bIsOn)
		{
			if (FrontContainer->GetVolume() < BackContainer->GetVolume() - THRESHOLD / 2)
			{
				Pump->TurnOff();
				delay(MINIMUM_PUMP_TIME);
			}
		}
		else
		{	
			if (FrontContainer->GetVolume() - THRESHOLD / 2 > BackContainer->GetVolume())
			{
				Pump->TurnOn();
				delay(MINIMUM_PUMP_TIME);
			}
			if (BackContainer->GetVolume() < MINIMUM_LEVEL)
			{
				Pump->TurnOn();
				delay(MINIMUM_PUMP_TIME);
			}
		}
		
		delay(1);
	}
}
