
//*********************************************************************************************************


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
// DS1302:  CE pin    -> Arduino Digital 27
//          I/O pin   -> Arduino Digital 29
//          SCLK pin  -> Arduino Digital 31
//          VCC pin   -> Arduino Digital 33
//          GND pin   -> Arduino Digital 35


#include <Time.h>
#include <TimeLib.h>
#include <DS1302RTC.h>

// Set pins:  CE(Reset), IO(DAT),CLK
DS1302RTC RTC(10, 11, 12);
// Optional connection for RTC module
#define DS1302_GND_PIN 31
#define DS1302_VCC_PIN 9

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
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
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

//*****************
#define Modeschalter 2 //Definiere den Pin für den Schalter zwischen Mode 0 und 1
#define LedPin1 13     //Namen für den Ledpin
//*********************************************************************************************************

//RELAITS
//*********************************************************************************************************
#define relaitPin1 5 //Definiere den Namen und Pin für das 1. Relait
#define relaitPin2 6 //Definiere den Namen und Pin für das 2. Relait
//*********************************************************************************************************

//******************
//*********************************************************************************************************
//Globale Variablen (Bitte nicht ändern)
//*********************************************************************************************************
int zaehler = 0;
int feuchtewert = 0;
int maxTemperatur = 0;
int minTemperatur = 0;
int maxLuftfeuchte = 0;
int minLuftfeuchte = 0;
int optimaleLuftfeuchte = 0;
int relait1check = 0;
int errorcheck = 0;


//*********************************************************************************************************
//*********************************************************************************************************

void setup()
{
    Serial.begin(9600);
  
  //DHT
  //************ 
  Serial.println("Hydrobalancer ist online.");
  dht.begin();
  //************
  
  //PIN Modus festlegen  
  pinMode(relaitPin1, OUTPUT); //Setze den Steuerpin für Relait 1 als Ausgang
  pinMode(relaitPin2, OUTPUT); //Setze den Steuerpin für Relait 2 als Ausgang
  
  pinMode(Modeschalter, INPUT);  //Setze den Steuerpin für den gewünschten Modus als Eingang
  pinMode(DHT_powerPin, OUTPUT); //Setze den PowerPin für den DHT Sensor als Ausgang
  pinMode(LedPin1, OUTPUT); //Setze den Steuerpin für Led1 als Ausgang
  //*****************
 
  digitalWrite(relaitPin1, LOW);         //Schalte relaitPin1 aus 
  digitalWrite(relaitPin2, LOW);         //Schalte relaitPin2 aus   
  digitalWrite(DHT_powerPin, HIGH);      //Schalte DHT Powerpin ein 
  digitalWrite(LedPin1, LOW);            //Schalte LedPin 1 aus

//*********************************************************************************************************
//Clock Module initialisierung
//*********************************************************************************************************  
  Serial.println("DS1302RTC Read Test");
  Serial.println("-------------------");
  
  // Activate RTC module
  digitalWrite(DS1302_GND_PIN, LOW);
  pinMode(DS1302_GND_PIN, OUTPUT);

  digitalWrite(DS1302_VCC_PIN, HIGH);
  pinMode(DS1302_VCC_PIN, OUTPUT);
  
  Serial.println("RTC module activated");
  Serial.println();
  delay(500);
  
  if (RTC.haltRTC()) {
    Serial.println("The DS1302 is stopped.  Please run the SetTime");
    Serial.println("example to initialize the time and begin running.");
    Serial.println();
  }
  if (!RTC.writeEN()) {
    Serial.println("The DS1302 is write protected. This normal.");
    Serial.println();
  }
  
  delay(5000);
//*********************************************************************************************************

//UHRZEITEN für Bewässerung hier eintragen!
//*********************************************************************************************************
int water_hour_01 = 20;
int water_hour_02 = 22;
int water_hour_03 = 1;
int water_hour_04 = 4;
int water_hour_05 = 7;
int water_hour_06 = 0;
int water_hour_07 = 0;
int water_hour_08 = 0;
int water_hour_09 = 0;
int water_hour_10 = 0;
//*********************************************************************************************************
//Zeit für eine Spülung in Sekunden
int flush_time_secounds = 90    
    
}

void loop()
{

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
  zaehler++;
  //*********************************************************************************************************

  //*********************************************************************
  //DHT
  //*********************************************************************  
    // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  //Serial.print(f);
  //Serial.print(" *F\t");
  Serial.print("Gefuehlte Temperatur: ");
  Serial.print(hic);
  Serial.println(" *C");
  //Serial.print(hif);
  //Serial.println(" *F");

    delay(2000);
//********************************************

//*********************************************************************************************************  
//Modeschalter
//*********************************************************************************************************
//int Mode = 0;  
  int Mode = digitalRead(Modeschalter);       //Lese den Status des Modeschalters
  Serial.println("*********");
  Serial.print("Modus:"); 
  Serial.println(Mode,2); 
  Serial.println("*********");

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

//*********************************************************************************************************
//Relaitcheck 
//Gibt den aktuellen Status des Relaits aus
//*********************************************************************************************************
  Serial.print("Relait 1 Power: ");
  Serial.print(relait1check);
  Serial.println("*********");
//*********************************************************************************************************
//*********************************************************************************************************


  //**************************************************
  //Hier die Werte für !Mode 0! nach belieben eintragen
  //Festlegen der gewünschten Temperaturen
  //**************************************************
if(Mode == 0){
  maxTemperatur = 29;
  minTemperatur = 17;
  maxLuftfeuchte = 70;
  minLuftfeuchte = 50;
  optimaleLuftfeuchte = 65;
} 
  //*************************************************
  //*************************************************
  
  //**************************************************
  //Hier die Werte für !Mode 1! nach belieben eintragen
  //Festlegen der gewünschten Temperaturen
  //**************************************************    
if(Mode == 1){
  maxTemperatur = 29;
  minTemperatur = 17;
  maxLuftfeuchte = 70;
  minLuftfeuchte = 60;
  optimaleLuftfeuchte = 68;
  }     
  //*************************************************
  //*************************************************  
//*********************************************************************************************************
//*********************************************************************************************************

//*********************************************************************************************************
//Schaltvorgang Optimierung
//*********************************************************************************************************
if (h > optimaleLuftfeuchte)
{
feuchtewert++;
Serial.println("*********");
Serial.print("Der aktuelle Feuchtewert ");
Serial.println(feuchtewert);
Serial.println("Schaltvorgang bei +-15");
Serial.println("*********");
Serial.println("Letzte Messung war hoeher als der Optimalwert");
Serial.println("****************************************");
}

if (h < optimaleLuftfeuchte)
{
feuchtewert--;
Serial.println("*********");
Serial.print("Der aktuelle Feuchtewert ");
Serial.println(feuchtewert);
Serial.println("(Schaltvorgang bei +-15)");
Serial.println("*********");
Serial.println("Letzte Messung war niedriger als der Optimalwert");
Serial.println("****************************************");
}
//*************************************************  
Serial.println("****************************************");




//*********************************************************************************************************
//Schaltvorgang und Feedback
//*********************************************************************************************************
if (zaehler==15)                                  //Wenn der Messzähler 15 Messdurchgänge erreicht hat                                  
{
  zaehler = 0;
//***************************************************
//***************************************************
  if (t <= minTemperatur || t >= maxTemperatur || h <= minLuftfeuchte || h >= maxLuftfeuchte) //Wenn die Temperatur kleiner als minTemperatur oder höher als maxTemperatur oder Luftfeuchte unter minLuftfeuchte oder über maxLuftfeuchte
  {
    digitalWrite(LedPin1, HIGH);            //Schalte LedPin 1 ein
    Serial.println("Achtung Temperatur oder Feuchte sind problematisch!!");
    delay(3000);                            //Verzögerung 1000cycles - ca. 0,5 Sekunden
  }
  
 else //ansonsten
  {
    digitalWrite(LedPin1, LOW);              //Schalte LedPin 1 aus
    Serial.println("Temperatur und Feuchte sind schwer in Ordnung :)");
    delay(3000);                             //Verzögerung 1000cycles - ca. 0,5 Sekunden
  }
  
  
//Der Schaltvorgang für den Befeuchter
  if (h < optimaleLuftfeuchte && feuchtewert < -14)    //Wenn die aktuelle Feuchte niedriger als die Optimale Luftfeuchte ist und feuchtewert dies 15 mal bestätigt hat.
  {
    digitalWrite(relaitPin1, HIGH);          //Schalte Relait Pin 1 ein
    relait1check = 1;
    Serial.println("Bin am befeuchten!");
    delay(15000);     //Verzögerung ca 30 Sekunden
  }
  
  if (h > optimaleLuftfeuchte && feuchtewert > 14)    //Wenn die aktuelle Feuchte höher als die Optimale Luftfeuchte ist und feuchtewert dies 15 mal bestätigt hat.
  {
    digitalWrite(relaitPin1, LOW);           //Schalte Relait Pin 1 aus
    relait1check = 0;
    Serial.println("Bin am rasten...keine Befeuchtung");
    delay(15000);                            //Verzögerung ca 30 Sekunden
  }
feuchtewert = 0;

 }
//***************************************************  
//***************************************************    
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

