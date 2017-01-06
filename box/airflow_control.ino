void aircontrol()
{

  //Wenn Luftfeuchte zu niederig ODER Temperatur zo hoch UND Luftefeuchte höher als der Minimalwert ist addieren wir zur Variable "air_zaehler" +1 
  if(h >= maxLuftfeuchte || t > maxTemperatur && h >= minLuftfeuchte)
  {
  air_zaehler++;
  }
  //Ansonsten 
  else
  {
  air_zaehler--;  
  }



  //Der Schaltert für die Abluft/Zuluft wird bei dem Zyklus 15 ausgeführt
  if (zaehler == 15) 
  {
    if(air_zaehler >= 15)
    {
    air_ausgabe();
    digitalWrite(relaitPin4, HIGH);
    relait4check = 1;
    }  
  
    if(air_zaehler <= -15)  
    {
    air_ausgabe2();        
    digitalWrite(relaitPin4, LOW);
    relait4check = 0;
    }

  air_zaehler = 0; //Wird nach dem 15. Zyklus zurückgesetzt
  }

}  

