#ifndef dht_setup_h
#define dht_setup_h

//*********************************************************************************************************
//Hydro DHT
//*********************************************************************************************************
//HYDRO SENSOR
//
//    FILE: dht22_test.ino
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.03
// PURPOSE: DHT library test sketch for DHT22 && Arduino
//     URL:
// HISTORY:
// 0.1.03 extended stats for all errors
// 0.1.02 added counters for error-regression testing.
// 0.1.01
// 0.1.00 initial version
//
// Released to the public domain
//
//*********************************************************************************************************
// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#include "DHT.h"
//#include "Adafruit_Sensor.h"

#define DHTPIN 3     // what digital pin we're connected to
//#define DHT_powerPin 3 //Powerpin fÃ¼r den dht

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht(DHTPIN, DHTTYPE);
//*********************************************************************************************************


#endif
