
//  Sensirion.h
//  Krydderino_008
//
//  Created by Haakon Storm Heen on 29.04.12.
//  Copyright (c) 2012 Haakon Storm, Inc. All rights reserved.

#ifndef Krydderino_008_Sensirion_h
#define Krydderino_008_Sensirion_h

	// Technical details
	// https://www.adafruit.com/products/464

//#include "magic_numbers.h"
//#include <WProgram.h>

class Sensirion
{
	public:	
		Sensirion();
		float read_temperature(void);
		float read_humidity(void);

	private:		
};

#endif

