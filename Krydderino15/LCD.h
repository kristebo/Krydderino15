//
//  LCD.h
//  Krydderino_008
//
//  Created by Haakon Storm Heen on 04.05.12.
//  Adapted from code by Lennart Nilsen on 02.05.12.
//  Copyright (c) 2012 Haakon Storm, Inc. All rights reserved.
//

#ifndef Krydderino_008_LCD_h
#define Krydderino_008_LCD_h

#include "Status.h"

class LCD
{
public:	
	LCD(Status *_status);
	void init();
//	void test();
	void clear();
	void display(int row, const char string[16]);
	void print_ec_and_ppm(void);
	void print_plant_temp_and_rh(void);
	void print_water_level(void);
	void print_water_level_instant(void);
	void display_number(int number1, int number2);

	
private:		
};

#endif

