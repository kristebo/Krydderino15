

#include "Arduino.h"
#include "LocalLibrary.h"

#include "MagicNumbers.h"	// Constants and magic numbers
#include "Sensirion.h"		// Air Temperature & Relative Humidity sensor
#include "WaterLevel.h"		// E-tape Water Level sensor
#include "LCD.h"			// LCD display
#include "Temperature.h"	// Waterproof water temperature thermistor
#include "Status.h"
#include "Relay_12V.h"
#include "EC.h"				// Atlas Scientific EC-sensor class
#include "PH.h"				// Atlas Scientific pH-sensor class


// Instantiate sensor and actuator classes

Status status = Status();
Sensirion airtemp = Sensirion();
WaterLevel waterlevel = WaterLevel();
LCD lcd = LCD( &status );
Temperature temp = Temperature();
Relay_12V mister_fan = Relay_12V( MISTER_FAN_PIN );
Relay_12V plant_fan = Relay_12V( PLANT_FAN_PIN );
Relay_12V mister = Relay_12V( MISTER_PIN );
Relay_12V nute_solenoid = Relay_12V( PPM_PIN );
Relay_12V phup_solenoid = Relay_12V( PHPLUS_PIN );
Relay_12V phdown_solenoid = Relay_12V( PHMINUS_PIN );
EC ec = EC();
PH ph = PH();

int str_counter_1;
int str_counter_3;

int cycle_counter;

//******************************************************************************
//************************************ SETUP ***********************************
//******************************************************************************
void setup()
{
    //	Serial.begin(9600);
	lcd.init();
	//				1234567890123456
	lcd.clear();
	lcd.display(0, "Calibrating\0  ");
	lcd.display(1, "sensors...\0   ");
//	waterlevel.init();
	lcd.clear();
	lcd.display(0, "Sensors okay.\0");
	ec.initialize_ec_sensor();
	ph.initialize_ph_sensor();
	cycle_counter = 0;
	
    //	Serial.begin(38400); // hardware serial port
	
    Serial.begin(9600); // Open serial connection to report values to host
}

//******************************************************************************
//************************************ LOOP ************************************
//******************************************************************************
void loop() {
	cycle_counter++;
    
    // **** Fetch & Display temp/RH sensor ****
    
    for (int x=0; x < 2; x++)
    {
        status.plant_temperature = airtemp.read_temperature();
        status.plant_humidity = airtemp.read_humidity();
        delay(2000);
        lcd.print_plant_temp_and_rh();
    }

    
    // **** Fetch & Display water level sensor ****
	
//	status.water_level_instant = waterlevel.read_sensor();
//    //	status.water_level_instant =
//	waterlevel.get_averaged_water_level();
//	status.water_level_in_inches = waterlevel.water_level_in_inches();
//	status.water_level = waterlevel.humanized_level();

    // hack while waiting for new water level sensor:
    status.water_level = WL_NORMAL;

//	status.water_temperature = temp.temperature_in_celcius();
//	lcd.print_water_level();
//	delay(1000);
//	lcd.print_water_level_instant();
//	delay(2500);
    
    
    // **** Dumping Cycle Counter on LCD ****
	
	lcd.display_number(cycle_counter, 0);
	
    // **** Run 24V mister fan relay for some time every n cycles ****
	if ((cycle_counter % (3)) == 0)
	{
        plant_fan.off();
		cycle_counter = 0;	// reset the cycle counter
		lcd.clear(); //1234567890123456
		lcd.display(0,"   \0");
		lcd.display(1,"AeroMister    ON  \0");
		mister.on();
        delay(5 * 1000);
		lcd.clear(); //1234567890123456
		lcd.display(0,"Aeroponic fan ON  \0");
		lcd.display(1,"AeroMister    ON  \0");
		mister_fan.on();
        for (int k=0; k < 5; k++) {
            lcd.display(0,"Aeroponic fanOFF\0");
            mister_fan.off();
            delay(8000);
            lcd.display(0,"Aeroponic fan ON  \0");
            mister_fan.on();
            delay(3000);
        }
		lcd.clear(); //1234567890123456
		lcd.display(0,"Aeroponic fa.OFF\0");
        delay(300);
		mister_fan.off();
        delay(1000);
		lcd.display(1,"AeroMister   OFF\0");
        mister.off();
	} else mister.off();
    	
    // **** Run Top Fan If Too Hot ****
	
	if (status.plant_temperature >= 26)
	{
		lcd.clear(); //1234567890123456
		lcd.display(0,"Too hot! >26C\0");
		lcd.display(1,"Starting fan!\0");
		plant_fan.on();
	}
	
    // **** Run Top Fan If Too Humid ****
	
	if (status.plant_humidity >= 65)
	{
		lcd.clear(); //1234567890123456
		lcd.display(0,"Too humid!\0");
		lcd.display(1,"Starting fan!\0");
		plant_fan.on();
	}
    
    // **** Stop Top Fan If Nice ****
    
	if ((status.plant_temperature < 26) && (status.plant_humidity < 65))
	{
		lcd.clear(); //1234567890123456
		lcd.display(0,"Perfect now.\0");
		lcd.display(1,"Stopping fans.\0");
		plant_fan.off();
	}
	delay(2000);
	
    // **** Process pH sensor ****
	
    lcd.clear(); //1234567890123456
    lcd.display(0,"Reading pH\0");
    lcd.display(1,"level in water..\0");
	ph.averaged_reading();
	status.water_ph = ph.last_average;

    // **** Process EC sensor ****

    lcd.clear(); //1234567890123456
    lcd.display(0,"Reading nutrient\0");
    lcd.display(1,"level in water..\0");
	ec.averaged_reading();
	status.water_ec = ec.last_average;
    
	lcd.print_ec_and_ppm();
    
    delay(2000);
	
    // **** Based on EC & pH, release fluids ****
	
    // **** Test solenoids ****
	
//    nute_solenoid.on(400);
//    delay(1000);
//    phup_solenoid.on(400);
//    delay(1000);
//    phdown_solenoid.on(400);
//    delay(1000);
    
}