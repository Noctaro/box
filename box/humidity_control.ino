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

if (zaehler == Messdurchgaenge)                                  //Wenn der MesszÃ¤hler Messdurchgaenge MessdurchgÃ¤nge erreicht hat                                  
 {
  
    //Der Schaltvorgang fÃ¼r den Befeuchter
    if (h <= minLuftfeuchte && feuchtewert <= Messdurchgaenge)    //Wenn die aktuelle Feuchte niedriger als die Optimale Luftfeuchte ist und feuchtewert dies Messdurchgaenge_negativ mal bestÃ¤tigt hat.
    {
    digitalWrite(relaitPin1, HIGH);          //Schalte Relait Pin 1 ein
    relait1check = 1;
    humidity_balancer_ausgabe();
    }
  
    if (h >= optimaleLuftfeuchte && feuchtewert >= Messdurchgaenge && Absaugung_aktiv == 0)    //Wenn die aktuelle Feuchte hÃ¶her als die Optimale Luftfeuchte ist und feuchtewert dies Messdurchgaenge mal bestÃ¤tigt hat. Und die Absaugung nicht aktiv ist.
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
