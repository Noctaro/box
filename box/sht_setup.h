#ifndef sht_setup_h
#define sht_setup_h

#include <Wire.h>
#include "Adafruit_SHT31.h"
Adafruit_SHT31 sht31 = Adafruit_SHT31();

//*******************
//SHT initialisieren
//*******************
void sht_init()
{
      while (!Serial)
    delay(10);     // will pause Zero, Leonardo, etc until serial console opens
    //Serial.println("SHT31 test");
    if (! sht31.begin(0x44)) 
    { // Set to 0x45 for alternate i2c addr
    //Serial.println("Couldn't find SHT31");
    while (1) delay(1);
    }
}
#endif
