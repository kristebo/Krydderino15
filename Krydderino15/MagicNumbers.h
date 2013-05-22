//
//  MagicNumbers.h
//  Krydderino_008
//
//  Created by Haakon Storm Heen on 29.04.12.
//  Copyright (c) 2012 Haakon Storm, Inc. All rights reserved.
//

#ifndef Krydderino_008_MagicNumbers_h
#define Krydderino_008_MagicNumbers_h

	// ***********************************************
	// 		PARAMETERS FOR 24V MISTER RELAY
	// ***********************************************

#define MISTER_PIN			35

	// ***********************************************
	// 		PARAMETERS FOR 24V MISTER FAN RELAY
	// ***********************************************

#define MISTER_FAN_PIN		31

	// ***********************************************
	// 		PARAMETERS FOR 12V SOLENOIDS
	// ***********************************************

#define PPM_PIN			32
#define PHPLUS_PIN		33
#define PHMINUS_PIN		34


	// ***********************************************
	// 		PARAMETERS FOR 12V PLANT VENT RELAY
	// ***********************************************

#define PLANT_FAN_PIN		30

	// ***********************************************
	// 		PARAMETERS FOR EC SENSOR LIBRARY
	// ***********************************************

#define EC_NUM_OF_SAMPLES	30
#define EC_SAMPLE_DELAY		10
#define EC_TX				16
#define EC_RX				17
#define EC_BAUD_RATE		38400

	// ***********************************************
	// 		PARAMETERS FOR PH SENSOR LIBRARY
	// ***********************************************

#define PH_NUM_OF_SAMPLES	10
#define PH_SAMPLE_DELAY		10
#define PH_RX				14
#define PH_TX				15
#define PH_BAUD_RATE		38400

	// ***********************************************
	// 		PARAMETERS FOR WATER TEMPERATURE LIBRARY
	// ***********************************************

#define TEMP_THERMISTOR_PIN		A1
	// resistance at 25 degrees C
#define TEMP_THERMISTOR_NOMINAL 10000      
	// temp. for nominal resistance (almost always 25 C)
#define TEMP_TEMPERATURE_NOMINAL 25   
	// how many samples to take and average
#define TEMP_NUM_SAMPLES 5
	// beta coefficient of the thermistor (usually 3000-4000)
#define TEMP_BCOEFFICIENT 3950
	// the value of the 'other' resistor
#define TEMP_SERIES_RESISTOR 10000   


	// **************************************************
	// 		PARAMETERS FOR SENSIRION RH/TEMP LIBRARY
	// **************************************************

	//used to be 10
#define SENSIRION_DATA_PIN		53
	//used to be 11
#define SENSIRION_CLOCK_PIN		52

	// ***********************************************
	// 		PARAMETERS FOR WATER LEVEL LIBRARY
	// ***********************************************

enum WL_STATUS {		// tokenized water level
	WL_EMPTY,
	WL_LOW,
	WL_NORMAL,
	WL_TOO_HIGH	
};

	// Class WATER_LEVEL constants
#define WL_SERIESRESISTOR 		468 // fixed resistor (measured and soldered)
#define WL_SENSOR_PIN 			A0 // What pin to connect the sensor to
#define WL_NUMBER_OF_READINGS	40
#define WL_WATER_LEVEL_DELAY	50 // milliseconds between initial readings

#define WL_EMPTY_THRESH 	2
#define WL_LOW_THRESH 		4
#define WL_NORMAL_THRESH 	10

#define WL_12_INCHES		375
#define WL_11_INCHES 		361
#define WL_10_INCHES 		347
#define WL_9_INCHES 		332
#define WL_8_INCHES 		314
#define WL_7_INCHES 		293
#define WL_6_INCHES 		273
#define WL_5_INCHES 		255
#define WL_4_INCHES 		223
#define WL_3_INCHES 		197
#define WL_2_INCHES 		167
#define WL_1_INCHES 		126

#endif
