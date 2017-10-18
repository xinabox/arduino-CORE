/********************************************************
 *  This is a library for the XinaBox Configuration  	*
 *													  	*
 *	Core Functions include:								*
 *	-	I2C Communication								*
 *	-	Inter device communication						*
 *	-	RGB Control										*
 *														*
 ********************************************************/

#ifndef xConfig_h
#define xConfig_h

#include <stdint.h>

// Defines the BAUD rate
#define BAUD 115200

/********************************************************
 * RGB LED Pin Map 			    		*
 ********************************************************/
#define CR0X_RED 14
#define CR0X_GREEN 15
#define CR0X_BLUE 16

#define CW01_RED 12
#define CW01_GREEN 13
#define CW01_BLUE 5

#define CC01_RED 5
#define CC01_GREEN 6
#define CC01_BLUE 7

#define CW02_RED 25
#define CW02_GREEN 26
#define CW02_BLUE 27

#endif
