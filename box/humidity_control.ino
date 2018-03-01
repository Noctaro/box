int relais_1_guard = 0;

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
    relais_1_on();          //Schalte Relait Pin 1 ein
    humidity_balancer_ausgabe();
    int relais_1_guard = unix_secounds;
    }
  
    if (h >= optimaleLuftfeuchte && feuchtewert >= Messdurchgaenge && Absaugung_aktiv == 0)    //Wenn die aktuelle Feuchte höher als die Optimale Luftfeuchte ist und feuchtewert dies Messdurchgaenge mal bestätigt hat. Und die Absaugung nicht aktiv ist.
    {
    relais_1_off();           //Schalte Relait Pin 1 aus
    relais1check = 0;
    humidity_balancer_ausgabe2();
    int relais_1_guard = unix_secounds;
    }
  
 
  feuchtewert = 0;
  }

  //TESTING BEFEUCHTUNG BEIM LÜFTEN
    if(water_with_air == 1 && t >= minTemperatur && h < optimaleLuftfeuchte && relais_1_guard <= unix_secounds+relais_1_guard_time)
      {
      relais_1_on();
      Absaugung_aktiv = 1;
      }
    
    if(water_with_air == 1 && h >= maxLuftfeuchte && relais_1_guard <= unix_secounds+relais_1_guard_time)
      {
      relais_1_off();
      }  

}
//***************************************************
//***************************************************
