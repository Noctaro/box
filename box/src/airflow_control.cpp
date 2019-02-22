#include "Arduino.h"
#include "serial_text.h"
#include "global_var.h"
#include "relais.h"
#include "airflow_control.h"
//#include "mode_settings_box.h"

void aircontrol()
{

  //Wenn Luftfeuchte zu niederig ODER Temperatur zo hoch UND Luftefeuchte hÃ¶her als der Minimalwert ist addieren wir zur Variable "air_zaehler" +1

  // disabled for testing
  //if(h > maxLuftfeuchte || t >= maxTemperatur && h > minLuftfeuchte || hourly_air_active == 1)

  if(h > maxLuftfeuchte || t >= maxTemperatur || hourly_air_active == 1)
  {
  air_zaehler++;
  }
  //Ansonsten
  else
  {
  air_zaehler--;
  }


if (zaehler == Messdurchgaenge)
{
  //Der Schaltert fÃ¼r die Abluft/Zuluft wird bei dem Zyklus Messdurchgaenge ausgefÃ¼hrt
    if(air_zaehler >= Messdurchgaenge)
    {
    air_ausgabe();
    relais_4_on(); //Schalte relais 4 ein
    Absaugung_aktiv = 1;

    }

  //Testing
    if(air_zaehler < Messdurchgaenge && hourly_air_active == 0)
    {
    air_ausgabe2();
    relais_4_off();
    /*digitalWrite(relaisPin4, LOW);
    relais4check = 0;*/
    Absaugung_aktiv = 0;
    }
    // <-

  air_zaehler = 0; //Wird nach dem . Zyklus zurÃ¼ckgesetzt
 }

}


void air_refresh()
{

  if (minute_global == air_refresh_minute_01 && h > minLuftfeuchte && hourly_air_active == 0 || minute_global == air_refresh_minute_02 && h > minLuftfeuchte && hourly_air_active == 0 || minute_global == air_refresh_minute_03 && h > minLuftfeuchte && hourly_air_active == 0 || minute_global == air_refresh_minute_04 && h > minLuftfeuchte && hourly_air_active == 0)
  {
    air_ausgabe();
    relais_4_on();
    hourly_air_active = 1;

    if (air_refresh_time == 0)
    {
     air_refresh_time = unix_seconds;
    }

    }
    //air_refresh_ausgabe();

  if (air_refresh_time != 0 && unix_seconds >= air_refresh_time+air_refresh_second && hourly_air_active ==1 && t <= optimaleTemperatur && h <= optimaleLuftfeuchte || h <= minLuftfeuchte && hourly_air_active ==1)
    {
     relais_4_off();
     air_ausgabe2();
     hourly_air_active = 0;
     air_refresh_time = 0;
    }



}
