/* 
* MyColor.h
*
* Created: 5/31/2019 10:56:58 PM
* Author: civel
*/


#ifndef __MYCOLOR_H__
#define __MYCOLOR_H__

//includes
#include "Arduino.h"
#include "RGBColor.h"
#include "HSVColor.h"

class MyColor
{
//variables
public:
	RGBColor* MyRGBColor;
protected:
private:

//functions
public:
	MyColor();
	MyColor(HSVColor* t_hsv);
	MyColor(RGBColor* t_rgb);
	
	static HSVColor* ToHSV(RGBColor* t_color)
	{
		HSVColor* out;
		double min, max, delta;

		min = t_color->R < t_color->G ? t_color->R : t_color->G;
		min = min  < t_color->B ? min  : t_color->B;

		max = t_color->R > t_color->G ? t_color->R : t_color->B;
		max = max  > t_color->B ? max  : t_color->B;

		out->V = max;                                // v
		delta = max - min;
		if (delta < 0.00001)
		{
			out->S = 0;
			out->H = 0; // undefined, maybe nan?
			return out;
		}
		if( max > 0.0 ) { // NOTE: if Max is == 0, this divide would cause a crash
			out->S = (delta / max);                  // s
			} else {
			// if max is 0, then r = g = b = 0
			// s = 0, h is undefined
			out->S = 0.0;
			out->H = NAN;                            // its now undefined
			return out;
		}
		if( t_color->R >= max )                           // > is bogus, just keeps compilor happy
		out->H = ( t_color->G - t_color->B ) / delta;        // between yellow & magenta
		else
		if( t_color->G >= max )
		out->H = 2.0 + ( t_color->B - t_color->R ) / delta;  // between cyan & yellow
		else
		out->H = 4.0 + ( t_color->R - t_color->G ) / delta;  // between magenta & cyan

		out->H *= 60.0;                              // degrees

		if( out->H < 0.0 )
		out->H += 360.0;

		return out;
	}
	
	static RGBColor* ToRGB(HSVColor* t_color)
	{
		float hh, p, q, t, ff;
		long i;
		RGBColor* out;

		if(t_color->S <= 0.0) {       // < is bogus, just shuts up warnings
			out->R = (uint8_t)t_color->V;
			out->G = (uint8_t)t_color->V;
			out->B = (uint8_t)t_color->V;
			return out;
		}
		hh = t_color->H;
		if(hh >= 360.0) hh = 0.0;
		hh /= 60.0;
		i = (long)hh;
		ff = hh - i;
		p = t_color->V * (1.0 - t_color->S);
		q = t_color->V * (1.0 - (t_color->S * ff));
		t = t_color->V * (1.0 - (t_color->S * (1.0 - ff)));

		switch(i) {
			case 0:
			out->R = (uint8_t)t_color->V;
			out->G = (uint8_t)t;
			out->B = (uint8_t)p;
			break;
			case 1:
			out->R = (uint8_t)q;
			out->G = (uint8_t)t_color->V;
			out->B = (uint8_t)p;
			break;
			case 2:
			out->R = (uint8_t)p;
			out->G = (uint8_t)t_color->V;
			out->B = (uint8_t)t;
			break;

			case 3:
			out->R = (uint8_t)p;
			out->G = (uint8_t)q;
			out->B = (uint8_t)t_color->V;
			break;
			case 4:
			out->R = (uint8_t)t;
			out->G = (uint8_t)p;
			out->B = (uint8_t)t_color->V;
			break;
			case 5:
			default:
			out->R = (uint8_t)t_color->V;
			out->G = (uint8_t)p;
			out->B = (uint8_t)q;
			break;
		}
		return out;
	}
	
	~MyColor();
protected:
private:

}; //MyColor

#endif //__MYCOLOR_H__
