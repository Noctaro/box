void heat_control()
{
if (t > optimaleTemperatur)
{
temperaturwert++;
}

if (t < optimaleTemperatur)
{
temperaturwert--;
}

Serial.print("Temperaturwert: ");
Serial.println(temperaturwert);
 
if (zaehler == 15)
 {
  if (t <= minTemperatur && t < optimaleTemperatur && temperaturwert == -15)
  {
  Serial.println("Heizung aktiv*");
  digitalWrite(relaitPin3, HIGH);         //Schalte relaitPin3 ein      
  relait3check = 1;
  boolean heatup =1;
  delay(100);
  }

  if (t >= optimaleTemperatur && temperaturwert == 15)
  {
  Serial.println("Heizung inaktiv*");
  digitalWrite(relaitPin3, LOW);         //Schalte relaitPin3 aus 
  relait3check = 0;    
  delay(100);
  }

  temperaturwert = 0;
 }

}


