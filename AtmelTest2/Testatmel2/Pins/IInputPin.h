/* 
* IInputPin.h
*
* Created: 5/31/2019 2:57:08 PM
* Author: civel
*/


#ifndef __IINPUTPIN_H__
#define __IINPUTPIN_H__

//includes
#include "IPin.h"

class IInputPin : virtual public IPin
{
//functions
public:
	void SetAsInput() 
	{ 
		pinMode(IPin::GetPin(), INPUT);
		//m_IO = PinIO::PIIn;
	}
	void SetAsInputPullup() 
	{ 
		pinMode(IPin::GetPin(), INPUT_PULLUP);
		//m_IO = PinIO::PIInPullUp;
	}
	
protected:
	IInputPin() {}
}; //IInputPin

#endif //__IINPUTPIN_H__
