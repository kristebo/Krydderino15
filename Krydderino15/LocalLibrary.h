///
/// @file	LocalLibrary.h 
/// @brief	Library header
///
/// @details	<#details#>
/// @n	
/// @n @b	Project Krydderino15
/// @n @a	Developed with [embedXcode](http://embedXcode.weebly.com)
/// 
/// @author	Haakon Storm Heen
/// @author	Haakon Storm Inc
/// @date	21.05.13 17:06
/// @version	<#version#>
/// 
/// @copyright	© Haakon Storm Heen, 2013
/// @copyright	CC = BY NC SA
///
/// @see	ReadMe.txt for references
///


// Core library - IDE-based
#if defined(MPIDE) // chipKIT specific
#include "Arduino.h"
#elif defined(DIGISPARK) // Digispark specific
#include "Arduino.h"
#elif defined(ENERGIA) // LaunchPad, FraunchPad and StellarPad specific
#include "Energia.h"
#elif defined(MAPLE_IDE) // Maple specific
#include "Arduino.h"
#elif defined(CORE_TEENSY) // Teensy specific
#include "Arduino.h"
#elif defined(WIRING) // Wiring specific
#include "Wiring.h"
#elif defined(ARDUINO) && (ARDUINO >= 100) // Arduino 1.0x and 1.5x specific
#include "Arduino.h"
#elif defined(ARDUINO) && (ARDUINO < 100)  // Arduino 23 specific
#include "Arduino.h"
#endif // end IDE

#ifndef Krydderino15_LocalLibrary_h
#define Krydderino15_LocalLibrary_h

///
/// @brief	Blink a LED
/// @details	LED attached to pin is light on then light off
/// @n		Total cycle duration = ms
/// @param	pin pin to which the LED is attached
/// @param	times number of times
/// @param	ms cycle duration in ms
///
void blink(uint8_t pin, uint8_t times, uint16_t ms);

#endif
