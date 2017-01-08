<<<<<<< HEAD
void heat_check()
{
  if(t < minTemperatur || t >= maxTemperatur)
  {
    Serial.println("Temperatur KRITISCH! -.-"); 
    Serial.println("***");
    digitalWrite(LedPin1, HIGH);            //Schalte LedPin 1 ein  
    delay(100);
  } 
 
 else
    {
     Serial.println("Temperatur OK ^^"); 
     Serial.println("***");
     digitalWrite(LedPin1, LOW);            //Schalte LedPin 1 ein
    }

}



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

Serial.print("Temperaturwert: ");
Serial.print(temperaturwert);
 
if (zaehler2 == 15)
 {
  if (t <= minTemperatur && t < optimaleTemperatur && temperaturwert == -15)
  {
  Serial.print("    -> Heizung aktiv*");
  digitalWrite(relaitPin3, HIGH);         //Schalte relaitPin3 ein      
  relait3check = 1;
  //boolean heatup =1;
  delay(100);
  }

  if (t >= optimaleTemperatur && temperaturwert == 15)
  {
  Serial.print("    -> Heizung inaktiv");
  digitalWrite(relaitPin3, LOW);         //Schalte relaitPin3 aus 
  relait3check = 0;    
  delay(100);
  }
  zaehler2 = 0;
  temperaturwert = 0;
 }

  

}


=======
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


 
if (zaehler == 15)
 {
  if (t <= minTemperatur && t < optimaleTemperatur && temperaturwert == -15)
  {
  Heizung_ausgabe();
  digitalWrite(relaitPin3, HIGH);         //Schalte relaitPin3 ein      
  relait3check = 1;
  delay(100);
  }

  if (t >= optimaleTemperatur && temperaturwert == 15)
  {
  Heizung_ausgabe2();
  digitalWrite(relaitPin3, LOW);         //Schalte relaitPin3 aus 
  relait3check = 0;    
  delay(100);
  }
  
  temperaturwert = 0;
 }

  

}


>>>>>>> refs/remotes/origin/noc
