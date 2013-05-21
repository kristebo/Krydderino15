//
//  PH.cpp
//  Krydderino_008
//
//  Created by Daniel Høgli Olufsen on 28.05.12.
//  Copyright (c) 2012 Haakon Storm, Inc. All rights reserved.
//

#include "PH.h"
#include "MagicNumbers.h"
#include <string.h>

PH::PH()
{  
}

int PH::initialize_ph_sensor(void)
{
	Serial3.begin(PH_BAUD_RATE);
	
	return 0; // OK
}

float PH::read_sensor(void)
{
	sensorstring = "";
    float ph = -1.0;
    Serial3.print("r\r");
    
    while (Serial3.available() > 0) {
        read = (char)Serial3.read();
        
        sensorstring += read;
    }
    
	ph = atoi(sensorstring);
    
    return ph;
}

float PH::averaged_reading(void)
{
	float total_samples[PH_NUM_OF_SAMPLES];
	int i;
	float ph_sum = 0.0;
	float rounded_average = 1.0;
	
	for (i=0; i < PH_NUM_OF_SAMPLES; i++)
	{
		total_samples[i] = read_sensor();
		ph_sum += total_samples[i];
	}
    
	
	rounded_average = (float)(ph_sum / PH_NUM_OF_SAMPLES);
    
	last_average = rounded_average;
	return rounded_average;
}