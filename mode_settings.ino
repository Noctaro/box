 
  
  
  //**************************************************
  //MODE 0
  //**************************************************
  //Hier die Werte für !Mode 0! nach belieben eintragen
  //Festlegen der gewünschten Temperaturen
  //**************************************************
void Mode0_active()
  {
  maxTemperatur = 29;
  minTemperatur = 17;
  maxLuftfeuchte = 37;
  minLuftfeuchte = 35;
  optimaleLuftfeuchte = 36;
 //*********************************************************************************************************
 //UHRZEITEN für Bewässerung für Mode 1 hier eintragen! (Zum deaktivieren einer Zeit einfach 99 eintragen)
 //*********************************************************************************************************
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
void Mode1_active()
  {
  maxTemperatur = 29;
  minTemperatur = 17;
  maxLuftfeuchte = 70;
  minLuftfeuchte = 60;
  optimaleLuftfeuchte = 68;
 
 //*********************************************************************************************************
 //UHRZEITEN für Bewässerung für Mode 1 hier eintragen! (10 verschiedeme Stunden stehen zur Verfügung (Zum deaktivieren einer Zeit einfach 99 eintragen)
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
  long flush_time_secounds = 90;  //Dauer der Wasserzufuhr bei dem Bewässern
  //*********************************************************************************************************
  }     




