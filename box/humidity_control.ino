

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

  if (h_w_compenstation_active == 0)
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
    }

  if (h_w_compenstation_active == 0)
      {
      air_water();  
      }


  if (heat_water_compensation == 1)
      {
      water_heat();
      }
      
  feuchtewert = 0;
  }



}


//************************
//HEATCOMPENSATION TESTING
//************************
//Wenn die Temperatur zu hoch ist, wird bis zur maximalen Luftfeuchte befeuchtet, um dem Problem entgegen zu wirken.
void water_heat()
{  
if (heat_water_compensation == 1)
  {
  
  if (maxTemperatur < t && h < maxLuftfeuchte)  //Nur aktiv wenn die Temperatur überschritten wird, aber nicht wenn die maximale Luftfeuchte überschritten wird.
    {
      h_w_compenstation_active = 1;
      relais_1_on();
      Serial.println(F("*Befeuchtung aufgrund von Hitze aktiviert!"));
      delay(1000);
    }
    
    if(h_w_compenstation_active == 1 && maxTemperatur > t)
    {
      h_w_compenstation_active = 0;
      relais_1_off();
      Serial.println(F("*Befeuchtung aufgrund von Hitze deaktiviert!"));
    }
 
  }
} 
//************************

//************************
//TESTING BEFEUCHTUNG BEIM LÃœFTEN
//************************  
  void air_water()
  {
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
//************************






//***************************************************
//***************************************************
