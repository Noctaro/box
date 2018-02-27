//**************************************************
//FUNKTIONSAUSWAHL
//**************************************************
//Den Wert auf 0 setzen um diese Funktion zu deaktivieren
//**************************************************
void Box_functions()
{
  Luftfeuchte_regulieren = 1;  
  Temperatur_regulieren = 1;
  Abluft_regulieren = 1;
  Bewaesserung_regulieren = 1;
  
  Temperatur_anzeigen = 1;        //Gibt die aktuelle Temperatur am Serial Monitor aus.
  Luftfeuchte_anzeigen = 1;       //Gibt die aktuelle Luftfeuchte am Serial Monitor aus
  
  Wasserstand_anzeigen = 1;       //Gibt bei kritischem Wasserstand eine Meldung per Serial Monitor aus.
  Relaticheck_anzeigen = 1;       //Gibt den aktuellen Schaltzustand der Relaits am Serial Monitor aus.
  Schaltzyklus_anzeigen = 1;      //Gibt Meldungen über den Schaltzyklus der Relaits aus am Serial Monitor aus.
  Schaltvorgang_anzeigen = 1;     //Gibt Meldungen beim Schalten eines Relaits am Serial Monitor aus.
  Messdurchgang_anzeigen = 1;     //Gibt den aktuellen Messdurchlauf am Serial Monitor aus.
  TemperaturStatus_anzeigen = 1;  //Gibt bei kritischen Temperaturzuständen eine Meldung per Serial Monitor aus.
  Modeschalter_anzeigen = 1;      //Gibt den aktuell gewählten Modus am Serial Monitor aus.
  
  Uhrzeit_anzeigen = 1;           //Gibt die aktuelle Zeit am Serial Monitor aus
  Wochentag_anzeigen = 1;         //Gibt den aktuellen Wochentag am Serial Monitor aus
  Datum_anzeigen = 1;             //Gibt das aktuelle Datum am Serial Monitor aus
  
  excel_output = 0;               //Spezielle Ausgabe der Daten im CSV Format (alle anderen Anzeigen werden hierfür automatisch deaktiviert.)

  ////*********************************************************************************************************
  //Zeit die ziwschen Schaltvorgängen am relais 1 vergegen muss in Sekunden
  ////*********************************************************************************************************
  relais_1_guard_time = 180;      //Zeit die ziwschen Schaltvorgängen am relais 1 vergegen muss
  ////*********************************************************************************************************

  ////*********************************************************************************************************
  //Dauer bis zum nächsten Messdurchgang in Sekunden (WICHTIG: Mindestens 2 Sekunden um den DHT Sensor nicht zu überfordern!)
  //*********************************************************************************************************
   Messpause = 2;
   
   print_delay = 100; //Verzögerung bei der Ausgabe einer Zeile in ms. Sollte mindestens 50 sein
   
   

   
   Messdurchgaenge = 5; //Anzahl der Messdurchgänge bevor ein Relait geschalten wird
   Messdurchgaenge_negativ = 0 - Messdurchgaenge ;

}




//**************************************************
//MODEAUSWAHL
//**************************************************
//Hier die die gewünschte Modeauswahlmethode festlegen. Der gewünschte kann Mode nach belieben per Schalter oder Quellcode gweählt werden.
//Mode
//**************************************************

void Modeswitch()
{
Mode = 1;                               //Den gewünschten Modus im Code manuell setzen 0/1/2 - Hierfür muss die nächste Zeile auskommentiert werden
//Mode = digitalRead(Modeschalter);     //Lese den Status des physichen Modeschalters für die Wahl des gewünschten Modus - Hiefür muss die vorherige Zeile auskommentiert werden
}
//*********************************************************************************************************


//*********************************************************************************************************
//*********************************************************************************************************
//Hier die geünschten Werte für die 3 Modi eintragen
//*********************************************************************************************************
//*********************************************************************************************************

//**************************************************
//MODE 0 - CLIMATE I
//**************************************************
//Hier die Werte für !Mode 0! nach belieben eintragen
//Festlegen der gewünschten Temperaturen
//**************************************************
  
  void Mode0_settings_active()
  {
  maxTemperatur = 25;
  optimaleTemperatur = 24;
  minTemperatur = 22;
  //maxLuftfeuchte = 70;
  optimaleLuftfeuchte = 65;
  //minLuftfeuchte = 50; 
  
//  air_refresh_secound = 120; //Dauer der Belüftung in Sekunden (muss mehr als 60 Sekunden sein)
//  air_refresh_minute_01 = 15; //Minute zu der die Belüftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
//  air_refresh_minute_02 = 45; //Minute zu der die Belüftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
//  air_refresh_minute_03 = 00; //Minute zu der die Belüftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
//  air_refresh_minute_04 = 30; //Minute zu der die Belüftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  
//testing Zeitgesteuert
  if (hour_global < 20 || hour_global > 8) //Bei Tag
  {
  maxLuftfeuchte = 68; 
  minLuftfeuchte = 64;
  
  air_refresh_secound = 240; //Dauer der Belüftung in Sekunden (muss mehr als 60 Sekunden sein)
  
  air_refresh_minute_01 = 15;
  air_refresh_minute_02 = 45; //Minute zu der die Belüftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  air_refresh_minute_03 = 99; //Minute zu der die Belüftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  air_refresh_minute_04 = 99; //Minute zu der die Belüftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  }
  
  if (hour_global >= 23 || hour_global <= 7) //Bei Nacht
  {
  maxLuftfeuchte = 70;
  minLuftfeuchte = 60;
  
  air_refresh_secound = 380; //Dauer der Belüftung in Sekunden (muss mehr als 60 Sekunden sein)
  
  air_refresh_minute_01 = 99;
  air_refresh_minute_02 = 99; //Minute zu der die Belüftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  air_refresh_minute_03 = 99; //Minute zu der die Belüftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  air_refresh_minute_04 = 99; //Minute zu der die Belüftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  }
 
 //*********************************************************************************************************
 //UHRZEITEN für Bewässerung in MODE 0 hier eintragen! (10 verschiedeme Stunden stehen zur Verfügung 0-23 Uhr) (Zum deaktivieren einer Zeit einfach 99 eintragen)
 //*********************************************************************************************************
  water_hour_01 = 99;
  water_hour_cycles_01 = 1;  //Anzahl der Pumpvorgänge - sinvoll bei Pumpen mit eingebautem Timer, 
 //**********************
  water_hour_02 = 99;
  water_hour_cycles_02 = 1;  //sinvoll bei Pumpen mit eingebautem Timer
 //**********************  
  water_hour_03 = 99;
  water_hour_cycles_03 = 1;  //sinvoll bei Pumpen mit eingebautem Timer
 //**********************
  water_hour_04 = 99;
  water_hour_cycles_04 = 1;  //sinvoll bei Pumpen mit eingebautem Timer
 //**********************
  water_hour_05 = 99;
  water_hour_cycles_05 = 1;  //sinvoll bei Pumpen mit eingebautem Timer
 //********************** 
  water_hour_06 = 99;
  water_hour_cycles_06 = 1;  //sinvoll bei Pumpen mit eingebautem Timer
 //**********************  
  water_hour_07 = 99;
  water_hour_cycles_07 = 1;  //sinvoll bei Pumpen mit eingebautem Timer
 //**********************  
  water_hour_08 = 99;
  water_hour_cycles_08 = 1;  //sinvoll bei Pumpen mit eingebautem Timer
 //**********************  
  water_hour_09 = 99;
  water_hour_cycles_09 = 1;  //sinvoll bei Pumpen mit eingebautem Timer
 //**********************  
  water_hour_10 = 99;
  water_hour_cycles_10 = 1;  //sinvoll bei Pumpen mit eingebautem Timer
 //**********************
  
//*******************************************************************************************
//Dauer der Wasserzufuhr bei dem Bewässern
//*******************************************************************************************
long flush_time_secounds = 65;  
//*********************************************************************************************************
  
//***********************
water_with_air = 1; //Befeuchtung aktivieren wenn abgesaugt wird.
//***********************
   
//*********************************************************************************************************   
}//end of void MODE 0  
//*********************************************************************************************************



//*********************************************************************************************************
//********************************************************************************************************* 
 
  
//**************************************************
//MODE 1 - CLIMATE II
//**************************************************
  //Hier die Werte für MODE 1 nach belieben eintragen
  //Festlegen der gewünschten Temperaturen
  //************************************************** 
void Mode1_settings_active()
  {
  maxTemperatur = 26;
  optimaleTemperatur = 25;
  minTemperatur = 24;
  maxLuftfeuchte = 62;
  optimaleLuftfeuchte = 58;
  minLuftfeuchte = 57;
  
  air_refresh_secound = 300;  //Dauer der Belüftung in Sekunden (muss mindestens 65 Sekunden sein)
  air_refresh_minute_01 = 15; //Minute zu der die Belüftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  air_refresh_minute_02 = 45; //Minute zu der die Belüftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  air_refresh_minute_03 = 30; //Minute zu der die Belüftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  air_refresh_minute_04 = 00; //Minute zu der die Belüftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.

  
 //*********************************************************************************************************
 //UHRZEITEN für Bewässerung in MODE 1 hier eintragen! (10 verschiedeme Stunden stehen zur Verfügung)(Zum deaktivieren einer Zeit einfach 99 eintragen)
 //*********************************************************************************************************
  water_hour_01 = 99;
  water_hour_cycles_01 = 2; //Anzahl der Pumpvorgänge - sinvoll bei Pumpen mit eingebautem Timer, 
 //**********************
  water_hour_02 = 99;
  water_hour_cycles_02 = 1;  //sinvoll bei Pumpen mit eingebautem Timer
 //**********************  
  water_hour_03 = 99;
  water_hour_cycles_03 = 1;  //sinvoll bei Pumpen mit eingebautem Timer
 //**********************
  water_hour_04 = 99;
  water_hour_cycles_04 = 1;  
 //**********************
  water_hour_05 = 99;
  water_hour_cycles_05 = 1;  
 //********************** 
  water_hour_06 = 99;
  water_hour_cycles_06 = 1;  
 //**********************  
  water_hour_07 = 99;
  water_hour_cycles_07 = 1;  
 //**********************  
  water_hour_08 = 99;
  water_hour_cycles_08 = 1;  
 //**********************  
  water_hour_09 = 99;
  water_hour_cycles_09 = 1;  
 //**********************  
  water_hour_10 = 99;
  water_hour_cycles_10 = 1;  
 //**********************

//*******************************************************************************************
 flush_time_secounds = 90;  //Dauer der Wasserzufuhr bei dem Bewässern
//*********************************************************************************************************

//***********************
water_with_air = 0; //Befeuchtung aktivieren wenn abgesaugt wird.
//***********************

//*********************************************************************************************************   
}//end of void MODE 1   
//*********************************************************************************************************


//*********************************************************************************************************
//*********************************************************************************************************

  
//**************************************************
//MODE 2 - FLUSH
//**************************************************
  //Hier die Werte für MODE 2 nach belieben eintragen
  //Festlegen der gewünschten Temperaturen
  //************************************************** 

void Mode2_settings_active() //Flush Mode
  {
  maxTemperatur = 27;
  optimaleTemperatur = 26;
  minTemperatur = 25;
  maxLuftfeuchte = 60;
  optimaleLuftfeuchte = 50;
  minLuftfeuchte = 45;

 
 //*********************************************************************************************************
 //Zeitintervall für Bewässerung in MODE 2 hier eintragen! (10 verschiedeme Stunden stehen zur Verfügung)(Zum deaktivieren einer Zeit einfach 99 eintragen)
 //*********************************************************************************************************
 flush_time_secounds = 120;  //Dauer der Wasserzufuhr bei dem Bewässern
 //*******************************************************************************************
 flush_timer_secounds = 60;  //Zeit für Pause nach der Wasserzufuhr
 //*********************************************************************************************************


   
//*********************************************************************************************************   
}//end of void MODE 2   
//*********************************************************************************************************

//*********************************************************************************************************
//Relait test - relait 1 -> 1 blink then switch, relait 2 - 2 blink then switch,..... , restart
//*********************************************************************************************************
void Mode3_settings_active() 
  {
  digitalWrite(relaisPin1, LOW);         //Schalte relaitPin1 aus 
  digitalWrite(relaisPin2, LOW);         //Schalte relaitPin2 aus
  digitalWrite(relaisPin3, LOW);         //Schalte relaitPin3 aus - umgekehrte schaltlogik
  digitalWrite(relaisPin4, LOW);         //Schalte relaitPin4 aus
  
  int  i = 0;
    
  while(i<4)
    {
    i++;
    delay(2000);
    led_blinker();
    digitalWrite(relaisPin1, HIGH);
    delay(5000);
    digitalWrite(relaisPin1, LOW);
    }
    
      while(i<7)
    {
    i++;
    delay(2000);
    led_blinker();
    led_blinker();
    digitalWrite(relaisPin2, HIGH);
    delay(5000);
    digitalWrite(relaisPin2, LOW);
    }
    
          while(i<11)
    {
    i++;
    delay(2000);
    led_blinker();
    led_blinker();
    led_blinker();    
    digitalWrite(relaisPin3, HIGH);
    delay(5000);
    digitalWrite(relaisPin3, LOW);
    }
    
          while(i<14)
    {
    i++;
    delay(2000);
    led_blinker();
    led_blinker();
    led_blinker();
    led_blinker();    
    digitalWrite(relaisPin4, HIGH);
    delay(5000);
    digitalWrite(relaisPin4, LOW);
    }
  
//*********************************************************************************************************   
}//end of void MODE 3   
//*********************************************************************************************************
