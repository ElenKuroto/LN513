/**
 * @file LN513.h 
 */
 
#ifndef LN513_H
#define LN513_H

#include <Arduino.h>

class LN513
{
public:
	/** Constructor */
	LN513();
	
	
	/** Destructor */
	virtual ~LN513();
	
public:
	/**
	 * initialize
	 * @param[in] is_cathode_common true:Cathode Common, false: Anode Common
	 * @param[in] pins LN513 of pin1,...7, 12 (default: arduino d1 to LN513 pin1,..., d7 to pin7, d12 to pin12)
	 */
	void initialize(bool is_cathode_common, const uint8_t* pins = NULL);
	
	/**
	 * change of light
	 * @param[in] digit 0...9
	 */
	void change(uint8_t digit);
	
private:
	uint8_t pinArray[8];
	bool cathodeCommon;
};

#endif
