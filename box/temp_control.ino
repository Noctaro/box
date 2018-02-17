void heat_control()
{
if (t >= optimaleTemperatur)
{
temperaturwert++;
}

if (t < optimaleTemperatur)
{
temperaturwert--;
}


 
if (zaehler == Messdurchgaenge)
 {
  if (t <= minTemperatur && t < optimaleTemperatur && temperaturwert == Messdurchgaenge_negativ)
  {
  Heizung_ausgabe();
  //digitalWrite(relaitPin3, HIGH);         //Schalte relaitPin3 ein      
  pinMode(relaitPin3, INPUT);
  relait3check = 1;
  delay(100);
  }

  if (t >= optimaleTemperatur && temperaturwert == Messdurchgaenge)
  {
  Heizung_ausgabe2();
  //digitalWrite(relaitPin3, LOW);         //Schalte relaitPin3 aus 
  pinMode(relaitPin3, OUTPUT);
  relait3check = 0;    
  delay(100);
  }
  
  temperaturwert = 0;
 }

  

}

