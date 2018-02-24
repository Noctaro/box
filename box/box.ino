//  __   __     ______     ______           __         ______     ______     __  __     __    
// /\ "-.\ \   /\  __ \   /\  ___\         /\ \       /\  ___\   /\  __ \   /\ \/\ \   /\ \   
// \ \ \-.  \  \ \ \/\ \  \ \ \____        \ \ \____  \ \  __\   \ \ \/\_\  \ \ \_\ \  \ \ \  
//  \ \_\\"\_\  \ \_____\  \ \_____\        \ \_____\  \ \_____\  \ \___\_\  \ \_____\  \ \_\ 
//   \/_/ \/_/   \/_____/   \/_____/    &    \/_____/   \/_____/   \/___/_/   \/_____/   \/_/ 
                                                                                           

//NOCEDIT
//*********************************************************************************************************


//*********************************************************************************************************
//Sensor auswählen - aktuell kann nur ein Sensor aktiv sein. Beim gewünschten Sensor den Wert auf SENSOR_used = 1 stellen. Beim anderen Sensor muss dieser Wert dann auf 0 gesetzt werden. 
//*********************************************************************************************************
#include "dht_setup.h"
const int DHT_used = 0;

#include "sht_setup.h"
const int SHT_used = 1;
//*********************************************************************************************************



//*********************************************************************************************************
//Funktionen für das Clock modul einbinden
//*********************************************************************************************************
#include "clock_setup.h"
//*********************************************************************************************************

//*********************************************************************************************************
//PIN fÃ¼r den Wassersensor
//*********************************************************************************************************
//BenÃ¶tigt Remapping - Pin 1 == Serial TX
#define Water_Sensor A2 //Definiere den Wassersensor Pin
//*********************************************************************************************************

//*********************************************************************************************************
//PIN fÃ¼r den Schalter der Modeauswahlfunktion
//*********************************************************************************************************
//BenÃ¶tigt Remapping - Pin 2 == Serial TX
#define Modeschalter A1 //Definiere den Pin fÃ¼r den Schalter zwischen Mode 0, 1 und 2
//*********************************************************************************************************


//*********************************************************************************************************
//PIN fÃ¼r die Statusled
//*********************************************************************************************************
#define LedPin1 13     //Namen fÃ¼r den Ledpin
//*********************************************************************************************************


//*********************************************************************************************************
//RELAIT PINS
//*********************************************************************************************************
#define relaitPin1 5 //Definiere den Namen und Pin fÃ¼r das 1. Relait - Feuchte
#define relaitPin2 6 //Definiere den Namen und Pin fÃ¼r das 2. Relait - Wasser  
#define relaitPin3 7 //Definiere den Namen und Pin fÃ¼r das 3. Relait - Heizung 
#define relaitPin4 4 //Definiere den Namen und Pin fÃ¼r das 4. Relait - Abluft

//alternate Testing

//*********************************************************************************************************


//*********************************************************************************************************
//EEPROM
//*********************************************************************************************************
#include <EEPROM.h>
int eeprom_address_watered = 0;
//*********************************************************************************************************


//*********************************************************************************************************
//Globale Variablen (Bitte nicht Ã¤ndern) -> GewÃ¼nschte Werte sind in mode_settings.ino anpassbar
//*********************************************************************************************************
int zaehler = 0;
//int zaehler2 = 0;
int air_zaehler = 0;

int feuchtewert = 0;
int temperaturwert = 0;


int maxTemperatur = 0;
int minTemperatur = 0;
int optimaleTemperatur = 0;

int maxLuftfeuchte = 0;
int minLuftfeuchte = 0;
int optimaleLuftfeuchte = 0;
//int dht_adjust = 10; //Sollte der DHT Sensor die Luftfeuchte falsch anzeigen, kann hier eine Anpassung vorgenommen werden.

int Messpause = 0;
int Messdurchgaenge = 0;
int Messdurchgaenge_negativ = 0;

int Absaugung_aktiv = 0;

int water_with_air = 0;

int air_refresh_secound = 0;

int dht_adjustment_h = 0;
int dht_adjustment_t = 0;

float h = 0; //Variable fÃ¼r aktuelle Luftfeuchte in %
float t = 0; //Variable fÃ¼r aktuelle Temperatur in Celsius
float f = 0; //Variable fÃ¼r aktuelle Temperatur in Fahrenheit
float hif = 0;
float hic = 0;

int minute_global = 0;
int hour_global = 0;
long unix_secounds = 0;
long air_refresh_time = 0;

boolean relait1check = 0;
boolean relait2check = 0;
boolean relait3check = 0;
boolean relait4check = 0;

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

int water_hour_cycles_01 = 1;
int water_hour_cycles_02 = 1;
int water_hour_cycles_03 = 1;
int water_hour_cycles_04 = 1;
int water_hour_cycles_05 = 1;
int water_hour_cycles_06 = 1;
int water_hour_cycles_07 = 1;
int water_hour_cycles_08 = 1;
int water_hour_cycles_09 = 1;
int water_hour_cycles_10 = 1;

int air_refresh_minute_01 = 99; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
int air_refresh_minute_02 = 99; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
int air_refresh_minute_03 = 99; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
int air_refresh_minute_04 = 99; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.

int air_refresh_times = 0;

int print_delay = 0;

//String inData = 0;

boolean water_applied = 1;
int water_cycles_done = 0;
boolean water_check = 1;

boolean hourly_air_active = 0;

long flush_time_secounds = 90;  //Dauer der Wasserzufuhr bei dem BewÃ¤ssern
long flush_timer_secounds = 60; //Dauer der Pause bis zur nÃ¤chsten SpÃ¼lung

byte Mode = 0; 

//Box Funktionen 
boolean Luftfeuchte_regulieren = 1; 
boolean Temperatur_regulieren = 1;
boolean Abluft_regulieren = 1;
boolean Bewaesserung_regulieren = 1;

boolean Temperatur_anzeigen = 1;        //Gibt die aktuelle Temperatur am Serial Monitor aus.
boolean Luftfeuchte_anzeigen = 1;       //Gibt die aktuelle Luftfeuchte am Serial Monitor aus
boolean Wasserstand_anzeigen = 1;
boolean Relaticheck_anzeigen = 1;
boolean Messdurchgang_anzeigen = 1;
boolean TemperaturStatus_anzeigen = 1;
boolean Schaltvorgang_anzeigen = 1;
boolean Schaltzyklus_anzeigen = 1;
boolean Modeschalter_anzeigen = 1;

boolean Uhrzeit_anzeigen = 1;
boolean Wochentag_anzeigen = 1;
boolean Datum_anzeigen = 1;

boolean excel_output = 1;

//*********************************************************************************************************
//*********************************************************************************************************

//WATCHDOG library
//*********************************************************************************************************
//#include <avr/wdt.h>
//*********************************************************************************************************



//*********************************************************************************************************
//Setup Loop wird einmal ausgefÃ¼hrt
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
  pinMode(relaitPin1, OUTPUT); //Setze den Steuerpin fÃ¼r Relait 1 als Ausgang
  pinMode(relaitPin2, OUTPUT); //Setze den Steuerpin fÃ¼r Relait 2 als Ausgang
  pinMode(relaitPin3, OUTPUT); //Setze den Steuerpin fÃ¼r Relait 3 als Ausgang
  pinMode(relaitPin4, OUTPUT); //Setze den Steuerpin fÃ¼r Relait 4 als Ausgang
  
  digitalWrite(relaitPin1, LOW);         //Schalte relaitPin1 aus 
  digitalWrite(relaitPin2, LOW);         //Schalte relaitPin2 aus
  digitalWrite(relaitPin3, LOW);         //Schalte relaitPin3 aus
  digitalWrite(relaitPin4, LOW);         //Schalte relaitPin4 aus
  

  
  pinMode(Modeschalter, INPUT);  //Setze den Steuerpin fÃ¼r den gewÃ¼nschten Modus als Eingang
//  pinMode(DHT_powerPin, OUTPUT); //Setze den PowerPin fÃ¼r den DHT Sensor als Ausgang
  pinMode(LedPin1, OUTPUT); //Setze den Steuerpin fÃ¼r Led1 als Ausgang
  pinMode(Water_Sensor, INPUT);     //The Water Sensor is an Input
  //*****************
 
 
  
// digitalWrite(DHT_powerPin, HIGH);      //Schalte DHT Powerpin ein 
  digitalWrite(LedPin1, LOW);            //Schalte LedPin 1 aus

  //*********************************************************************************************************
  //Clock Module Initialisierung
  //*********************************************************************************************************  
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
  
  delay(5000);

  water_applied = EEPROM.read(eeprom_address_watered);
  //Serial.print("Bewaesserungsstatus = ");
  //Serial.println(water_applied);
//*********************************************************************************************************

//*********************************************************************************************************
//Boxfunktionen aktivieren oder deaktivieren
//*********************************************************************************************************
Box_functions();    
//*********************************************************************************************************

//Watchdog Timer - beisst nach 8 Sekunden zu
 //*********************************************************************************************************
//wdt_enable(WDTO_8S);
//*********************************************************************************************************

} //END OF SETUP
//*********************************************************************************************************
//*********************************************************************************************************


//*********************************************************************************************************
//MAINLOOP
//*********************************************************************************************************
void loop()
{
//************
//CyclezÃ¤hler
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


//*********************************************************************
//DHT
//*********************************************************************  
// Reading temperature or humidity takes about 250 milliseconds!
// Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
//*********************************************************************  
if(DHT_used == 1)
{
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
}
//********************************************************************* 

//*********************************************************************
//SHT31
//********************************************************************* 
if(SHT_used == 1)
{ 
 t = sht31.readTemperature();
 h = sht31.readHumidity();
}

//*********************************************************************************************************  
//Modeschalter
//*********************************************************************************************************
  Modeswitch();           //Legt den ausgewÃ¤hlten Mode fest
  
  
//*********************************************************************************************************
//Lesen der Modekonfiguration und Aktivieren der gewÃ¼nschten Einstellungen
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
//BewÃ¤sserung
//*********************************************************************************************************
//Der Schaltvorgang fÃ¼r die BewÃ¤sserung falls eine fÃ¼r die BewÃ¤sserung gewÃ¤hlte Stunde eintritt.
//*********************************************************************************************************
if(Bewaesserung_regulieren == 1)
{
if(Mode == 1 || Mode == 0)
    {
    water_applied = EEPROM.read(eeprom_address_watered);
    bewaesserung_status_ausgabe();
    water_cycles_done = 0;

      if (hour_global == water_hour_01 && water_applied == 0)
      {
      Stars();     
      while (water_cycles_done < water_hour_cycles_01)
       {
        water_cycles_done++;
        water_cycles_ausgabe();
        Serial.println(water_hour_cycles_01);

        watercontrol_active(); //Auskommentieren falls keine BewÃ¤sserung notwendig
        delay(3000); //Schaltpause 
        //*********************************************************************************************************  
        //Watchdog Timer reset - avoid biting  
        //*********************************************************************************************************  
        //wdt_reset();
        //*********************************************************************************************************
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

        watercontrol_active(); //Auskommentieren falls keine BewÃ¤sserung notwendig
        delay(3000); //Schaltpause
        //*********************************************************************************************************  
        //Watchdog Timer reset - avoid biting  
        //*********************************************************************************************************  
        //wdt_reset();
        //*********************************************************************************************************
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

        watercontrol_active(); //Auskommentieren falls keine BewÃ¤sserung notwendig
        delay(3000); //Schaltpause
        //*********************************************************************************************************  
        //Watchdog Timer reset - avoid biting  
        //*********************************************************************************************************  
        //wdt_reset();
        //*********************************************************************************************************
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

        watercontrol_active(); //Auskommentieren falls keine BewÃ¤sserung notwendig
        delay(3000); //Schaltpause  
        //*********************************************************************************************************  
        //Watchdog Timer reset - avoid biting  
        //*********************************************************************************************************  
        //wdt_reset();
        //*********************************************************************************************************
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

        watercontrol_active(); //Auskommentieren falls keine BewÃ¤sserung notwendig
        delay(3000); //Schaltpause 
        //*********************************************************************************************************  
        //Watchdog Timer reset - avoid biting  
        //*********************************************************************************************************  
        //wdt_reset();
        //*********************************************************************************************************
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

        watercontrol_active(); //Auskommentieren falls keine BewÃ¤sserung notwendig
        delay(3000); //Schaltpause  
        //*********************************************************************************************************  
        //Watchdog Timer reset - avoid biting  
        //*********************************************************************************************************  
        //wdt_reset();
        //*********************************************************************************************************
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

        watercontrol_active(); //Auskommentieren falls keine BewÃ¤sserung notwendig
        delay(3000); //Schaltpause  
        //*********************************************************************************************************  
        //Watchdog Timer reset - avoid biting  
        //*********************************************************************************************************  
        //wdt_reset();
        //*********************************************************************************************************        
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

        watercontrol_active(); //Auskommentieren falls keine BewÃ¤sserung notwendig
        delay(3000); //Schaltpause  
        //*********************************************************************************************************  
        //Watchdog Timer reset - avoid biting  
        //*********************************************************************************************************  
        //wdt_reset();
        //*********************************************************************************************************        
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

        watercontrol_active(); //Auskommentieren falls keine BewÃ¤sserung notwendig
        delay(3000); //Schaltpause  
        //*********************************************************************************************************  
        //Watchdog Timer reset - avoid biting  
        //*********************************************************************************************************  
        //wdt_reset();
        //*********************************************************************************************************
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

        watercontrol_active(); //Auskommentieren falls keine BewÃ¤sserung notwendig
        delay(3000); //Schaltpause  
        //*********************************************************************************************************  
        //Watchdog Timer reset - avoid biting  
        //*********************************************************************************************************  
        //wdt_reset();
        //*********************************************************************************************************        
       }
      water_applied = 1;
      EEPROM.write(eeprom_address_watered, water_applied); 
      watercontrol_active_ausgabe2();
      Stars();
      }
      //****
      //****
      
  
      //ÃœberprÃ¼fe ob die BewÃ¤sserung zur aktuellen Stunde ausgefÃ¼hrt wurde
      if ( minute_global == 59 && water_applied == 1 )
      {
      //Stars();
        
      watercontrol_reset(); //Auskommentieren falls keine BewÃ¤sserung notwendig
      
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
//MesszÃ¤hler
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
//Schaltwerte fÃ¼r Lufteuchte, Temperatur, Abluft ausgeben
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
//ZÃ¤hler Reset
//*********************************************************************************************************
  if(zaehler >= Messdurchgaenge)
  {
  zaehler = 0;
  }

//*********************************************************************************************************
//VerzÃ¶gerung bis zur nÃ¤chsten Messung
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
//    {
//        inData = Serial.readStringUntil('\n');
//       Serial.println("*data: "+inData);
//       delay(2000);
//       inData="";
//     }

//*********************************************************************************************************  
//Watchdog Timer reset - avoid biting  
//*********************************************************************************************************  
//wdt_reset();
//*********************************************************************************************************
  
  //************************************     
} //END OF Mainloop

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
  //Serial.println("*********");
}
