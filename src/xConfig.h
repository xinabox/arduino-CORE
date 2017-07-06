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
 *				 RGB LED Pin Map 			    		*
 ********************************************************/
#if CPU == xCC01
	#define RED 5
	#define GREEN 6
	#define BLUE 7

#elif CPU == xCW01 
	#define RED 12
	#define GREEN 13
	#define BLUE 5
	
#elif CPU == xCR01 
	#define RED 14
	#define GREEN 15
	#define BLUE 16
#endif

#endif
