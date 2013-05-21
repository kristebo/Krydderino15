//
//  Relay_12V.cpp
//  C++ code
//  ----------------------------------
//  Developed with embedXcode
//
//  Project Krydderino_008
//  Created by Haakon Storm Heen on 06.05.12
//  Copyright (c) 2012 Haakon Storm, Inc.
//

// Core library
#include "Arduino.h" // — for Arduino 0023
#include "Relay_12V.h"

Relay_12V::Relay_12V(int pin_number)	
{
	local_pin_number = pin_number;
	pinMode(pin_number, OUTPUT);
}

void Relay_12V::on(void)
{
	pinMode(local_pin_number, OUTPUT);
	digitalWrite(local_pin_number, HIGH);
}

void Relay_12V::on(int millis_to_wait)
{
	pinMode(local_pin_number, OUTPUT);
	digitalWrite(local_pin_number, HIGH);
	delay(millis_to_wait);
	digitalWrite(local_pin_number, LOW);	
}

void Relay_12V::off(void)
{
	pinMode(local_pin_number, OUTPUT);
	digitalWrite(local_pin_number, LOW);	
}

int Relay_12V::assigned_pin_number(void)
{
	return local_pin_number;
}
