/* 
* MyColor.cpp
*
* Created: 5/31/2019 10:56:58 PM
* Author: civel
*/


#include "MyColor.h"

// default constructor
MyColor::MyColor()
{
} //MyColor

MyColor::MyColor(RGBColor* t_rgb)
{
	MyRGBColor = t_rgb;
} //MyColor

MyColor::MyColor(HSVColor* t_hsv) : MyColor(ToRGB(t_hsv))
{
} //MyColor

// default destructor
MyColor::~MyColor()
{
	delete MyRGBColor;
} //~MyColor
