/* 
* IOutputPin.h
*
* Created: 5/31/2019 2:57:41 PM
* Author: civel
*/


#ifndef __IOUTPUTPIN_H__
#define __IOUTPUTPIN_H__

//includes
#include "IPin.h"

class IOutputPin : virtual public IPin
{
//functions
public:
	void SetAsOutput() 
	{
		pinMode(IPin::GetPin(), OUTPUT);
		IPin::m_IO = PinIO::PIOut;
	}
	
protected:
	IOutputPin() {}

}; //IOutputPin

#endif //__IOUTPUTPIN_H__
