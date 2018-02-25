void aircontrol()
{

  //Wenn Luftfeuchte zu niederig ODER Temperatur zo hoch UND Luftefeuchte hÃ¶her als der Minimalwert ist addieren wir zur Variable "air_zaehler" +1 

  // disabled for testing 
  //if(h > maxLuftfeuchte || t >= maxTemperatur && h > minLuftfeuchte || hourly_air_active == 1)
  
  if(h > maxLuftfeuchte || t >= maxTemperatur || hourly_air_active == 1)
  {
  air_zaehler++;
  }
  //Ansonsten 
  else
  {
  air_zaehler--;  
  }

  
if (zaehler == Messdurchgaenge)
{
  //Der Schaltert fÃ¼r die Abluft/Zuluft wird bei dem Zyklus Messdurchgaenge ausgefÃ¼hrt
    if(air_zaehler >= Messdurchgaenge)
    {           
    //Testing new ->  
    //air_ausgabe();
    //digitalWrite(relaitPin4, HIGH);
    //relait4check = 1;
      
    //air_refresh_ausgabe();
    
    //air_ausgabe2();        
    //digitalWrite(relaitPin4, LOW);
    //relait4check = 0;   
    // <-
    
    //original ->
    air_ausgabe();
    digitalWrite(relaitPin4, HIGH);
    relait4check = 1;
    
    //TESTING BEFEUCHTUNG BEIM LÃœFTEN
    if(water_with_air == 1 && t >= minTemperatur && h < optimaleLuftfeuchte)
      {
      digitalWrite(relaitPin1, HIGH);
      relait1check = 1;
      Absaugung_aktiv = 1;
      }
    if(water_with_air == 1 && h >= maxLuftfeuchte)
      {
      digitalWrite(relaitPin1, LOW);
      relait1check = 0;
      }      
    }  
  
  //Testing
    if(air_zaehler < Messdurchgaenge && hourly_air_active == 0)  
    {
    air_ausgabe2();        
    digitalWrite(relaitPin4, LOW);
    relait4check = 0;
    Absaugung_aktiv = 0;
    }
    // <-
 
  air_zaehler = 0; //Wird nach dem . Zyklus zurÃ¼ckgesetzt
 }
 //TESTING
 //if(h <= optimaleLuftfeuchte && t <= maxTemperatur )
 // {
 // air_ausgabe2();        
 // digitalWrite(relaitPin4, LOW);
 // relait4check = 0;
 // }
}  

//TESTING
void air_refresh()
{
  
  if (minute_global == air_refresh_minute_01 && h >= optimaleLuftfeuchte && hourly_air_active == 0 || minute_global == air_refresh_minute_02 && h >= optimaleLuftfeuchte && hourly_air_active == 0 || minute_global == air_refresh_minute_03 && h >= optimaleLuftfeuchte && hourly_air_active == 0 || minute_global == air_refresh_minute_04 && h >= optimaleLuftfeuchte && hourly_air_active == 0)
  {
    air_ausgabe();
    digitalWrite(relaitPin4, HIGH);
    relait4check = 1;
    hourly_air_active = 1;
    
    if (air_refresh_time == 0)
    {
     air_refresh_time = unix_secounds; 
    }
    
    }
    //air_refresh_ausgabe(); 

  if (air_refresh_time != 0 && unix_secounds >= air_refresh_time+air_refresh_secound)
    {    
     digitalWrite(relaitPin4, LOW);
     air_ausgabe2();
     relait4check = 0; 
     hourly_air_active = 0;
     air_refresh_time = 0;  
    }
     
  
 
}
  
