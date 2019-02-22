#include "global_var.h"
#include "Arduino.h"
//#include "DS1302RTC.h"
#include "serial_text.h"

//#include "Time.h"
//#include "TimeLib.h"
//#include "wire.h"
#include "relais.h"
#include "led_signal.h"
#include "mode_settings_box.h"
//vorgefertigtes Textsegment - Stars
void Stars()
{
  Serial.println(F("*********"));
}


 void Zeitausgabe()
 {
/*

 tmElements_t tm;

 RTC.get();

 if (! RTC.read(tm))
  {
    hour_global = tm.Hour;
    minute_global = tm.Minute;
    second_global = tm.Second;
    if(Uhrzeit_anzeigen == 1 && excel_output == 0)
    {
    Stars();
    Serial.print("Uhrzeit: ");
    print2digits(tm.Hour);
    Serial.write('-');
    print2digits(tm.Minute);
    Serial.write('-');
    print2digits(tm.Second);
    Serial.println(" ");
    delay(print_delay);
    Stars();

    }



    if(Datum_anzeigen == 1 && excel_output == 0)
    {
    Serial.print("Datum (T/M/J):  ");
    Serial.print(tm.Day);
    Serial.write('/');
    Serial.print(tm.Month);
    Serial.write('/');
    Serial.println(tmYearToCalendar(tm.Year));
    delay(print_delay);
    Stars();
    }



    if(Wochentag_anzeigen == 1 && excel_output == 0)
    {
    Serial.print("Wochentag = ");
    Serial.print(tm.Wday);
    Serial.println();
    delay(print_delay);
    Stars();
    }

  }

  else
    {
    Serial.println(F("DS1302 read error!  Please check the circuitry."));
    Serial.println();
    delay(9000);
    }

*/
 }

//**********************************


//**********************************
void Modeswitch_ausgabe()
{
  if(Modeschalter_anzeigen == 1 && excel_output == 0)
  {
  Serial.print("Modus:");
  Serial.println(Mode,2);
  delay(print_delay);
  Stars();
  }
}
//**********************************


//**********************************
void Messzaehler_ausgabe()
{
if (Messdurchgang_anzeigen == 1 && excel_output == 0)
  {
  Serial.print("Messdurchgang ");
  Serial.print(zaehler);
  Serial.print(" von ");
  Serial.println(Messdurchgaenge);
  Stars();
  delay(print_delay);
  }
}
//**********************************



//**********************************
void Relaitcheck_ausgabe()
{
  if(Relaticheck_anzeigen == 1 && excel_output == 0)
  {
  Serial.print(F("Befeuchtung  -> Relait 1 Power: "));
  Serial.println(relais1check);
  Serial.print(F("Bewaesserung -> Relait 2 Power: "));
  Serial.println(relais2check);
  Serial.print(F("Heizung      -> Relait 3 Power: "));
  Serial.println(relais3check);
  Serial.print(F("Abluft       -> Relait 4 Power: "));
  Serial.println(relais4check);
  delay(print_delay);
  Stars();

  }
}
//**********************************



//**********************************
  void Schaltwerte_ausgabe()
  {
   if(Schaltvorgang_anzeigen && excel_output == 0)
   {
    if(Luftfeuchte_regulieren == 1)
    {
    Serial.print(F("Luftfeuchtewert: "));
    Serial.println(feuchtewert);
    }

    if(Temperatur_regulieren == 1)
    {
    Serial.print(F("Temperaturwert: "));
    Serial.println(temperaturwert);
    }

    if(Abluft_regulieren == 1)
    {
    Serial.print(F("Abluftwert: "));
    Serial.println(air_zaehler);
    }

   Serial.print(F("Schaltvorgang bei +-"));
   Serial.println(Messdurchgaenge);
   Stars();
   delay(print_delay);
   }
  }
//**********************************



//**********************************
void LuftfeuchteStatus_ausgabe()
{
  if (h <= minLuftfeuchte || h >= maxLuftfeuchte) //Wenn die Luftfeuchte unter minLuftfeuchte oder Ã¼ber maxLuftfeuchte
  {
    led_hum_critical();            //Schalte LedPin 1 ein

    if(Luftfeuchte_anzeigen ==1 && excel_output == 0)
    {
    Serial.println(F("Lufteuchte KRITISCH! -.-"));
    delay(print_delay);                            //VerzÃ¶gerung 1000cycles - ca. 0,5 Sekunden
    }

  }

   else //ansonsten
    {
      if(Luftfeuchte_anzeigen ==1 && excel_output == 0)
      {
      Serial.println(F("Lufteuchte OK! ^^Â´"));
      delay(print_delay);
      }
    }
 }
//**********************************


//**********************************
void TemperaturStatus_ausgabe()
{


  if(t < minTemperatur || t >= maxTemperatur)
  {
  led_temp_critical();  //Kritischen Status per LED ausgeben

    if(excel_output == 0)
    {
    Serial.println(F("Temperatur KRITISCH! -.-"));
    delay(print_delay);
    }
  }

 else
    {
     if(excel_output == 0)
     {
     Serial.println(F("Temperatur OK ^^"));
     delay(print_delay);
     }
    }
}
//**********************************



//**********************************
 void Temperatur_Luftfeuchte_ausgabe()
 {
  if(Luftfeuchte_anzeigen == 1 && excel_output == 0)
  {
  Serial.print(F("Luftfeuchitgkeit: "));
  Serial.print(h);
  Serial.println(" %\t");
  Stars();
  delay(print_delay);
  }

  if(Temperatur_anzeigen == 1 && excel_output == 0)
  {
  Serial.print(F("Temperatur: "));
  Serial.print(t);
  Serial.println(F(" *C "));
  Stars();
  delay(print_delay);

  //Serial.print(f);
  //Serial.print(" *F\t");
  //float hic = dht.computeHeatIndex(t, h, false);
  //Serial.print("Gefuehlte Temp: ");
  //Serial.print(hic);
  //Serial.println(" *C");
  //Stars();
  //delay(print_delay);
  //Serial.print(hif);
  //Serial.println(" *F");
  }
 }
//**********************************



//**********************************
void watercontrol_reset_ausgabe()
{
  if(excel_output == 0)
  {
  Serial.println(F("Bewaesserung wird zur gewaehlten Stunde aktiviert."));
  Serial.print(water_applied);
  Serial.println(F(" ins EEPROM geschrieben, Bewaesserung moeglich"));
  Serial.println(F("Warte 25 Sekunden"));
  }

  int count_reset_time = 0;
  while (count_reset_time <= 10)
  {
    count_reset_time++;
    delay(2500);
    if(excel_output == 0)
    {
    Serial.print("*");
    }

  }


}
//**********************************



//**********************************
void watercontrol_active_ausgabe()
{
      if(Wasserstand_anzeigen == 1 && excel_output == 0)
      {
      Serial.print(F("Relait 2 Power: "));
      Serial.println(relais2check);
      Serial.print(F("Bewaesserung laeuft fuer "));
      Serial.print(flush_time_seconds);
      Serial.println(F(" Sekunden"));
      }



      if(Wasserstand_anzeigen == 1 && excel_output == 0)
      {
        Serial.println(F("^^"));
      }
}

void watercontrol_active_ausgabe2()
{
      if(Wasserstand_anzeigen == 1 && excel_output == 0)
      {
      Serial.println(F("BW abgeschlossen."));
      Serial.print(water_applied);
      Serial.println(F(" ins EEPROM geschrieben"));
      }
}

//**********************************
void bewaesserung_status_ausgabe()
  {

    Serial.print(F("Bewaesserung ausgefuehrt: "));
    Serial.println(water_applied);
    delay(print_delay);
    Stars();

  }


//**********************************
void water_level_ausgabe()
{
  if(Wasserstand_anzeigen == 1 && excel_output == 0)
    {

    Serial.println(F("Wasserstand KRITISCH -.-"));
    Stars();
    delay(print_delay);
    }
}

void water_level_ausgabe2()
{
      if(Wasserstand_anzeigen == 1 && excel_output == 0)
      {

      Serial.println(F("Wasserstand OK"));
      Stars();
      delay(print_delay);
      }
}
//**********************************




//**********************************
void flushcontrol_active_ausgabe()
{
      if(excel_output == 0)
      {
      Serial.print(F("Relait 2 Power: "));
      Serial.println(relais2check);
      Serial.print(F("Bewaesserung laeuft"));
      Serial.print(flush_time_seconds);
      Serial.println(F(" Sekunden"));
      }


 int flush_time_counter = 0;
 while(flush_time_counter <= 10)
 {
 flush_time_counter++;
 Serial.print(F("*Watering System engaged! ☺"));
 delay(flush_time_seconds*100);
 }
 Serial.println(F("Watering System shutting down, all done! ♥"));
 delay(1000);
}

void flushcontrol_active_ausgabe2()
{
      if(excel_output == 0)
      {
      Serial.println(F("Bewaesserung abgeschlossen."));
      delay(print_delay);
      }
}
//**********************************



//**********************************
void Heizung_ausgabe()
{
  if(Schaltvorgang_anzeigen == 1 && excel_output == 0)
  {
  Stars();
  Serial.println(F("Heizung aktiv"));
  Stars();
  delay(print_delay);
  }
}

void Heizung_ausgabe2()
{
  if(Schaltvorgang_anzeigen == 1 && excel_output == 0)
  {
  Stars();
  Serial.println(F("Heizung inaktiv"));
  Stars();
  delay(print_delay);
  }
}
//**********************************



//**********************************
void humidity_balancer_ausgabe()
{
    if(Schaltvorgang_anzeigen == 1 && excel_output == 0)
    {
    Serial.println(F("Bin am befeuchten!"));
    Stars();
    delay(print_delay);
    }
}

void humidity_balancer_ausgabe2()
{
    if(Schaltvorgang_anzeigen == 1 && excel_output == 0)
    {
    Serial.println(F("keine Befeuchtung"));
    Stars();
    delay(print_delay);
    }
}
//**********************************



//**********************************
void air_ausgabe()
{
    if(Schaltvorgang_anzeigen == 1 && excel_output == 0)
    {
      Stars();
      Serial.println(F("Luftzirkulation aktiviert" ));
      Stars();
      delay(print_delay);
     }
}

void air_ausgabe2()
{
  if(Schaltvorgang_anzeigen == 1 && excel_output == 0)
    {
    Stars();
    Serial.println(F("Luftzirkulation deaktiviert" ));
    Stars();
    delay(print_delay);
    }
}

/*void air_refresh_ausgabe()
{
 int air_refresh_counter = 0;
 while(air_refresh_counter <= 10)
 {
 air_refresh_counter++;
 Serial.print("*");
 delay(air_refresh_second*100);
 }
}
*/
//**********************************

void waterlevel_print()
{
 Serial.print(F("Wasserlevel: "));
 Serial.println(water_lev);
 delay(print_delay);
}

//**********************************

//**********************************
void water_cycles_ausgabe()
{
 Serial.print(F("Durchgang "));
 Serial.print(water_cycles_done);
 Serial.print(F(" von "));
 delay(print_delay);
}


//**********************************
//Optimale Werte ausgeben
//**********************************
void print_mode_settings()
{
 Serial.print(F("*Maximale Temperatur= "));
 Serial.println(maxTemperatur);

 Serial.print(F("*Optimale Temperatur= "));
 Serial.println(optimaleTemperatur);

 Serial.print(F("*Minimale Temperatur= "));
 Serial.println(minTemperatur);

 delay(print_delay);



 Serial.print(F("*Maximale Luftfeuchte= "));
 Serial.println(maxLuftfeuchte);

 Serial.print(F("*Optimale Luftfeuchte= "));
 Serial.println(optimaleLuftfeuchte);

 Serial.print(F("*Minimale Luftfeuchte= "));
 Serial.println(minLuftfeuchte);

 delay(print_delay);

 Serial.print(F("*Sunrise= "));
 Serial.println(sonnenaufgang);
 Serial.print(F("*Sunset= "));
 Serial.println(sonnenuntergang);

 delay(print_delay);

 Serial.print(F("*Sonne aktiv= "));
 Serial.println(tag_active);

 delay(print_delay);

}

//**********************************
//Watercounter
//**********************************
void watercounter_print()
  {
   Serial.print(F("Next waterlevel reading: "));
   Serial.println(water_check_counter_cycles-water_check_counter);
  }


//**********************************

//**********************************





//**********************************
void CSVausgabe()
{

  if(excel_output == 1)
  {
/*
   Serial.print(F("Temperatur: "));
   Serial.print(t);
   Serial.print(",");
   Serial.print(F("Luftfeuchtigkeit: "));
   Serial.print(h);
   Serial.print(F(","));
   Serial.print(F("Wasserstand: "));
   Serial.print(water_check);
   Serial.print(F(","));
   Serial.print(F("Relait 1 Power: "));
   Serial.print(relais1check);
   Serial.print(F(","));
   Serial.print(F("Relait 2 Power: "));
   Serial.print(relais2check);
   Serial.print(F(","));
   Serial.print(F("Relait 3 Power: "));
   Serial.print(relais3check);
   Serial.print(F(","));
   Serial.print(F("Relait 4 Power: "));
   Serial.print(relais4check);
   Serial.print(F(","));

   tmElements_t tm;
   RTC.get();
   if (! RTC.read(tm))
   {
   Serial.print("Uhrzeit: ");
   print2digits(tm.Hour);
   Serial.print(':');
   print2digits(tm.Minute);
   Serial.print(':');
   print2digits(tm.Second);
   Serial.print(",");
   Serial.print("Datum (T/M/J):  ");
   Serial.print(tm.Day);
   Serial.print('/');
   Serial.print(tm.Month);
   Serial.print('/');
   Serial.print(tmYearToCalendar(tm.Year));
   }

   Serial.println(",");
*/
  }

}
//#endif
//**********************************
