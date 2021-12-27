#include "LN513.h"
#include <stdio.h>

LN513::LN513()
: cathodeCommon(true)
{
	for (int i = 0; i < 8; ++i) {
		pinArray[i] = i + 1;
	}
	pinArray[7] = 12;
}

LN513::~LN513()
{
}

void LN513::initialize(bool is_cathode_common, const uint8_t* pins)
{
	if (pins != NULL) {
		memcpy(pinArray, pins, sizeof(uint8_t) * 8);
	}
	
	cathodeCommon = is_cathode_common;
	uint8_t off = (cathodeCommon) ? LOW : HIGH;
	for (int i = 0; i < 8; ++i) {
		pinMode(pinArray[i], OUTPUT);
		digitalWrite(pinArray[i], off);
	}
}

void LN513::change(uint8_t digit)
{
	uint8_t light = (cathodeCommon) ? HIGH : LOW;
	uint8_t off = (cathodeCommon) ? LOW : HIGH;
	
	for (int i = 0; i < 8; ++i) {
		digitalWrite(pinArray[i], off);
	}

	switch (digit) {
		case 0:
			digitalWrite(pinArray[0], light);
			digitalWrite(pinArray[1], light);
			digitalWrite(pinArray[2], light);
			digitalWrite(pinArray[3], light);
			digitalWrite(pinArray[4], light);
			digitalWrite(pinArray[5], light);
			break;
		case 1:
			digitalWrite(pinArray[0], light);
			digitalWrite(pinArray[5], light);
			break;
			
		case 2:
			digitalWrite(pinArray[0], light);
			digitalWrite(pinArray[1], light);
			digitalWrite(pinArray[3], light);
			digitalWrite(pinArray[4], light);
			digitalWrite(pinArray[7], light);
			break;
			
		case 3:
			digitalWrite(pinArray[0], light);
			digitalWrite(pinArray[1], light);
			digitalWrite(pinArray[4], light);
			digitalWrite(pinArray[5], light);
			digitalWrite(pinArray[7], light);
			break;
			
		case 4:
			digitalWrite(pinArray[0], light);
			digitalWrite(pinArray[2], light);
			digitalWrite(pinArray[5], light);
			digitalWrite(pinArray[7], light);
			break;
			
		case 5:
			digitalWrite(pinArray[1], light);
			digitalWrite(pinArray[2], light);
			digitalWrite(pinArray[4], light);
			digitalWrite(pinArray[5], light);
			digitalWrite(pinArray[7], light);
			break;
			
		case 6:
			digitalWrite(pinArray[1], light);
			digitalWrite(pinArray[2], light);
			digitalWrite(pinArray[3], light);
			digitalWrite(pinArray[4], light);
			digitalWrite(pinArray[5], light);
			digitalWrite(pinArray[7], light);
			break;
			
		case 7:
			digitalWrite(pinArray[0], light);
			digitalWrite(pinArray[1], light);
			digitalWrite(pinArray[2], light);
			digitalWrite(pinArray[5], light);
			break;
			
		case 8:
			digitalWrite(pinArray[0], light);
			digitalWrite(pinArray[1], light);
			digitalWrite(pinArray[2], light);
			digitalWrite(pinArray[3], light);
			digitalWrite(pinArray[4], light);
			digitalWrite(pinArray[5], light);
			digitalWrite(pinArray[7], light);
			break;
			
		case 9:
			digitalWrite(pinArray[0], light);
			digitalWrite(pinArray[1], light);
			digitalWrite(pinArray[2], light);
			digitalWrite(pinArray[4], light);
			digitalWrite(pinArray[5], light);
			digitalWrite(pinArray[7], light);
			break;
			
		default:
			break;
	}
}

