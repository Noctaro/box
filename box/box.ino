//  __   __     ______     ______           __         ______     ______     __  __     __    
// /\ "-.\ \   /\  __ \   /\  ___\         /\ \       /\  ___\   /\  __ \   /\ \/\ \   /\ \   
// \ \ \-.  \  \ \ \/\ \  \ \ \____        \ \ \____  \ \  __\   \ \ \/\_\  \ \ \_\ \  \ \ \  
//  \ \_\\"\_\  \ \_____\  \ \_____\        \ \_____\  \ \_____\  \ \___\_\  \ \_____\  \ \_\ 
//   \/_/ \/_/   \/_____/   \/_____/    &    \/_____/   \/_____/   \/___/_/   \/_____/   \/_/ 
                                                                                       
//
//*********************************************************************************************************

//Globale Variablen
#include "global_var.h"

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

/*
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
#include "Adafruit_Sensor.h"





#define DHTPIN 3     // what digital pin we're connected to
//#define DHT_powerPin 3 //Powerpin für den dht

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

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

//*********************************************************************************************************
*/


//*********************************************************************************************************
//SHT 31 init (alle DHT Zeilen auskommentieren)
//*********************************************************************************************************
#include <Wire.h>
#include <ClosedCube_SHT31D.h>

ClosedCube_SHT31D sht31d;
//*********************************************************************************************************


//*********************************************************************************************************
//PIN für den Wassersensor
//*********************************************************************************************************
//Benötigt Remapping - Pin 1 == Serial TX
#define Water_Sensor A2 //Definiere den Wassersensor Pin
//*********************************************************************************************************

//*********************************************************************************************************
//PIN für den Schalter der Modeauswahlfunktion
//*********************************************************************************************************
//Benötigt Remapping - Pin 2 == Serial TX
#define Modeschalter A1 //Definiere den Pin für den Schalter zwischen Mode 0, 1 ,2 und 3
//*********************************************************************************************************


//*********************************************************************************************************
//PIN für die Statusled
//*********************************************************************************************************
#define LedPin1 13     //Namen für den Ledpin
//*********************************************************************************************************


//RELAIS
//*********************************
#include "relais.h"
//*********************************

//alternate Testing

//*********************************************************************************************************


//*********************************************************************************************************
//EEPROM
//*********************************************************************************************************
#include <EEPROM.h>
int eeprom_address_watered = 0;
//*********************************************************************************************************




//*********************************************************************************************************
//*********************************************************************************************************


//*********************************************************************************************************
//Setup Loop wird einmal ausgeführt
//*********************************************************************************************************
void setup()
{
  
  Serial.begin(9600);

  /*
  //*********************************************************************************************************
  //DHT Initialisierung
  //*********************************************************************************************************
  Serial.println(F("Hydrobalancer ist online."));
  dht.begin();
  //pinMode(DHT_powerPin, OUTPUT); //Setze den PowerPin für den DHT Sensor als Ausgang
  //************
  */

  //*********************************************************************************************************
  //SHT 3x Initialisierung
  //*********************************************************************************************************
  sht31d.begin(0x44);
	Serial.print("SHT31D Serial #");
  Serial.println(sht31d.readSerialNumber());
  //************

  //*********************************************************************************************************
  //relais Initialisierung
  //*********************************************************************************************************  
  relaisinit();
  
  //Restliche Pin initialisierung
  pinMode(Modeschalter, INPUT);  //Setze den Steuerpin für den gewünschten Modus als Eingang
  pinMode(LedPin1, OUTPUT); //Setze den Steuerpin für Led1 als Ausgang
  //pinMode(Water_Sensor, INPUT);     //The Water Sensor is an Input
  //*****************
 
 
  
// digitalWrite(DHT_powerPin, HIGH);      //Schalte DHT Powerpin ein 
  digitalWrite(LedPin1, LOW);            //Schalte LedPin 1 aus

  //*********************************************************************************************************
  //Clock Module Initialisierung
  //*********************************************************************************************************  
  Serial.println("DS1302RTC Read Test");
  //*****************
  // RTC Modul aktivieren
  //*****************
  digitalWrite(DS1302_GND_PIN, LOW);
  pinMode(DS1302_GND_PIN, OUTPUT);

  digitalWrite(DS1302_VCC_PIN, HIGH);
  pinMode(DS1302_VCC_PIN, OUTPUT);
  
  RTC.writeEN(1);
  
  Serial.println(F("RTC module activated"));
  Serial.println();
  delay(500);
  
  if (RTC.haltRTC()) {
    Serial.println(F("The DS1302 is stopped. SetTime"));
    Serial.println();
  }
  if (!RTC.writeEN()) {
    Serial.println(F("The DS1302 is write protected. This normal."));
    Serial.println();
  }
  
  delay(5000);

  water_applied = EEPROM.read(eeprom_address_watered);
  Serial.print(F("Bewaesserungsstatus = "));
  Serial.println(water_applied);
//*********************************************************************************************************

//*********************************************************************************************************
//Boxfunktionen aktivieren oder deaktivieren - anpassbar in mode_settings
//*********************************************************************************************************
Box_functions();    
//*********************************************************************************************************

}
//*********************************************************************************************************
//*********************************************************************************************************


//*********************************************************************************************************
//MAINLOOP
//*********************************************************************************************************
void loop()
{
//************
//Cyclezähler
//************
zaehler++;
//************
//Einmal kurz blinken um den Start eines neuen Zyklus darzustellen 
//************ 
led_cycle_check();
//*********************************************************************************************************
//*********************************************************************************************************


//*********************************************************************************************************
//CLOCK
//*********************************************************************************************************
  tmElements_t tm;
  
//Serial.print("UNIX Time: ");
//Serial.print(RTC.get());
  RTC.get();
  Zeitausgabe();
  unix_secounds = (RTC.get());
  Serial.print("Unix Zeit: ");
  Serial.println(unix_secounds);
//*********************************************************************************************************
//*********************************************************************************************************
  
  


  
  //*********************************************************************************************************

/*
//*********************************************************************
//DHT
//*********************************************************************  
// Reading temperature or humidity takes about 250 milliseconds!
// Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
//*********************************************************************  
  h = dht.readHumidity();//+dht_adjust;
  // Read temperature as Celsius (the default)
  t = dht.readTemperature();
  
  h = h+dht_adjustment_h;
  // Read temperature as Fahrenheit (isFahrenheit = true)
  //f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) 
  {
  Serial.println("Failed to read from DHT sensor!");
  //  return;
  }

  // Compute heat index in Fahrenheit (the default)
  hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  hic = dht.computeHeatIndex(t, h, false);
 
//********************************************************************* 
*/

//********************************************************************* 
//SHT READ
//********************************************************************* 
  printResult("Pooling Mode", sht31d.readTempAndHumidity(REPEATABILITY_HIGH, MODE_POLLING, 50));
  delay(250);


//********************************************************************* 

//*********************************************************************************************************  
//Modeschalter
//*********************************************************************************************************
  Modeswitch();           //Legt den ausgewählten Mode fest
  
  
//*********************************************************************************************************
//Lesen der Modekonfiguration und Aktivieren der gewünschten Einstellungen
//*********************************************************************************************************
  if(Mode == 0) //Grow
  {
  Mode0_settings_active();
  } 

//*********************************************************************************************************
  
  if(Mode == 1) //Bloom
  {
  Mode1_settings_active();
  }     

//*********************************************************************************************************
  
  if(Mode == 2) //FLUSH
  {
  Mode2_settings_active();
  flushcontrol_active();
  }   

  if(Mode == 3) //Relait testmode (endlos loop)
  {
    int s=0;
    while(s==0)
    {
    Mode3_settings_active();
    }
  }  
//*********************************************************************************************************

//*********************************************************************************************************  
//Luftzirkulation regulieren
//*********************************************************************************************************
  if(Abluft_regulieren == 1)
  {
  aircontrol();
  
  
  air_refresh(); //TESTING
  }
 
//*********************************************************************************************************
//Temperatur regulieren und ausgeben
//*********************************************************************************************************
  if(Temperatur_regulieren == 1)
  {
  heat_control();
  }


//*********************************************************************************************************
//Luftfeuchte regulieren und ausgeben
//*********************************************************************************************************
  if(Luftfeuchte_regulieren == 1)
  {
  humidity_balancer(); //Schaltvorgang und Feedback
  }

//*********************************************************************************************************
//Bewässerung
//*********************************************************************************************************
//Der Schaltvorgang für die Bewässerung falls eine für die Bewässerung gewählte Stunde eintritt.
//*********************************************************************************************************
if(Bewaesserung_regulieren == 1)
{

/*
switch(hour_global)
  case water_hour_01:
    if(water_applied == 0)
    {
    
    }
break;  
 */
  
if(Mode == 1 || Mode == 0)
    {
    water_applied = EEPROM.read(eeprom_address_watered);
    bewaesserung_status_ausgabe();
    water_cycles_done = 0;

//---> switch

      if (hour_global == water_hour_01 && water_applied == 0)
      {
      Stars();     
      while (water_cycles_done < water_hour_cycles_01)
       {
        water_cycles_done++;
        water_cycles_ausgabe();
        Serial.println(water_hour_cycles_01);

        watercontrol_active(); //Auskommentieren falls keine Bewässerung notwendig
        delay(3000); //Schaltpause  
       }
      water_applied = 1;
      EEPROM.write(eeprom_address_watered, water_applied); 
      watercontrol_active_ausgabe2();
      Stars();
      }
      //****
      
      if (hour_global == water_hour_02 && water_applied == 0)
          {
      Stars();     
      while (water_cycles_done < water_hour_cycles_02)
       {
        water_cycles_done++;
        water_cycles_ausgabe();
        Serial.println(water_hour_cycles_02);

        watercontrol_active(); //Auskommentieren falls keine Bewässerung notwendig
        delay(3000); //Schaltpause  
       }
      water_applied = 1;
      EEPROM.write(eeprom_address_watered, water_applied); 
      watercontrol_active_ausgabe2();
      Stars();
      }
      //****
      
      if (hour_global == water_hour_03 && water_applied == 0)
      {
      Stars();     
      while (water_cycles_done < water_hour_cycles_03)
       {
        water_cycles_done++;
        water_cycles_ausgabe();
        Serial.println(water_hour_cycles_03);

        watercontrol_active(); //Auskommentieren falls keine Bewässerung notwendig
        delay(3000); //Schaltpause  
       }
      water_applied = 1;
      EEPROM.write(eeprom_address_watered, water_applied); 
      watercontrol_active_ausgabe2();
      Stars();
      }
      //****
      
      if (hour_global == water_hour_04 && water_applied == 0)
      {
      Stars();     
      while (water_cycles_done < water_hour_cycles_04)
       {
        water_cycles_done++;
        water_cycles_ausgabe();
        Serial.println(water_hour_cycles_04);

        watercontrol_active(); //Auskommentieren falls keine Bewässerung notwendig
        delay(3000); //Schaltpause  
       }
      water_applied = 1;
      EEPROM.write(eeprom_address_watered, water_applied); 
      watercontrol_active_ausgabe2();
      Stars();
      }
      //****
      
      if (hour_global == water_hour_05 && water_applied == 0) 
      {
      Stars();     
      while (water_cycles_done < water_hour_cycles_05)
       {
        water_cycles_done++;
        water_cycles_ausgabe();
        Serial.println(water_hour_cycles_05);

        watercontrol_active(); //Auskommentieren falls keine Bewässerung notwendig
        delay(3000); //Schaltpause  
       }
      water_applied = 1;
      EEPROM.write(eeprom_address_watered, water_applied); 
      watercontrol_active_ausgabe2();
      Stars();
      }
      //****
      
      if (hour_global == water_hour_06 && water_applied == 0 )
      {
      Stars();     
      while (water_cycles_done < water_hour_cycles_06)
       {
        water_cycles_done++;
        water_cycles_ausgabe();
        Serial.println(water_hour_cycles_06);

        watercontrol_active(); //Auskommentieren falls keine Bewässerung notwendig
        delay(3000); //Schaltpause  
       }
      water_applied = 1;
      EEPROM.write(eeprom_address_watered, water_applied); 
      watercontrol_active_ausgabe2();
      Stars();
      }
      //****
      
      if (hour_global == water_hour_07 && water_applied == 0 )
                {
      Stars();     
      while (water_cycles_done < water_hour_cycles_07)
       {
        water_cycles_done++;
        water_cycles_ausgabe();
        Serial.println(water_hour_cycles_07);

        watercontrol_active(); //Auskommentieren falls keine Bewässerung notwendig
        delay(3000); //Schaltpause  
       }
      water_applied = 1;
      EEPROM.write(eeprom_address_watered, water_applied); 
      watercontrol_active_ausgabe2();
      Stars();
      }
      //****
      
      if (hour_global == water_hour_08 && water_applied == 0 ) 
      {
      Stars();     
      while (water_cycles_done < water_hour_cycles_08)
       {
        water_cycles_done++;
        water_cycles_ausgabe();
        Serial.println(water_hour_cycles_08);

        watercontrol_active(); //Auskommentieren falls keine Bewässerung notwendig
        delay(3000); //Schaltpause  
       }
      water_applied = 1;
      EEPROM.write(eeprom_address_watered, water_applied); 
      watercontrol_active_ausgabe2();
      Stars();
      }
      //****
      
      if (hour_global == water_hour_09 && water_applied == 0 )
                {
      Stars();     
      while (water_cycles_done < water_hour_cycles_09)
       {
        water_cycles_done++;
        water_cycles_ausgabe();
        Serial.println(water_hour_cycles_09);

        watercontrol_active(); //Auskommentieren falls keine Bewässerung notwendig
        delay(3000); //Schaltpause  
       }
      water_applied = 1;
      EEPROM.write(eeprom_address_watered, water_applied); 
      watercontrol_active_ausgabe2();
      Stars();
      }
      //****
      
      if (hour_global == water_hour_10 && water_applied == 0 )
      {
      Stars();     
      while (water_cycles_done < water_hour_cycles_10)
       {
        water_cycles_done++;
        water_cycles_ausgabe();
        Serial.println(water_hour_cycles_10);

        watercontrol_active(); //Auskommentieren falls keine Bewässerung notwendig
        delay(3000); //Schaltpause  
       }
      water_applied = 1;
      EEPROM.write(eeprom_address_watered, water_applied); 
      watercontrol_active_ausgabe2();
      Stars();
      }
      //****
      //****
      
  
      //Überprüfe ob die Bewässerung zur aktuellen Stunde ausgeführt wurde
      if ( minute_global == 59 && second_global >= 40 && water_applied == 1 )
      {
      //Stars();
        
      watercontrol_reset(); //Auskommentieren falls keine Bewässerung notwendig
      
      //Stars();   
      }
   

    }
  }

//*********************************************************************************************************
//*********************************************************************************************************

//*********************************************************************************************************  
//Ausgabe am Serial Monitor (Serial print)
//*********************************************************************************************************

//*********************************************************************************************************
//Mode Auswahl ausgeben
//*********************************************************************************************************
  Modeswitch_ausgabe();   //Gibt den aktuellen Status am Serial Monitor aus
//*********************************************************************************************************  

//*********************************************************************************************************
//Messzähler
//Gibt den aktuellen Messdurchgang am Serial Monitor aus
//*********************************************************************************************************
  Messzaehler_ausgabe();
//*********************************************************************************************************

//*********************************************************************************************************
//Gibt den aktuelle Temperatur und Luftfeuchte am Serial Monitor aus
//*********************************************************************************************************
  Temperatur_Luftfeuchte_ausgabe();

//*********************************************************************************************************
//Relaitcheck 
//Gibt den aktuellen Status der Relaits am Serial Monitor aus
//*********************************************************************************************************
  Relaitcheck_ausgabe();
//*********************************************************************************************************

//*********************************************************************************************************
//Schaltwerte für Lufteuchte, Temperatur, Abluft ausgeben
//*********************************************************************************************************
Schaltwerte_ausgabe();
//*********************************************************************************************************

//*********************************************************************************************************
//Ausgabe des Luftfeuchte Status an die LED und den Serial Monitior
//*********************************************************************************************************
LuftfeuchteStatus_ausgabe(); 

//*********************************************************************************************************
//Ausgabe des Temperatur Status an die LED und den Serial Monitior
//*********************************************************************************************************
TemperaturStatus_ausgabe();
//*********************************************************************************************************
//*********************************************************************************************************



//*********************************************************************************************************  
//Wassersensor auslesen und Wasserstand ausgeben
//*********************************************************************************************************
if (Wasserstand_anzeigen == 1)
{
water_level();  
}
//*********************************************************************************************************




//*********************************************************************************************************  
//CSV Ausgabe am Serial Monitor (Serial print)
//*********************************************************************************************************
  
  //CSVausgabe();  
 
  



//*********************************************************************************************************
//Zähler Reset
//*********************************************************************************************************
  if(zaehler >= Messdurchgaenge)
  {
  zaehler = 0;
  }

//*********************************************************************************************************
//Verzögerung bis zur nächsten Messung
//*********************************************************************************************************  
  int delayer = 0;
  while(delayer <= 10)
    {
    delayer++;  
    delay(Messpause*100);
     if(excel_output == 0)
      {
      Serial.print("*");
      }
      Serial.println("^^");
    }

Serial.flush();


//*********************************************************************************************************
//Lese vom serial port//

//if(Serial.available() > 0)
  //  {
    //    inData = Serial.readStringUntil('\n');
      // Serial.println("*data: "+inData);
       //delay(2000);
       //inData="";
     //}
//************************************     
} //close Mainloop

//*********************************************************************************************************//*********************************************************************************************************
//*********************************************************************************************************//*********************************************************************************************************
//CLOCK
void print2digits(int number) {
  if (number >= 0 && number < 10)
    Serial.write('0');
  Serial.print(number);
}

//
// END OF FILE
//

//vorgefertigte Textsegmente
void Stars()
{
  Serial.println(F("*********"));
}

//SHT LIBRARY WERTE AUSLESEN
void printResult(String text, SHT31D result) {
  if (result.error == NO_ERROR) {
    t = result.t;
    delay(200);
    h = result.rh;
    delay(200);
  }
  else {
    Serial.print(text);
    Serial.print(": [ERROR] Code #");
    Serial.println(result.error);
  }
}
