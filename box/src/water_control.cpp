#include "relais.h"
#include "serial_text.h"
#include "global_var.h"
#include "water_control.h"
#include <EEPROM.h>
#include "Arduino.h"
//*********************************************************************************************************
//BewÃ¤sserung
//*********************************************************************************************************

//*********************************************************************************************************
//BewÃ¤sserung fÃ¼r die kommende Stunde wieder aktivieren
//*********************************************************************************************************
void watercontrol_reset()
{
       //BewÃ¤sserung ab Minute 59 wieder ermÃ¶glichen.
       water_applied = 0;
       EEPROM.write(eeprom_address_watered, water_applied);
       watercontrol_reset_ausgabe();
}

//*********************************************************************************************************
//Der Schaltvorgang fÃ¼r die BewÃ¤sserung falls eine fÃ¼r die BewÃ¤sserung gewÃ¤hlte Stunde eintritt.
//*********************************************************************************************************
void watercontrol_active()
{
      //BewÃ¤sserung aktivieren
      relais_2_on();

      Serial.println(relais2check);

      watercontrol_active_ausgabe();

      int count_watercontrol_time = 0;
      while (count_watercontrol_time <= 10)
      {
      count_watercontrol_time++;
        if(excel_output == 0)
        {
        delay(flush_time_seconds*100); //VerzÃ¶gerung fÃ¼r ein 10tel der angegebenen Zeit in Sekunden
        Serial.print(F("*"));
        }
      }

      //BewÃ¤sserung deaktivieren
      relais_2_off();

      Serial.println(relais2check);

      delay(1000);
}

//*********************************************************************************************************
//Wasser Sensor auslesen
//*********************************************************************************************************

void water_level()
 {
 if(water_check_counter >= water_check_counter_cycles)
  {
  water_check_counter = 0;
  digitalWrite(Water_Sensor_Power, HIGH); //Power the sensor
  delay(1500); //wait for sensorvoltage to stabilize
  int water_lev_raw = analogRead(Water_Sensor); //read the sensor
  delay(150); //wait for reading
  Serial.println("Wasser RAW:");
  Serial.println(water_lev_raw);
  water_lev = map(water_lev_raw, 1023, 0, 0, 100); // scale analog output from 1015-0 back into the 0-100 range
  digitalWrite(Water_Sensor_Power, LOW);
  }
  else
  {
   water_check_counter++;
   watercounter_print();
  }
 }
//*********************************************************************************************************



//*********************************************************************************************************
//Flush Mode
//*********************************************************************************************************
void flushcontrol_active()
{
      //BewÃ¤sserung aktivieren
      relais_2_on();
      flushcontrol_active_ausgabe();


      //BewÃ¤sserung deaktivieren
      relais_2_off();
      flushcontrol_active_ausgabe2();

}
