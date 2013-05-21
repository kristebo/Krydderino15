//
//  PH.h
//  Krydderino_008
//
//  Created by Daniel Høgli Olufsen on 28.05.12.
//  Copyright (c) 2012 Haakon Storm, Inc. All rights reserved.
//

#ifndef Krydderino_008_PH_h
#define Krydderino_008_PH_h

// Core library
#include "Arduino.h" // — for Arduino 0023
#include "MagicNumbers.h"

class PH
{
public:	
	float last_average;
	float last_samples[PH_NUM_OF_SAMPLES];
	
    char read;
	
    bool input_stringcomplete;
	bool sensor_stringcomplete;
    
	PH(void);
	float read_sensor(void);
	int initialize_ph_sensor(void);
    float averaged_reading(void);
	
private:		
};


#endif