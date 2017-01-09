void humidity_balancer()
{
//*********************************************************************************************************
//Temperatur und Feuchte auslesen
//*********************************************************************************************************  
//h = dht.readHumidity();
//t = dht.readTemperature();

//*********************************************************************************************************
//Schaltvorgang optimieren Feuchte
//*********************************************************************************************************
if (h > optimaleLuftfeuchte)
{
feuchtewert++;
}

if (h < optimaleLuftfeuchte)
{
feuchtewert--;
}

if (zaehler == 15)                                  //Wenn der Messzähler 15 Messdurchgänge erreicht hat                                  
 {
  
    //Der Schaltvorgang für den Befeuchter
    if (h <= minLuftfeuchte && feuchtewert < -14)    //Wenn die aktuelle Feuchte niedriger als die Optimale Luftfeuchte ist und feuchtewert dies 15 mal bestätigt hat.
    {
    digitalWrite(relaitPin1, HIGH);          //Schalte Relait Pin 1 ein
    relait1check = 1;
    humidity_balancer_ausgabe();
    }
  
    if (h >= optimaleLuftfeuchte && feuchtewert > 14)    //Wenn die aktuelle Feuchte höher als die Optimale Luftfeuchte ist und feuchtewert dies 15 mal bestätigt hat.
    {
    digitalWrite(relaitPin1, LOW);           //Schalte Relait Pin 1 aus
    relait1check = 0;
    humidity_balancer_ausgabe2();
    }

  feuchtewert = 0;
  }
}
//***************************************************
//***************************************************
