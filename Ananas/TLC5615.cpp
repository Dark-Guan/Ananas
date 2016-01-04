/*
	TLC5615.cpp - Arduino library support for the Digital-to-Analog conversion chip TLC5615
	Created by Luffy, May 1,2014.
	Released into the public domain.
	ver 1.0 BATE
*/

#include "Arduino.h"
#include "TLC5615.h"

TLC5615::TLC5615(uint8_t DIN, uint8_t SCLK, uint8_t CS)
{
	pinMode(DIN, OUTPUT);
	pinMode(SCLK, OUTPUT);
	pinMode(CS, OUTPUT);
	DIN_Pin = DIN;
	SCLK_Pin = SCLK;
	CS_Pin = CS;
	InitTLC5615();


	//initial the voltage
}

void TLC5615::InitTLC5615()
{
//	digitalWrite(CS_Pin, HIGH);
	digitalWrite(CS_Pin, LOW);
	digitalWrite(SCLK_Pin, LOW);
}

void TLC5615::DAConvert(uint16_t data)
{
	InitTLC5615();
	for (unsigned char i=0; i<12; i++)
	{
		if (data & 0x200)
			digitalWrite(DIN_Pin, HIGH);
		else
			digitalWrite(DIN_Pin, LOW);
		digitalWrite(SCLK_Pin, HIGH);
		data = data<<1;		
		digitalWrite(SCLK_Pin, LOW);
	}
	digitalWrite(CS_Pin, HIGH);
	digitalWrite(SCLK_Pin, LOW);
}
