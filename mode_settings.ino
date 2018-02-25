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
  Schaltzyklus_anzeigen = 1;      //Gibt Meldungen Ã¼ber den Schaltzyklus der Relaits aus am Serial Monitor aus.
  Schaltvorgang_anzeigen = 1;     //Gibt Meldungen beim Schalten eines Relaits am Serial Monitor aus.
  Messdurchgang_anzeigen = 1;     //Gibt den aktuellen Messdurchlauf am Serial Monitor aus.
  TemperaturStatus_anzeigen = 1;  //Gibt bei kritischen TemperaturzustÃ¤nden eine Meldung per Serial Monitor aus.
  Modeschalter_anzeigen = 1;      //Gibt den aktuell gewÃ¤hlten Modus am Serial Monitor aus.
  
  Uhrzeit_anzeigen = 1;           //Gibt die aktuelle Zeit am Serial Monitor aus
  Wochentag_anzeigen = 1;         //Gibt den aktuellen Wochentag am Serial Monitor aus
  Datum_anzeigen = 1;             //Gibt das aktuelle Datum am Serial Monitor aus
  
  excel_output = 0;               //Spezielle Ausgabe der Daten im CSV Format (alle anderen Anzeigen werden hierfÃ¼r automatisch deaktiviert.)

  ////*********************************************************************************************************
  //Dauer bis zum nÃ¤chsten Messdurchgang in Sekunden (WICHTIG: Mindestens 2 Sekunden um den DHT Sensor nicht zu Ã¼berfordern!)
  //*********************************************************************************************************
   Messpause = 2;
   
   print_delay = 100; //VerzÃ¶gerung bei der Ausgabe einer Zeile in ms. Sollte mindestens 50 sein
   
   

   
   Messdurchgaenge = 5; //Anzahl der MessdurchgÃ¤nge bevor ein Relait geschalten wird
   Messdurchgaenge_negativ = 0 - Messdurchgaenge ;

}




//**************************************************
//MODEAUSWAHL
//**************************************************
//Hier die die gewÃ¼nschte Modeauswahlmethode festlegen. Der gewÃ¼nschte kann Mode nach belieben per Schalter oder Quellcode gweÃ¤hlt werden.
//Mode
//**************************************************

void Modeswitch()
{
Mode = 1;                               //Den gewÃ¼nschten Modus im Code manuell setzen 0/1/2 - HierfÃ¼r muss die nÃ¤chste Zeile auskommentiert werden
//Mode = digitalRead(Modeschalter);     //Lese den Status des physichen Modeschalters fÃ¼r die Wahl des gewÃ¼nschten Modus - HiefÃ¼r muss die vorherige Zeile auskommentiert werden
}
//*********************************************************************************************************


//*********************************************************************************************************
//*********************************************************************************************************
//Hier die geÃ¼nschten Werte fÃ¼r die 3 Modi eintragen
//*********************************************************************************************************
//*********************************************************************************************************

//**************************************************
//MODE 0 - CLIMATE I
//**************************************************
//Hier die Werte fÃ¼r !Mode 0! nach belieben eintragen
//Festlegen der gewÃ¼nschten Temperaturen
//**************************************************
  
  void Mode0_settings_active()
  {
  //maxTemperatur = 27;
  //optimaleTemperatur = 26;
  //minTemperatur = 25;
  //maxLuftfeuchte = 52;
  //optimaleLuftfeuchte = 45;
  //minLuftfeuchte = 43;
  //air_refresh_secound = 65;  //Dauer der BelÃ¼ftung in Sekunden (muss mindestens 65 Sekunden sein)
  //air_refresh_minute_01 = 15; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  //air_refresh_minute_02 = 45; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  //air_refresh_minute_03 = 99; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  //air_refresh_minute_04 = 99; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  
  //Zeiten für Zeitsteuerung
  int tagbeginn_stunde = 18;       //Sonnenaufgang 
  int nachtbeginn_stunde = 12;    //Sonnenuntergang
  
 
  //Zeitgesteuert -Bei Tag
  //*******************************************//
  if (hour_global < nachtbeginn_stunde || hour_global >= tagbeginn_stunde) //Bei Tag
  {
  maxTemperatur = 27;
  optimaleTemperatur = 26;
  minTemperatur = 25;
    
  maxLuftfeuchte = 68; 
  optimaleLuftfeuchte = 65;
  minLuftfeuchte = 64;
  
  air_refresh_secound = 240; //Dauer der BelÃ¼ftung in Sekunden (muss mehr als 60 Sekunden sein)
  
  air_refresh_minute_01 = 15;
  air_refresh_minute_02 = 45; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  air_refresh_minute_03 = 99; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  air_refresh_minute_04 = 99; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  }
  
  //Zeitgesteuert - Bei Nacht
  //*******************************************//
  if (hour_global >= nachtbeginn_stunde || hour_global < tagbeginn_stunde) //Bei Nacht
  {
  maxTemperatur = 27;
  optimaleTemperatur = 26;
  minTemperatur = 25;
    
  maxLuftfeuchte = 68; 
  optimaleLuftfeuchte = 65;
  minLuftfeuchte = 64;
  
  air_refresh_secound = 240; //Dauer der BelÃ¼ftung in Sekunden (muss mehr als 60 Sekunden sein)
  
  air_refresh_minute_01 = 15;
  air_refresh_minute_02 = 45; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  air_refresh_minute_03 = 99; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  air_refresh_minute_04 = 99; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  }
 
 //*********************************************************************************************************
 //UHRZEITEN fÃ¼r BewÃ¤sserung in MODE 0 hier eintragen! (10 verschiedeme Stunden stehen zur VerfÃ¼gung 0-23 Uhr) (Zum deaktivieren einer Zeit einfach 99 eintragen)
 //*********************************************************************************************************
  water_hour_01 = 99;
  water_hour_cycles_01 = 1;  //Anzahl der PumpvorgÃ¤nge - sinvoll bei Pumpen mit eingebautem Timer, 
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
//Dauer der Wasserzufuhr bei dem BewÃ¤ssern
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
  //Hier die Werte fÃ¼r MODE 1 nach belieben eintragen
  //Festlegen der gewÃ¼nschten Temperaturen
  //************************************************** 
void Mode1_settings_active()
  {
  //maxTemperatur = 27;
  //optimaleTemperatur = 26;
  //minTemperatur = 25;
  //maxLuftfeuchte = 52;
  //optimaleLuftfeuchte = 45;
  //minLuftfeuchte = 43;
  //air_refresh_secound = 65;  //Dauer der BelÃ¼ftung in Sekunden (muss mindestens 65 Sekunden sein)
  //air_refresh_minute_01 = 15; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  //air_refresh_minute_02 = 45; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  //air_refresh_minute_03 = 99; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  //air_refresh_minute_04 = 99; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  
  //Zeiten für Zeitsteuerung
  int tagbeginn_stunde = 7;       //Sonnenaufgang 
  int nachtbeginn_stunde = 23;    //Sonnenuntergang
  
 
  //Zeitgesteuert -Bei Tag
  //*******************************************//
  if (hour_global < nachtbeginn_stunde || hour_global > tagbeginn_stunde) //Bei Tag
  {
  maxTemperatur = 27;
  optimaleTemperatur = 26;
  minTemperatur = 25;
    
  maxLuftfeuchte = 68; 
  optimaleLuftfeuchte = 65;
  minLuftfeuchte = 64;
  
  air_refresh_secound = 240; //Dauer der BelÃ¼ftung in Sekunden (muss mehr als 60 Sekunden sein)
  
  air_refresh_minute_01 = 15;
  air_refresh_minute_02 = 45; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  air_refresh_minute_03 = 99; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  air_refresh_minute_04 = 99; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  }
  
  //Zeitgesteuert - Bei Nacht
  //*******************************************//
  if (hour_global >= nachtbeginn_stunde || hour_global <= tagbeginn_stunde) //Bei Nacht
  {
  maxTemperatur = 27;
  optimaleTemperatur = 26;
  minTemperatur = 25;
    
  maxLuftfeuchte = 68; 
  optimaleLuftfeuchte = 65;
  minLuftfeuchte = 64;
  
  air_refresh_secound = 380; //Dauer der BelÃ¼ftung in Sekunden (muss mehr als 60 Sekunden sein)
  
  air_refresh_minute_01 = 99;
  air_refresh_minute_02 = 99; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  air_refresh_minute_03 = 99; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  air_refresh_minute_04 = 99; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
}
  


  
 //*********************************************************************************************************
 //UHRZEITEN fÃ¼r BewÃ¤sserung in MODE 1 hier eintragen! (10 verschiedeme Stunden stehen zur VerfÃ¼gung)(Zum deaktivieren einer Zeit einfach 99 eintragen)
 //*********************************************************************************************************
  water_hour_01 = 2;
  water_hour_cycles_01 = 2; //Anzahl der PumpvorgÃ¤nge - sinvoll bei Pumpen mit eingebautem Timer, 
 //**********************
  water_hour_02 = 6;
  water_hour_cycles_02 = 1;  //sinvoll bei Pumpen mit eingebautem Timer
 //**********************  
  water_hour_03 = 8;
  water_hour_cycles_03 = 1;  //sinvoll bei Pumpen mit eingebautem Timer
 //**********************
  water_hour_04 = 10;
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
 flush_time_secounds = 90;  //Dauer der Wasserzufuhr bei dem BewÃ¤ssern
//*********************************************************************************************************

//***********************
water_with_air = 1; //Befeuchtung aktivieren wenn abgesaugt wird.
//***********************

//*********************************************************************************************************   
}//end of void MODE 1   
//*********************************************************************************************************


//*********************************************************************************************************
//*********************************************************************************************************

  
//**************************************************
//MODE 2 - FLUSH
//**************************************************
  //Hier die Werte fÃ¼r MODE 2 nach belieben eintragen
  //Festlegen der gewÃ¼nschten Temperaturen
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
 //Zeitintervall fÃ¼r BewÃ¤sserung in MODE 2 hier eintragen! (10 verschiedeme Stunden stehen zur VerfÃ¼gung)(Zum deaktivieren einer Zeit einfach 99 eintragen)
 //*********************************************************************************************************
 flush_time_secounds = 120;  //Dauer der Wasserzufuhr bei dem BewÃ¤ssern
 //*******************************************************************************************
 flush_timer_secounds = 60;  //Zeit fÃ¼r Pause nach der Wasserzufuhr
 //*********************************************************************************************************


   
//*********************************************************************************************************   
}//end of void MODE 2   
//*********************************************************************************************************

//*********************************************************************************************************
//Mode 3 - Relait test - relait 1 -> 1 blink then switch, relait 2 - 2 blink then switch,..... , restart
//*********************************************************************************************************
void Mode3_settings_active() 
  {
  digitalWrite(relaitPin1, LOW);         //Schalte relaitPin1 aus 
  digitalWrite(relaitPin2, LOW);         //Schalte relaitPin2 aus
  digitalWrite(relaitPin3, LOW);         //Schalte relaitPin3 aus 
  digitalWrite(relaitPin4, LOW);         //Schalte relaitPin4 aus
  
  int  i = 0;
    
  while(i<2)
    {
    i++;
    delay(2000);
    led_blinker();
    digitalWrite(relaitPin1, HIGH);
    delay(5000);
    digitalWrite(relaitPin1, LOW);
    }
    
      while(i<4)
    {
    i++;
    delay(2000);
    led_blinker();
    led_blinker();
    digitalWrite(relaitPin2, HIGH);
    delay(5000);
    digitalWrite(relaitPin2, LOW);
    }
    
          while(i<6)
    {
    i++;
    delay(2000);
    led_blinker();
    led_blinker();
    led_blinker();    
    digitalWrite(relaitPin3, HIGH);
    delay(5000);
    digitalWrite(relaitPin3, LOW);
    }
    
          while(i<8)
    {
    i++;
    delay(2000);
    led_blinker();
    led_blinker();
    led_blinker();
    led_blinker();    
    digitalWrite(relaitPin4, HIGH);
    delay(5000);
    digitalWrite(relaitPin4, LOW);
    }
  
//*********************************************************************************************************   
}//end of void MODE 3   
//*********************************************************************************************************

