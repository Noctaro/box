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

  water_with_air = 1;             //Wenn die Abluft aktiviert wird und die Luftfeuchte kleiner oder gleich der optimalen Feuchte ist,
                                  //wird auch die Befeuchtung aktiviert (gilt fÃ¼r alle Modi, falls in einem Modus nicht eigens festgelegt)

  heat_water_compensation = 1;    //Wenn die Temperatur zu hoch ist, wird bis zur maximalen Luftfeuchte befeuchtet, um dem Problem entgegen zu wirken.                                  
  
  excel_output = 0;               //Spezielle Ausgabe der Daten im CSV Format (alle anderen Anzeigen werden hierfÃ¼r automatisch deaktiviert.)

 //DHT Kalibrierung
 dht_adjustment_h = 0;             //DHT Feuchte Ausgabe anpassen
 dht_adjustment_t = 3;             //Temperatur Ausgabe anpassen

  ////*********************************************************************************************************
  //Zeit die ziwschen SchaltvorgÃ¤ngen am relais 1 vergegen muss in Sekunden
  ////*********************************************************************************************************
  relais_1_guard_time = 5;      // Feuchte
  relais_2_guard_time = 5;       // BewÃ¤sserung 
  relais_3_guard_time = 300;      // Heizung
  relais_4_guard_time = 5;       // Abluft
  ////*********************************************************************************************************

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
  maxTemperatur = 25;
  optimaleTemperatur = 24;
  minTemperatur = 22;
  //maxLuftfeuchte = 70;
  optimaleLuftfeuchte = 65;
  //minLuftfeuchte = 50; 
  
//  air_refresh_secound = 120; //Dauer der BelÃ¼ftung in Sekunden (muss mehr als 60 Sekunden sein)
//  air_refresh_minute_01 = 15; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
//  air_refresh_minute_02 = 45; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
//  air_refresh_minute_03 = 00; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
//  air_refresh_minute_04 = 30; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  
//testing Zeitgesteuert
  if (hour_global < 20 && hour_global > 8) //Bei Tag
  {
  maxLuftfeuchte = 68; 
  minLuftfeuchte = 64;
  
  air_refresh_secound = 240; //Dauer der BelÃ¼ftung in Sekunden (muss mehr als 60 Sekunden sein)
  
  air_refresh_minute_01 = 15;
  air_refresh_minute_02 = 45; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  air_refresh_minute_03 = 99; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  air_refresh_minute_04 = 99; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  }
  
  if (hour_global >= 20 && hour_global <= 8) //Bei Nacht
  {
  maxLuftfeuchte = 70;
  minLuftfeuchte = 60;
  
  air_refresh_secound = 380; //Dauer der BelÃ¼ftung in Sekunden (muss mehr als 60 Sekunden sein)
  
  air_refresh_minute_01 = 99;
  air_refresh_minute_02 = 99; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
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
//Befeuchtung aktivieren wenn abgesaugt wird. Kann hier exklusiv fÃ¼r diesen Mode aktiviert werden 
//water_with_air = 0; 
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
  /* 
  maxTemperatur = 26;
  optimaleTemperatur = 25;
  minTemperatur = 24;
  maxLuftfeuchte = 56;
  optimaleLuftfeuchte = 53;
  minLuftfeuchte = 52;
  
  air_refresh_secound = 300;  //Dauer der BelÃ¼ftung in Sekunden (muss mindestens 65 Sekunden sein)
  air_refresh_minute_01 = 15; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  air_refresh_minute_02 = 30; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  air_refresh_minute_03 = 45; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  air_refresh_minute_04 = 0; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  */
//******************************
  //testing Zeitgesteuert
//****************************** 
   int sonnenaufgang = 05;
   int sonnenuntergang = 01;
  
  //******************************
  //Bei Tag
  //******************************
  
  //if (hour_global >= sonnenaufgang && hour_global < sonnenuntergang ) //Bei Tag
  //if (hour_global >= sonnenaufgang)
  //{
  
  maxTemperatur = 24;
  optimaleTemperatur = 23;
  minTemperatur = 21;
  maxLuftfeuchte = 72;
  optimaleLuftfeuchte = 70;
  minLuftfeuchte = 68;
  
  air_refresh_secound = 180; //Dauer der BelÃ¼ftung in Sekunden (muss mehr als 60 Sekunden sein)
  
  air_refresh_minute_01 = 20;
  air_refresh_minute_02 = 40; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  air_refresh_minute_03 = 00; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  air_refresh_minute_04 = 99; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.

  tag_active = 1;//<-nicht ï¿½ndern
  //}

  //******************************
  //Bei Nacht
  //******************************
  //if (hour_global >= sonnenuntergang || hour_global < sonnenaufgang) //Bei Nacht
  if (hour_global >= sonnenuntergang && hour_global < sonnenaufgang)
  {
  maxTemperatur = 20;
  optimaleTemperatur = 19;
  minTemperatur = 18;
  maxLuftfeuchte = 70;
  optimaleLuftfeuchte = 68;
  minLuftfeuchte = 66;
  
  air_refresh_secound = 300; //Dauer der BelÃ¼ftung in Sekunden (muss mehr als 60 Sekunden sein)
  
  air_refresh_minute_01 = 00;
  air_refresh_minute_02 = 15; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  air_refresh_minute_03 = 30; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
  air_refresh_minute_04 = 45; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.

  tag_active = 0;//<-nicht ï¿½ndern
  }

  //GUI SETTINGS
  
  if (gui_opt_temp > 0)
    {
    optimaleTemperatur = gui_opt_temp;
    minTemperatur = gui_min_temp;
    maxTemperatur = gui_max_temp;
    optimaleLuftfeuchte = gui_opt_hum;
    minLuftfeuchte = gui_min_hum;
    maxLuftfeuchte = gui_max_hum;
    }
    
  
  
 //*********************************************************************************************************
 //UHRZEITEN fÃ¼r BewÃ¤sserung in MODE 1 hier eintragen! (10 verschiedeme Stunden stehen zur VerfÃ¼gung)(Zum deaktivieren einer Zeit einfach 99 eintragen)
 //*********************************************************************************************************
  water_hour_01 = 16;
  water_hour_cycles_01 = 2; //Anzahl der PumpvorgÃ¤nge - sinvoll bei Pumpen mit eingebautem Timer, 
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
 flush_time_secounds = 90;  //Dauer der Wasserzufuhr bei dem BewÃ¤ssern
//*********************************************************************************************************

//***********************
//Befeuchtung aktivieren wenn abgesaugt wird. Kann hier exklusiv fÃ¼r diesen Mode aktiviert werden 
//water_with_air = 0; 
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
//Relait test - relait 1 -> 1 blink then switch, relait 2 - 2 blink then switch,..... , restart
//*********************************************************************************************************
void Mode3_settings_active() 
  {
  digitalWrite(relaisPin1, LOW);         //Schalte relaitPin1 aus 
  digitalWrite(relaisPin2, LOW);         //Schalte relaitPin2 aus
  digitalWrite(relaisPin3, LOW);         //Schalte relaitPin3 aus 
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
