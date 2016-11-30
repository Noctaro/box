//  __   __     ______     ______           __         ______     ______     __  __     __    
// /\ "-.\ \   /\  __ \   /\  ___\         /\ \       /\  ___\   /\  __ \   /\ \/\ \   /\ \   
// \ \ \-.  \  \ \ \/\ \  \ \ \____        \ \ \____  \ \  __\   \ \ \/\_\  \ \ \_\ \  \ \ \  
//  \ \_\\"\_\  \ \_____\  \ \_____\        \ \_____\  \ \_____\  \ \___\_\  \ \_____\  \ \_\ 
//   \/_/ \/_/   \/_____/   \/_____/    &    \/_____/   \/_____/   \/___/_/   \/_____/   \/_/ 
                                                                                           

NOCEDIT
//*********************************************************************************************************
//EEPROM
#include <EEPROM.h>
int eeprom_address_watered = 0;

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
// DS1302:  CE pin   (RST)  -> Arduino Digital 10
//          I/O pin  (DAT)  -> Arduino Digital 11
//          SCLK pin (CLK)  -> Arduino Digital 12
//          VCC pin         -> Arduino Digital 9
//          GND pin         -> Arduino GND


#include <Time.h>
#include <TimeLib.h>
#include <DS1302RTC.h>

// Set pins:  CE(Reset), IO(DAT),CLK
DS1302RTC RTC(10, 11, 12);
// Optional connection for RTC module
#define DS1302_VCC_PIN 9
#define DS1302_GND_PIN 31


//*********************************************************************************************************

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

#define DHTPIN 4     // what digital pin we're connected to
#define DHT_powerPin 10 //Powerpin für den dht

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

//*********************************************************************************************************
//PIN für den Wassersensor
//*********************************************************************************************************
#define Water_Sensor 1 //Definiere den Wassersensor Pin
//*********************************************************************************************************

//*********************************************************************************************************
//PIN für den Schalter der Modeauswahlfunktion
//*********************************************************************************************************
#define Modeschalter 2 //Definiere den Pin für den Schalter zwischen Mode 0 und 1
//*********************************************************************************************************


//*********************************************************************************************************
//PIN für die Statusled
//*********************************************************************************************************
#define LedPin1 13     //Namen für den Ledpin
//*********************************************************************************************************


//*********************************************************************************************************
//RELAIT PINS
//*********************************************************************************************************
#define relaitPin1 5 //Definiere den Namen und Pin für das 1. Relait
#define relaitPin2 6 //Definiere den Namen und Pin für das 2. Relait
//*********************************************************************************************************


//*********************************************************************************************************
//Globale Variablen (Bitte nicht ändern) -> Gewünschte Werte sind in mode_settings.ino anpassbar
//*********************************************************************************************************
byte zaehler = 0;
int feuchtewert = 0;
int maxTemperatur = 0;
int minTemperatur = 0;
int maxLuftfeuchte = 0;
int minLuftfeuchte = 0;
int optimaleLuftfeuchte = 0;
boolean relait1check = 0;
boolean relait2check = 0;
boolean errorcheck = 0;
int water_hour_01 = 99;
int water_hour_02 = 99;
int water_hour_03 = 99;
int water_hour_04 = 99;
int water_hour_05 = 99;
int water_hour_06 = 99;
int water_hour_07 = 99;
int water_hour_08 = 99;
int water_hour_09 = 99;
int water_hour_10 = 99;
int water_applied = 1;
long flush_time_secounds = 90;  //Dauer der Wasserzufuhr bei dem Bewässern
float h = 0;
float t = 0;
//float f = 0;
//float hif = 0;
//float hic = 0;
//*********************************************************************************************************
//*********************************************************************************************************


//*********************************************************************************************************
//Setup Loop wird einmal ausgeführt
//*********************************************************************************************************
void setup()
{
  
  Serial.begin(9600);
  
  //*********************************************************************************************************
  //DHT Initialisierung
  //*********************************************************************************************************
  Serial.println("Hydrobalancer ist online.");
  dht.begin();
  //************
  
  //PIN Modus festlegen  
  pinMode(relaitPin1, OUTPUT); //Setze den Steuerpin für Relait 1 als Ausgang
  pinMode(relaitPin2, OUTPUT); //Setze den Steuerpin für Relait 2 als Ausgang
  
  pinMode(Modeschalter, INPUT);  //Setze den Steuerpin für den gewünschten Modus als Eingang
  pinMode(DHT_powerPin, OUTPUT); //Setze den PowerPin für den DHT Sensor als Ausgang
  pinMode(LedPin1, OUTPUT); //Setze den Steuerpin für Led1 als Ausgang
  pinMode(Water_Sensor, INPUT);     //The Water Sensor is an Input
  //*****************
 
  digitalWrite(relaitPin1, LOW);         //Schalte relaitPin1 aus 
  digitalWrite(relaitPin2, LOW);         //Schalte relaitPin2 aus   
  digitalWrite(DHT_powerPin, HIGH);      //Schalte DHT Powerpin ein 
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
  
  Serial.println("RTC module activated");
  Serial.println();
  delay(500);
  
  if (RTC.haltRTC()) {
    Serial.println("The DS1302 is stopped.  Please run the SetTime");
    Serial.println();
  }
  if (!RTC.writeEN()) {
    Serial.println("The DS1302 is write protected. This normal.");
    Serial.println();
  }
  
  delay(5000);
//*********************************************************************************************************
    
}

//*********************************************************************************************************
//MAINLOOP
//*********************************************************************************************************
void loop()
{
  
  digitalWrite(LedPin1, LOW);
  //*********************************************************************************************************
  //CLOCK
  //*********************************************************************************************************
   tmElements_t tm;
  
  Serial.print("UNIX Time: ");
  Serial.print(RTC.get());

  if (! RTC.read(tm)) {
    Serial.print("  Time = ");
    print2digits(tm.Hour);
    Serial.write(':');
    print2digits(tm.Minute);
    Serial.write(':');
    print2digits(tm.Second);
    Serial.print(", Date (D/M/Y) = ");
    Serial.print(tm.Day);
    Serial.write('/');
    Serial.print(tm.Month);
    Serial.write('/');
    Serial.print(tmYearToCalendar(tm.Year));
    Serial.print(", DoW = ");
    Serial.print(tm.Wday);
    Serial.println();
  } else {
    Serial.println("DS1302 read error!  Please check the circuitry.");
    Serial.println();
    delay(9000);
  }
  
  //*********************************************************************************************************
  //*********************************************************************************************************
  
  
  //************
  //cyclezähler
  //************
  zaehler++;
  //*********************************************************************************************************

//*********************************************************************
//DHT
//*********************************************************************  
// Reading temperature or humidity takes about 250 milliseconds!
// Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
//*********************************************************************  
 DHT_check_input();
//********************************************************************* 

//*********************************************************************************************************  
//Wassersensor auslesen
//*********************************************************************************************************
 water_level();  
//*********************************************************************************************************

//*********************************************************************************************************  
//Modeschalter
//*********************************************************************************************************
//int Mode = 0;                               //Mode im Code manuell setzen, dann muss die nächste Zeile auskommentiert werden
  byte Mode = digitalRead(Modeschalter);       //Lese den Status des Modeschalters
  Serial.println("*********");
  Serial.print("Modus:"); 
  Serial.println(Mode,2); 
  Serial.println("*********");
//*********************************************************************************************************   

//*********************************************************************************************************
//Messzähler
//Gibt den aktuellen Messdurchgang an
//*********************************************************************************************************
  Serial.print("Messdurchgang ");
  Serial.print(zaehler);
  Serial.println(" von 15");
  Serial.println("*********");
//*********************************************************************************************************


//*********************************************************************************************************
//Relaitcheck 
//Gibt den aktuellen Status des Relaits aus
//*********************************************************************************************************
  Serial.print("*Relait 1 Power: ");
  Serial.print(relait1check);
  Serial.print("* *Relait 2 Power: ");
  Serial.print(relait2check);
  Serial.println("*");  
//*********************************************************************************************************
//*********************************************************************************************************

//*********************************************************************************************************
//Lesen der Modekonfiguration
//*********************************************************************************************************
if(Mode == 0)
  {
  Mode0_settings_active();
  } 

//*********************************************************************************************************
  
if(Mode == 1)
  {
  Mode1_settings_active();
  }     
//*********************************************************************************************************
//*********************************************************************************************************

//*********************************************************************************************************
//Bewässerung
//*********************************************************************************************************
//Der Schaltvorgang für die Bewässerung falls eine für die Bewässerung gewählte Stunde eintritt.
//*********************************************************************************************************
   //water_applied = EEPROM.read(eeprom_address_watered); 
   
    //Überprüfe ob die Bewässerung zur aktuellen Stunde ausgeführt wurde
    if ( tm.Minute == 59 && water_applied == 1 )
      {
      watercontrol_reset();
      }
   
   if (tm.Hour == water_hour_01 && water_applied == 0 || tm.Hour == water_hour_02 && water_applied == 0 || tm.Hour == water_hour_03 && water_applied == 0 || tm.Hour == water_hour_04 && water_applied == 0 || tm.Hour == water_hour_05 && water_applied == 0 || tm.Hour == water_hour_06 && water_applied == 0 || tm.Hour == water_hour_07 && water_applied == 0 || tm.Hour == water_hour_08 && water_applied == 0 || tm.Hour == water_hour_09 && water_applied == 0 || tm.Hour == water_hour_10 && water_applied == 0 )
    {
    watercontrol_active();
    }
//*********************************************************************************************************


//*********************************************************************************************************
//Schaltvorgang optimieren Feuchte
//*********************************************************************************************************
huimdity_check_optimizer();
//*************************************************  



//*********************************************************************************************************
//Schaltvorgang und Feedback für Luftfeuchteregler
//*********************************************************************************************************
humidity_balancer();
//***************************************************  


//*********************************************************************************************************
}

//CLOCK
void print2digits(int number) {
  if (number >= 0 && number < 10)
    Serial.write('0');
  Serial.print(number);
}

//
// END OF FILE
//


