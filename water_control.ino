
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
      relait2check = 1;      
      digitalWrite(relaitPin2, HIGH);           //Schalte Relait Pin 2 ein
      watercontrol_active_ausgabe();
      
      //BewÃ¤sserung deaktivieren
      digitalWrite(relaitPin2, LOW);           //Schalte Relait Pin 2 aus
      relait2check = 0;
      Serial.println(relait2check);


      
      delay(1000);
}

//*********************************************************************************************************
//Wasser Sensor auslesen
//*********************************************************************************************************
/* The water sensor will switch LOW when water is detected.
           Get the Arduino to illuminate the LED when no water is detected, and switch off when water is present */
         
void water_level()
{
 if(digitalRead(Water_Sensor) == HIGH)
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
      relait2check = 1;
      digitalWrite(relaitPin2, HIGH);           //Schalte Relait Pin 2 ein
      flushcontrol_active_ausgabe();
      

      //BewÃ¤sserung deaktivieren
      
      digitalWrite(relaitPin2, LOW);           //Schalte Relait Pin 2 aus
      relait2check = 0;
      water_applied = 1;

      flushcontrol_active_ausgabe2();

}