//
//  Temperature.cpp
//  C++ code
//  ----------------------------------
//  Developed with embedXcode
//
//  Project Krydderino_008
//  Created by Haakon Storm Heen on 05.05.12
//  Copyright (c) 2012 Haakon Storm, Inc.
//

// Core library
#include "Temperature.h"
#include "MagicNumbers.h"

Temperature::Temperature()
{
	// object constructor code here
}

float Temperature::temperature_in_celcius(void)
{
	uint8_t i;
	float average;
	int samples[TEMP_NUM_SAMPLES];
	
		// take N samples in a row, with a slight delay
	for (i=0; i< TEMP_NUM_SAMPLES; i++) 
	{
		samples[i] = analogRead(TEMP_THERMISTOR_PIN);
		delay(10);
	}
	
		// average all the samples out
	average = 0;
	for (i=0; i< TEMP_NUM_SAMPLES; i++) {
		average += samples[i];
	}
	average /= TEMP_NUM_SAMPLES;
	
		// convert the value 'average' to resistance
	average = 1023 / average - 1;
	average = TEMP_SERIES_RESISTOR / average;
	
	float steinhart;
	steinhart = average / TEMP_THERMISTOR_NOMINAL;     // (R/Ro)
	steinhart = log(steinhart);                  // ln(R/Ro)
	steinhart /= TEMP_BCOEFFICIENT;                // 1/B * ln(R/Ro)
	steinhart += 1.0 / (TEMP_TEMPERATURE_NOMINAL + 273.15); // + (1/To)
	steinhart = 1.0 / steinhart;                 // Invert
	steinhart -= 273.15;                         // convert to C
	
	return steinhart;
}

