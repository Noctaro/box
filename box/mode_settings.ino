 

  
//**************************************************
//MODE 0
//**************************************************
  //Hier die Werte für !Mode 0! nach belieben eintragen
  //Festlegen der gewünschten Temperaturen
  //**************************************************
  void Mode0_settings_active()
  {
  maxTemperatur = 29;
  optimaleTemperatur = 21;
  minTemperatur = 20;
  maxLuftfeuchte = 39;
  minLuftfeuchte = 30;
  optimaleLuftfeuchte = 37;
 //*********************************************************************************************************
 //UHRZEITEN für Bewässerung in Mode 0 hier eintragen! (10 verschiedeme Stunden stehen zur Verfügung 0-23 Uhr) (Zum deaktivieren einer Zeit einfach 99 eintragen)
 //*********************************************************************************************************
  water_hour_01 = 20;
  water_hour_02 = 21;
  water_hour_03 = 22;
  water_hour_04 = 23;
  water_hour_05 = 24;
  water_hour_06 = 99;
  water_hour_07 = 99;
  water_hour_08 = 99;
  water_hour_09 = 99;
  water_hour_10 = 99;
  //*******************************************************************************************
  long flush_time_secounds = 90;  //Dauer der Wasserzufuhr bei dem Bewässern
  //*********************************************************************************************************
   } 


//*********************************************************************************************************
//*********************************************************************************************************
//*********************************************************************************************************
  
 
  
//**************************************************
//MODE 1
//**************************************************
  //Hier die Werte für !Mode 1! nach belieben eintragen
  //Festlegen der gewünschten Temperaturen
  //************************************************** 
void Mode1_settings_active()
  {
  maxTemperatur = 29;
  optimaleTemperatur = 20;
  minTemperatur = 17;
  maxLuftfeuchte = 70;
  minLuftfeuchte = 60;
  optimaleLuftfeuchte = 68;
 
 //*********************************************************************************************************
 //UHRZEITEN für Bewässerung in Mode 1 hier eintragen! (10 verschiedeme Stunden stehen zur Verfügung)(Zum deaktivieren einer Zeit einfach 99 eintragen)
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
  }     


  
//**************************************************
//MODE 2 - FLUSH
//**************************************************
  //Hier die Werte für !Mode 2! nach belieben eintragen
  //Festlegen der gewünschten Temperaturen
  //************************************************** 

void Mode2_settings_active() //Flush Mode
  {
  maxTemperatur = 29;
  optimaleTemperatur = 20;
  minTemperatur = 17;
  maxLuftfeuchte = 70;
  minLuftfeuchte = 60;
  optimaleLuftfeuchte = 68;

 
 //*********************************************************************************************************
 //Zeitintervall für Bewässerung in Mode 2 hier eintragen! (10 verschiedeme Stunden stehen zur Verfügung)(Zum deaktivieren einer Zeit einfach 99 eintragen)
 //*********************************************************************************************************
 flush_time_secounds = 120;  //Dauer der Wasserzufuhr bei dem Bewässern
 //*******************************************************************************************
 flush_timer_secounds = 60;  //Zeit für Pause nach der Wasserzufuhr
 //*********************************************************************************************************
  }    



