/*
	TLC5615.h - Arduino library support for the Digital-to-Analog conversion chip TLC5615
	Created by Luffy, May 1,2014.
	Released into the public domain.
	ver 1.0 BATE
*/
#ifndef TLC5615_h
#define TLC5615_h
 
#include "Arduino.h"
 
class TLC5615
{
  public:
    TLC5615(uint8_t DIN, uint8_t SCLK, uint8_t CS);
	void InitTLC5615();
	void DAConvert(uint16_t data);
  private:
	uint8_t DIN_Pin;
	uint8_t SCLK_Pin;
	uint8_t CS_Pin;
};
 
#endif
