//
//  Relay_12V.h 
//  Library header
//  ----------------------------------
//  Developed with embedXcode
//
//  Project Krydderino_008
//  Created by Haakon Storm Heen on 06.05.12
//  Copyright (c) 2012 Haakon Storm, Inc.
//

// Core library
#include "Arduino.h" // — for Arduino 0023
#include "MagicNumbers.h"

#ifndef Relay_12V_h
#define Relay_12V_h

class Relay_12V {
public:
	int local_pin_number;
	
	Relay_12V(int pin_number);
	void on(int millis_to_wait);
	void on(void);
	void off(void);
	int assigned_pin_number(void);
private:
	
};

#endif
