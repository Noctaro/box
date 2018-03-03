
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
        delay(flush_time_secounds*100); //VerzÃ¶gerung fÃ¼r ein 10tel der angegebenen Zeit in Sekunden   
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
/* The water sensor will switch LOW when water is detected.
           Get the Arduino to illuminate the LED when no water is detected, and switch off when water is present */
         
void water_level()
{
 if(analogRead(Water_Sensor) == HIGH)
 {
  led_water_check();
  water_check = 1;
  water_level_ausgabe();
 }
  
  else
    {
    water_check = 0;
    water_level_ausgabe2();    
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
