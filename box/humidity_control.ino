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

if (zaehler == Messdurchgaenge)                                  //Wenn der Messzähler Messdurchgaenge Messdurchgänge erreicht hat                                  
 {
  
    //Der Schaltvorgang für den Befeuchter
    if (h <= minLuftfeuchte && feuchtewert <= Messdurchgaenge)    //Wenn die aktuelle Feuchte niedriger als die Optimale Luftfeuchte ist und feuchtewert dies Messdurchgaenge_negativ mal bestätigt hat.
    {
    digitalWrite(relaitPin1, HIGH);          //Schalte Relait Pin 1 ein
    relait1check = 1;
    humidity_balancer_ausgabe();
    }
  
    if (h >= optimaleLuftfeuchte && feuchtewert >= Messdurchgaenge && Absaugung_aktiv == 0)    //Wenn die aktuelle Feuchte höher als die Optimale Luftfeuchte ist und feuchtewert dies Messdurchgaenge mal bestätigt hat. Und die Absaugung nicht aktiv ist.
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
