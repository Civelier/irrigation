/* 
* HSVColor.cpp
*
* Created: 5/31/2019 10:59:31 PM
* Author: civel
*/


#include "HSVColor.h"

// default constructor
HSVColor::HSVColor(float t_hue, float t_saturation, float t_value)
{
	H = t_hue;
	S = t_saturation;
	V = t_value;
} //HSVColor

// default destructor
HSVColor::~HSVColor()
{
} //~HSVColor
