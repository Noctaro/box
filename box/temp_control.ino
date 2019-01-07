//**************************************************
//TEMPERATURE CONTROL
//If all measuring loops are done, turn on heater while min temperature or less is reached. If temperature has reached optimum or above, turn off heater.
//We take samples of the temperature each loop and add or substract +-1 to "temperaturwert" depending on "optimaleTemperatur". So glitches on the sensor will not cause
//instant switching. You may adjust the amount of samples taken before switching in "mode_settings_box" file.
//**************************************************

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
  relais_3_on(); 
  }

  if (t >= optimaleTemperatur && temperaturwert == Messdurchgaenge)
  {
  Heizung_ausgabe2();
  relais_3_off();
  }
  
  temperaturwert = 0;
 }


}





