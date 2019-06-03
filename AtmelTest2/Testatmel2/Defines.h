/*
 * Defines.h
 *
 * Created: 5/28/2019 2:21:17 PM
 *  Author: civel
 */ 

#ifndef DEFINES_H_
#define DEFINES_H_

//user variables
#define THRESHOLD 1 //Liters

#define NANO

//Debug
#define DEBUG_LEVEL 2


#ifdef DEBUG_LEVEL
	#define DebugWrite(text, lvl)\
	if (DEBUG_LEVEL <= lvl) Serial.print(text)
		
	#define DebugWriteLine(text, lvl)\
	if (DEBUG_LEVEL <= lvl) Serial.println(text)
#else
	#define DebugWrite(text, lvl)\
	if (false)
		
	#define DebugWriteLine(text, lvl)\
	if (false)
#endif //def DEBUG_LEVEL

#define Write(text) Serial.print(text)

#define WriteLine(text) Serial.println(text)

#endif /* DEFINES_H_ */