//**********************************
 void Zeitausgabe()
 {
 tmElements_t tm; 
 if (! RTC.read(tm)) 
  {
    hour_global = tm.Hour;
    minute_global = tm.Minute;
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
    Stars();
    delay(print_delay);  
    }
    
    
    
    if(Datum_anzeigen == 1 && excel_output == 0)
    {
    Serial.print("Datum (T/M/J):  ");
    Serial.print(tm.Day);
    Serial.write('/');
    Serial.print(tm.Month);
    Serial.write('/');
    Serial.println(tmYearToCalendar(tm.Year));
    Stars();
    delay(print_delay);
    }



    if(Wochentag_anzeigen == 1 && excel_output == 0)
    {
    Serial.print("Wochentag = ");
    Serial.print(tm.Wday);
    Serial.println();
    Stars();
    delay(print_delay);
    }
    
  } 
  
  else 
    {
    Serial.println("DS1302 read error!  Please check the circuitry.");
    Serial.println();
    delay(9000);
    }
 }   
//**********************************


//**********************************
void Modeswitch_ausgabe()
{
  if(Modeschalter_anzeigen == 1 && excel_output == 0)
  {
  Serial.print("Modus:"); 
  Serial.println(Mode,2); 
  Stars();
  delay(print_delay);
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
  Serial.print("Befeuchtung  -> Relait 1 Power: ");
  Serial.println(relait1check);
  Serial.print("Bewaesserung -> Relait 2 Power: ");
  Serial.println(relait2check);
  Serial.print("Heizung      -> Relait 3 Power: ");
  Serial.println(relait3check);
  Serial.print("Abluft       -> Relait 4 Power: ");
  Serial.println(relait4check);
  Stars();
  delay(print_delay);
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
    Serial.print("Luftfeuchtewert: ");
    Serial.println(feuchtewert);
    }
  
    if(Temperatur_regulieren == 1)
    {
    Serial.print("Temperaturwert: ");
    Serial.println(temperaturwert);
    }

    if(Abluft_regulieren == 1)
    {
    Serial.print("Abluftwert: ");
    Serial.println(air_zaehler);
    }
    
   Serial.print("Schaltvorgang bei +-"); 
   Serial.println(Messdurchgaenge);
   Stars();
   delay(print_delay);
   }
  } 
//**********************************



//**********************************
void LuftfeuchteStatus_ausgabe()
{
  if (h <= minLuftfeuchte || h >= maxLuftfeuchte) //Wenn die Luftfeuchte unter minLuftfeuchte oder über maxLuftfeuchte
  {
    led_hum_critical();            //Schalte LedPin 1 ein
    
    if(Luftfeuchte_anzeigen ==1 && excel_output == 0)
    {
    Serial.println("H KRITISCH!");
    delay(print_delay);                            //Verzögerung 1000cycles - ca. 0,5 Sekunden
    }
    
  }
  
   else //ansonsten
    {
      if(Luftfeuchte_anzeigen ==1 && excel_output == 0)
      {  
      Serial.println("H OK ^^");
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
    Serial.println("T KRITISCH!"); 
    delay(print_delay);
    }
  } 
 
 else
    {
     if(excel_output == 0)
     { 
     Serial.println("T OK ^^"); 
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
  Serial.print("Luftfeuchitgkeit: ");
  Serial.print(h);
  Serial.println(" %\t");
  Stars();
  delay(print_delay);
  }
  
  if(Temperatur_anzeigen == 1 && excel_output == 0)
  {
  Serial.print("Temperatur: ");
  Serial.print(t);
  Serial.println(" *C ");
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
  Serial.println("Bewaesserung wird zur gewaehlten Stunde aktiviert.");
  Serial.print(water_applied);
  Serial.println(" ins EEPROM geschrieben, Bewaesserung moeglich");
  Serial.println("Warte 1 Minute");
  }
  
  int count_reset_time = 0;
  while (count_reset_time <= 10)
  {
    count_reset_time++;   
    delay(6500);
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
      Serial.print("Relait 2 Power: ");
      Serial.println(relait2check);
      Serial.print("Bewaesserung laeuft fuer ");
      Serial.print(flush_time_secounds);
      Serial.println(" Sekunden");
      }
      
      int count_watercontrol_time = 0;
      while (count_watercontrol_time <= 10)
      {
      count_watercontrol_time++;  
        if(excel_output == 0)
        {
        delay(flush_time_secounds*100); //Verzögerung für ein 10tel der angegebenen Zeit in Sekunden   
        Serial.print("*");
        }
      }

      if(Wasserstand_anzeigen == 1 && excel_output == 0)
      {
        Serial.println("^^");
      }
}

void watercontrol_active_ausgabe2()
{
      if(Wasserstand_anzeigen == 1 && excel_output == 0)
      {
      Serial.println("BW abgeschlossen.");
      Serial.print(water_applied);
      Serial.println(" ins EEPROM geschrieben");
      }
}

//**********************************
void bewaesserung_status_ausgabe()
  {
    
    Serial.print("Bewaesserung ausgefuehrt: "); 
    Serial.println(water_applied); 
    Stars();
  }


//**********************************
void water_level_ausgabe()
{
  if(Wasserstand_anzeigen == 1 && excel_output == 0)
    {
     
    Serial.println("Wasserstand krit");
    Stars();
    delay(print_delay);
    }
}

void water_level_ausgabe2()    
{
      if(Wasserstand_anzeigen == 1 && excel_output == 0)
      {
          
      Serial.println("Wasserstand OK");
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
      Serial.print("Relait 2 Power: ");
      Serial.println(relait2check);
      Serial.print("Bewaesserung laeuft");
      Serial.print(flush_time_secounds);
      Serial.println(" Sekunden");
      }
      
 
 int flush_time_counter = 0;
 while(flush_time_counter <= 10)
 {
 flush_time_counter++; 
 Serial.print("*");
 delay(flush_time_secounds*100);
 }
 Serial.println("^^");
}

void flushcontrol_active_ausgabe2()
{
      if(excel_output == 0)
      {
      Serial.println("Bewaesserung abgeschlossen.");          
      }
}
//**********************************



//**********************************
void Heizung_ausgabe()
{
  if(Schaltvorgang_anzeigen == 1 && excel_output == 0)
  {
  Stars();
  Serial.println("Heizung aktiv");
  Stars();
  delay(print_delay);
  }
}

void Heizung_ausgabe2()
{
  if(Schaltvorgang_anzeigen == 1 && excel_output == 0)
  {
  Stars();
  Serial.println("Heizung inaktiv");
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
    Serial.println("Bin am befeuchten!");
    Stars();
    delay(print_delay);
    }
}

void humidity_balancer_ausgabe2()
{
    if(Schaltvorgang_anzeigen == 1 && excel_output == 0)
    { 
    Serial.println("keine Befeuchtung");                              
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
      Serial.println("Luftzirkulation aktiviert" );
      Stars();
      delay(print_delay);
     }
}

void air_ausgabe2()
{
  if(Schaltvorgang_anzeigen == 1 && excel_output == 0)
    {
    Stars();  
    Serial.println("Luftzirkulation deaktiviert" );  
    Stars();
    delay(print_delay);
    }
}

void air_refresh_ausgabe()
{
 int air_refresh_counter = 0;
 while(air_refresh_counter <= 10)
 {
 air_refresh_counter++; 
 Serial.print("*");
 delay(air_refresh_secound*100);
 } 
}
//**********************************



//**********************************

//**********************************
void water_cycles_ausgabe()
{
 Serial.print("Durchgang ");
 Serial.print(water_cycles_done);
 Serial.print(" von "); 
}


//**********************************

//**********************************



//**********************************

//**********************************



//**********************************

//**********************************





//**********************************
void CSVausgabe()
{

  if(excel_output == 1)
  {
   Serial.print("Temperatur: ");
   Serial.print(t); 
   Serial.print(",");
   Serial.print("Luftfeuchtigkeit: ");
   Serial.print(h);
   Serial.print(",");
   Serial.print("Wasserstand: ");
   Serial.print(water_check);
   Serial.print(",");
   Serial.print("Relait 1 Power: ");
   Serial.print(relait1check);
   Serial.print(",");
   Serial.print("Relait 2 Power: ");
   Serial.print(relait2check);
   Serial.print(",");
   Serial.print("Relait 3 Power: ");
   Serial.print(relait3check);
   Serial.print(",");
   Serial.print("Relait 4 Power: ");
   Serial.print(relait4check);
   Serial.print(",");

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
  } 
}
//**********************************  
