/********************************************************
 	This is a library for the XinaBox Core Functions	

 	Core Functions include:								
 	-	I2C Communication												
 	-	Inter device communication

	Currently Spport Models:
	-	CW01
	-	CC01
	-	CR01	
*********************************************************/
 
#include "xCore.h"

/********************************************************
 	Constructor
*********************************************************/
xCore::xCore(){
	#if defined(ARDUINO_ESP8266_ESP01)
	Wire.begin(2,14);
	#else
	Wire.begin();
	#endif
}
/********************************************************
 	Writes an 8 bit value over I2C
*********************************************************/
void xCore::write8(byte device, byte reg, byte value) {
	Wire.beginTransmission((uint8_t)device);
	Wire.write((uint8_t)reg);
	Wire.write((uint8_t)value);
	Wire.endTransmission(false);
}

/********************************************************
 	Writes an 16 bit value over I2C
*********************************************************/
void xCore::write16(byte device, byte reg, uint16_t value) {
	Wire.beginTransmission((uint8_t)device);
	Wire.write((uint8_t)reg);
	Wire.write((0xFF & (value >> 0)));
	Wire.write((0xFF & (value << 8)));
	Wire.endTransmission(false);
}

/********************************************************
 	Reads an 8 bit value over I2C
*********************************************************/
uint8_t xCore::read8(byte device, byte reg) {
	uint8_t value;
	Wire.beginTransmission((uint8_t)device);
	Wire.write((uint8_t)reg);
	Wire.endTransmission(false);
	Wire.requestFrom((uint8_t)device, (uint8_t)1);
	value = Wire.read();
	return value;
}

/********************************************************
 	Reads an 16 bit value over I2C
*********************************************************/
uint16_t xCore::read16(byte device, byte reg) {
	uint16_t value;
	Wire.beginTransmission((uint8_t)device);
	Wire.write((uint8_t)reg);
	Wire.endTransmission(false);
	Wire.requestFrom((uint8_t)device, (uint8_t)2);
	value = (Wire.read() << 8) | Wire.read();
	return value;
}

/********************************************************
 	Reads a signed 16 bit value over I2C
*********************************************************/
int16_t xCore::readS16(byte device, byte reg) {
	return (int16_t)read16((uint8_t)device, (uint8_t)reg);
}

/********************************************************
 	Reads a signed 24 bit value over I2C
*********************************************************/
uint32_t xCore::read24(byte device, byte reg) {
	uint32_t value;

	Wire.beginTransmission((uint8_t)device);
	Wire.write((uint8_t)reg);
	Wire.endTransmission(false);
	Wire.requestFrom((uint8_t)device, (uint8_t)3);

	value = Wire.read();
	value <<= 8;
	value |= Wire.read();
	value <<= 8;
	value |= Wire.read();

	return value;
}
