

void humidity_balancer()
{
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
    relais_1_on();          //Schalte Relait Pin 1 ein
    humidity_balancer_ausgabe();
    }
  
    if (h >= optimaleLuftfeuchte && feuchtewert >= Messdurchgaenge && Absaugung_aktiv == 0)    //Wenn die aktuelle Feuchte hÃ¶her als die Optimale Luftfeuchte ist und feuchtewert dies Messdurchgaenge mal bestÃ¤tigt hat. Und die Absaugung nicht aktiv ist.
    {
    relais_1_off();           //Schalte Relait Pin 1 aus
    humidity_balancer_ausgabe2();
    }
  
 
  feuchtewert = 0;
  }

  //TESTING BEFEUCHTUNG BEIM LÃœFTEN
  
    if(water_with_air == 1 && t >= minTemperatur && h <= optimaleLuftfeuchte) // Wenn die temperatur grÃ¶ÃŸer oder gleich der minimalen Temperatur ist und die Luftfeuchte kleiner als die optimale Feuchte ist 
      {
      relais_1_on();              //Schalte befeuchtung ein
      Absaugung_aktiv = 1;
      }
    
    if(water_with_air == 1 && h > optimaleLuftfeuchte) //Wenn die Luftfeuchte grÃ¶ÃŸer oder gleich der maximalen Feuchte ist
      {
      relais_1_off();            //Schalte befeuchtung aus
      Absaugung_aktiv = 0;
      }  

}
//***************************************************
//***************************************************
