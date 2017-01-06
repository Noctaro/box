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
  //Dauer bis zum nächsten Messdurchgang in Sekunden (WICHTIG: Mindestens 2 Sekunden um den DHT Sensor nicht zu überfordern!)
  //*********************************************************************************************************
   Messpause = 4;
}




//**************************************************
//MODEAUSWAHL
//**************************************************
//Hier die die gewünschte Modeauswahlmethode festlegen. Der gewünschte kann Mode nach belieben per Schalter oder Quellcode gweählt werden.
//**************************************************

void Modeswitch()
{
Mode = 1;                               //Den gewünschten Modus im Code manuell setzen - Hierfür muss die nächste Zeile auskommentiert werden
//Mode = digitalRead(Modeschalter);     //Lese den Status des physichen Modeschalters für die Wahl des gewünschten Modus - Hiefür muss die vorherige Zeile auskommentiert werden
}
//*********************************************************************************************************


//*********************************************************************************************************
//*********************************************************************************************************
//Hier die geünschten Werte für die 3 Modi eintragen
//*********************************************************************************************************
//*********************************************************************************************************

//**************************************************
//MODE 0 - GROW
//**************************************************
//Hier die Werte für !Mode 0! nach belieben eintragen
//Festlegen der gewünschten Temperaturen
//**************************************************
  
  void Mode0_settings_active()
  {
  maxTemperatur = 28;
  optimaleTemperatur = 26;
  minTemperatur = 24;
  maxLuftfeuchte = 65;
  optimaleLuftfeuchte = 60;
  minLuftfeuchte = 50;
  
 
 //*********************************************************************************************************
 //UHRZEITEN für Bewässerung in MODE 0 hier eintragen! (10 verschiedeme Stunden stehen zur Verfügung 0-23 Uhr) (Zum deaktivieren einer Zeit einfach 99 eintragen)
 //*********************************************************************************************************
  water_hour_01 = 13;
  water_hour_02 = 99;
  water_hour_03 = 99;
  water_hour_04 = 99;
  water_hour_05 = 99;
  water_hour_06 = 99;
  water_hour_07 = 99;
  water_hour_08 = 99;
  water_hour_09 = 99;
  water_hour_10 = 99;
  
  //*******************************************************************************************
  //Dauer der Wasserzufuhr bei dem Bewässern
  //*******************************************************************************************
  long flush_time_secounds = 90;  
  //*********************************************************************************************************


   
//*********************************************************************************************************   
}//end of void MODE 0  
//*********************************************************************************************************



//*********************************************************************************************************
//********************************************************************************************************* 
 
  
//**************************************************
//MODE 1 - BLOOM
//**************************************************
  //Hier die Werte für MODE 1 nach belieben eintragen
  //Festlegen der gewünschten Temperaturen
  //************************************************** 
void Mode1_settings_active()
  {
  maxTemperatur = 28;
  optimaleTemperatur = 26;
  minTemperatur = 24;
  maxLuftfeuchte = 55;
  optimaleLuftfeuchte = 50;
  minLuftfeuchte = 45;
  
 
 //*********************************************************************************************************
 //UHRZEITEN für Bewässerung in MODE 1 hier eintragen! (10 verschiedeme Stunden stehen zur Verfügung)(Zum deaktivieren einer Zeit einfach 99 eintragen)
 //*********************************************************************************************************
 water_hour_01 = 99;
 water_hour_02 = 99;
 water_hour_03 = 99;
 water_hour_04 = 99;
 water_hour_05 = 99;
 water_hour_06 = 99;
 water_hour_07 = 99;
 water_hour_08 = 99;
 water_hour_09 = 99;
 water_hour_10 = 99;

//*******************************************************************************************
 flush_time_secounds = 90;  //Dauer der Wasserzufuhr bei dem Bewässern
//*********************************************************************************************************


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
  maxTemperatur = 29;
  optimaleTemperatur = 20;
  minTemperatur = 17;
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




