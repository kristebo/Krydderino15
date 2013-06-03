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
	String sensorstring;
    sensorstring.reserve(30);
    char tmp_sensorstring[40] = {'\0', '\0', '\0', '\0', '\0', '\0'};
    float ph = -1.0;
    
    delay( 1000 ); // to avoid zero-reading on startup
    
    Serial3.print("r25.0\r");   // Tell the pH stamp to measure the pH probe
    delay(2000);             // Give the pH stamp time to do its magic
    
    while (Serial3.available() > 0) {
        read = (char) Serial3.read();
        sensorstring += read;
//      Serial.println(read);
    }
//    sensorstring += (char)'\0';
    sensorstring.toCharArray(tmp_sensorstring, 6);
    tmp_sensorstring[5] = '\0';
	ph = atof(tmp_sensorstring);
    
    Serial.print("Sensorstring: ");
    Serial.println( sensorstring );
    Serial.print("float pH:");
    Serial.println(ph);
    
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
    
	
	rounded_average = (float)(ph_sum / (PH_NUM_OF_SAMPLES));
    
	last_average = rounded_average;
    Serial.print("Rounded average: ");
    Serial.println(last_average);
    Serial.print("As (int): ");
    Serial.println((int)last_average);
    
	return rounded_average;
}