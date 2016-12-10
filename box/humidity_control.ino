  //*********************************************************************
  //DHT auslesen
  //*********************************************************************  
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  //*********************************************************************
  
void DHT_check_input()
{
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  //Serial.print(f);
  //Serial.print(" *F\t");
  Serial.print("Gefuehlte Temperatur: ");
  Serial.print(hic);
  Serial.println(" *C");
  //Serial.print(hif);
  //Serial.println(" *F");
  
    delay(2000);
}    
//********************************************
//*********************************************************************

//*********************************************************************************************************
//Schaltvorgang optimieren Feuchte
//*********************************************************************************************************
void huimdity_check_optimizer()
{

if (h > optimaleLuftfeuchte)
{
feuchtewert++;
<<<<<<< HEAD
Serial.println("*********");
Serial.print("Der aktuelle Feuchtewert ");
Serial.println(feuchtewert);
Serial.println("Schaltvorgang bei +-15");
Serial.println("*********");
Serial.println("Letzte Messung: Luftfeuchte hoeher als der Optimalwert");
Serial.println("****************************************");
=======
>>>>>>> 8765e7a3f2e4ce17529752816b9c4c1ed80d07c2
}

if (h < optimaleLuftfeuchte)
{
feuchtewert--;
<<<<<<< HEAD
Serial.println("*********");
Serial.print("Der aktuelle Feuchtewert ");
Serial.print(feuchtewert);
Serial.println("( Schaltvorgang bei +-15)");
Serial.println("*********");
Serial.println("Letzte Messung: Luftfeuchte niedriger als der Optimalwert");
Serial.println("****************************************");
}
Serial.println("****************************************");
=======
}

Serial.print("      Luftfeuchtewert ");
Serial.print(feuchtewert);
Serial.println("        (Schaltvorgang bei +-15)");
Serial.println("*********");
  
  if (h <= minLuftfeuchte || h >= maxLuftfeuchte) //Wenn die Luftfeuchte unter minLuftfeuchte oder über maxLuftfeuchte
  {
    digitalWrite(LedPin1, HIGH);            //Schalte LedPin 1 ein
    Serial.print("Luftfeuchtigkeit KRITISCH! -.-        ");
    delay(1000);                            //Verzögerung 1000cycles - ca. 0,5 Sekunden
  }
  
   else //ansonsten
    {
    digitalWrite(LedPin1, LOW);              //Schalte LedPin 1 aus
    Serial.print("Luftfeuchtigkeit OK ^^        ");
    }
>>>>>>> 8765e7a3f2e4ce17529752816b9c4c1ed80d07c2
}
//*************************************************

//*********************************************************************************************************


//*********************************************************************************************************
//Schaltvorgang und Feedback
//*********************************************************************************************************
void humidity_balancer()
{
h = dht.readHumidity();
t = dht.readTemperature();
if (zaehler==15)                                  //Wenn der Messzähler 15 Messdurchgänge erreicht hat                                  
 {
  zaehler = 0;
//***************************************************
//***************************************************
<<<<<<< HEAD
  if (t <= minTemperatur || t >= maxTemperatur || h <= minLuftfeuchte || h >= maxLuftfeuchte) //Wenn die Temperatur kleiner als minTemperatur oder höher als maxTemperatur oder Luftfeuchte unter minLuftfeuchte oder über maxLuftfeuchte
  {
    digitalWrite(LedPin1, HIGH);            //Schalte LedPin 1 ein
    Serial.println("Achtung Temperatur oder Feuchte sind problematisch!!");
    delay(3000);                            //Verzögerung 1000cycles - ca. 0,5 Sekunden
  }
  
 else //ansonsten
  {
    digitalWrite(LedPin1, LOW);              //Schalte LedPin 1 aus
    Serial.println("Temperatur und Feuchte sind schwer in Ordnung :)");
    delay(3000);                             //Verzögerung 1000cycles - ca. 0,5 Sekunden
  }
  
  
//Der Schaltvorgang für den Befeuchter
  if (h < optimaleLuftfeuchte && feuchtewert < -14)    //Wenn die aktuelle Feuchte niedriger als die Optimale Luftfeuchte ist und feuchtewert dies 15 mal bestätigt hat.
=======

  

  
//Der Schaltvorgang für den Befeuchter
  if (h <= minLuftfeuchte && feuchtewert < -14)    //Wenn die aktuelle Feuchte niedriger als die Optimale Luftfeuchte ist und feuchtewert dies 15 mal bestätigt hat.
>>>>>>> 8765e7a3f2e4ce17529752816b9c4c1ed80d07c2
  {
    digitalWrite(relaitPin1, HIGH);          //Schalte Relait Pin 1 ein
    relait1check = 1;
    Serial.println("Bin am befeuchten!");
    delay(5000);     //Verzögerung 
  }
  
<<<<<<< HEAD
  if (h > optimaleLuftfeuchte && feuchtewert > 14)    //Wenn die aktuelle Feuchte höher als die Optimale Luftfeuchte ist und feuchtewert dies 15 mal bestätigt hat.
=======
  if (h >= optimaleLuftfeuchte && feuchtewert > 14)    //Wenn die aktuelle Feuchte höher als die Optimale Luftfeuchte ist und feuchtewert dies 15 mal bestätigt hat.
>>>>>>> 8765e7a3f2e4ce17529752816b9c4c1ed80d07c2
  {
    digitalWrite(relaitPin1, LOW);           //Schalte Relait Pin 1 aus
    relait1check = 0;
    Serial.println("Bin am rasten...keine Befeuchtung");
    delay(5000);                            //Verzögerung ca 30 Sekunden
  }
feuchtewert = 0;
  
 }
<<<<<<< HEAD
}
=======
}
>>>>>>> 8765e7a3f2e4ce17529752816b9c4c1ed80d07c2
