#ifndef CLOCK_SETUP_H
#define CLOCK_SETUP_H
//*********************************************************************************************************
///CLOCK_MODULE
//*********************************************************************************************************
// DS1302_Serial_Easy (C)2010 Henning Karlsen
// web: http://www.henningkarlsen.com/electronics
//
// Adopted for DS1302RTC library by Timur Maksimov 2014
//
// A quick demo of how to use my DS1302-library to 
// quickly send time and date information over a serial link
//
// I assume you know how to connect the DS1302.
// DS1302:  CE pin   (RST)  -> Arduino Digital 8
//          I/O pin  (DAT)  -> Arduino Digital 9
//          SCLK pin (CLK)  -> Arduino Digital 10
//          GND pin         -> Arduino GND oder Digital 11
//          VCC pin         -> Arduino VCC oder Digital 12



#include <Time.h>
#include <TimeLib.h>
#include <DS1302RTC.h>

//*************************************
// Set pins:  CE(Reset), IO(DAT),CLK
DS1302RTC RTC(8, 9, 10); //new version

// Optional connection for RTC module
#define DS1302_GND_PIN 11 //zum deaktivieren einfach Pin 98 angeben
#define DS1302_VCC_PIN 12 //zum deaktivieren einfach Pin 99 angeben
//*************************************
//*********************************************************************************************************


//*********************************************************************************************************
//Clock Module Initialisierung
//*********************************************************************************************************
void clock_init()
{
  //Serial.println("DS1302RTC Read Test");
  //*****************
  // RTC Modul aktivieren
  //*****************
  digitalWrite(DS1302_GND_PIN, LOW);
  pinMode(DS1302_GND_PIN, OUTPUT);

  digitalWrite(DS1302_VCC_PIN, HIGH);
  pinMode(DS1302_VCC_PIN, OUTPUT);
  
  RTC.writeEN(1);
  
  //Serial.println("RTC module activated");
  //Serial.println();
  delay(500);
  
  if (RTC.haltRTC()) {
    Serial.println("The DS1302 is stopped.  Please run the SetTime");
    //Serial.println();
  }
  if (!RTC.writeEN()) {
    Serial.println("The DS1302 is write protected. This normal.");
    //Serial.println();
  }
}

//*********************************************************************************************************//*********************************************************************************************************
//CLOCK
void print2digits(int number) {
  if (number >= 0 && number < 10)
    Serial.write('0');
  Serial.print(number);
}

#endif
