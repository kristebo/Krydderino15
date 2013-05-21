
// LCD Library
// 
// Compatible with the Hitachi HD44780 driver. 
// 16-pin interface.

#include <LiquidCrystal.h>
#include "LCD.h"
#include "Arduino.h" // — for Arduino 0023
#include "MagicNumbers.h"
#include "Status.h"
#include <stdint.h> //for uint8_t

const int print_delay = 2000; // ms

	// initialize the library with the numbers of the interface pins
LiquidCrystal lcd_local(2, 3, 4, 5, 6, 7); 
//LiquidCrystal lcd_local(8, 9, 10, 11, 12, 13);
Status *local_status;

LCD::LCD(Status *_status)
{
	local_status = _status;
}

void LCD::init(void)
{
		//	byte degree_glyph[8] = {
		//		B00000,
		//		B000110,
		//		B001001,
		//		B000110,
		//		B00000,
		//		B00000,
		//		B00000,
		//	};
	
		// set up the LCD's number of columns and rows: 
	lcd_local.begin(16, 2);
		// Print a message to the LCD.
		//setCursor(0, 1);
		//	lcd_local.createChar(0, degree_glyph);
    uint8_t tmp_char = 0;
	lcd_local.write(tmp_char);
}

void LCD::print_ec_and_ppm(void)
{
		//		       1234567890123456
	char string[17] = "Water PPM: "; // +1 for \0
	char num[5] = "\0\0C\0";
	
	lcd_local.clear();
	lcd_local.setCursor(0, 0);
	itoa(local_status->water_ec, num, 10); // base 10
	strcat(string, num);
	lcd_local.print(string);
	
		//		       1234567890123456
	char string2[17] = "Water pH: "; // +1 for \0
	char num2[5] = "\0\0%\0";
	
	lcd_local.setCursor(0, 1);
	itoa(local_status->water_ph, num2, 10); // base 10
	strcat(string2, num2);
	lcd_local.print(string2);
}

void LCD::print_plant_temp_and_rh(void)
{
		// print plant temperature
		//		       1234567890123456
//	lcd_local.begin(16, 2);

	char string[17] = "Plant temp: "; // +1 for \0
	char num[5] = "\0\0C\0";
	
	lcd_local.clear();
	lcd_local.setCursor(0, 0);
	itoa(local_status->plant_temperature, num, 10); // base 10
	strcat(string, num);
	lcd_local.print(string);

		// print plant temperature on second LCD row
		//		       1234567890123456
	char string2[17] = "Humidity: "; // +1 for \0
	char num2[5] = "\0\0%\0";
	
	lcd_local.setCursor(0, 1);
	itoa(local_status->plant_humidity, num2, 10); // base 10
	strcat(string2, num2);
	lcd_local.print(string2);
}

void LCD::print_water_level(void)
{
		// print instantaneous water level
	char string[17] = "Water temp: "; // +1 for \0
	char num[4] = "\0\0\0";
	
	lcd_local.clear();
	lcd_local.setCursor(0, 0);
	itoa(local_status->water_temperature, num, 10); // base 10
	strcat(string, num);
	lcd_local.print(string);
	
		// print water temperature on second LCD row
	char string2[17] = "Water: "; // +1 for \0
	char num2[4] = "\0\0\0";
	lcd_local.setCursor(0, 1);
	
	switch (local_status->water_level) 
	{
		case WL_EMPTY: strcat(string2, "EMPTY! "); break;
		case WL_LOW: strcat(string2, "LOW! "); break;
		case WL_NORMAL: strcat(string2, "NORMAL "); break;
		case WL_TOO_HIGH: strcat(string2, "TOO HIGH! "); break;		
	}
	
	lcd_local.print(string2);
}

void LCD::print_water_level_instant(void)
{
		// print instantaneous water level
	char string[17] = "W.depth: "; // +1 for \0
	char num[4] = "\0\0\0";
	
	lcd_local.clear();
	lcd_local.setCursor(0, 0);
	itoa(local_status->water_level_instant, num, 10); // base 10
	strcat(string, num);
	lcd_local.print(string);
	
		// print water temperature on second LCD row
	char string2[17] = "W.inches: "; // +1 for \0
	char num2[4] = "\0\0\0";
	lcd_local.setCursor(0, 1);
	itoa(local_status->water_level_in_inches, num2, 10); // base 10
	strcat(string2, num2);
	lcd_local.print(string2);
}


void LCD::display(int row, const char string[16])
{
	lcd_local.setCursor(0, row);
	lcd_local.print(string);
}

void LCD::display_number(int number1, int number2)
{
		// print instantaneous water level
	char string[17] = "COUNTER: "; // +1 for \0
	char num[4] = "\0\0\0";
	
	lcd_local.clear();
	lcd_local.setCursor(0, 0);
	itoa(number1, num, 10); // base 10
	strcat(string, num);
	lcd_local.print(string);
	
		// print water temperature on second LCD row
//	char string2[17] = "PIN 2: "; // +1 for \0
//	char num2[4] = "\0\0\0";
//	lcd_local.setCursor(0, 1);
//	itoa(number2, num2, 10); // base 10
//	strcat(string2, num2);
//	lcd_local.print(string2);
}

void LCD::clear(void)
{
	lcd_local.clear();
}

//
//void LCD::test() 
//{
//	lcd_local.clear();
//	printTemperature(0, 0);
//	
//	lcd_local.setCursor(0, 1);
//	delay(print_delay);
//	
//	lcd_local.clear();
//	lcd_local.print("  Other info:");
//	
//	lcd_local.setCursor(0,1); // col, row
//	lcd_local.print("                ");
//	
//	lcd_local.setCursor(4,1);
//	lcd_local.print("UNDER");
//	delay(print_delay/2);
//	
//	lcd_local.setCursor(0,1);
//	lcd_local.print("                ");
//	delay(print_delay/2);
//	
//	lcd_local.setCursor(1,1);
//	lcd_local.print("CONSTRUCTION");
//	
//	delay(print_delay/2);
//}


