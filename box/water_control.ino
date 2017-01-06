
//*********************************************************************************************************
//Bewässerung
//*********************************************************************************************************

//*********************************************************************************************************
//Bewässerung für die kommende Stunde wieder aktivieren
//*********************************************************************************************************
void watercontrol_reset() 
{      
       //Bewässerung ab Minute 59 wieder ermöglichen.
       water_applied = 0;    
       EEPROM.write(eeprom_address_watered, water_applied);
       watercontrol_reset_ausgabe();
}

//*********************************************************************************************************
//Der Schaltvorgang für die Bewässerung falls eine für die Bewässerung gewählte Stunde eintritt.
//*********************************************************************************************************
void watercontrol_active() 
{
      //Bewässerung aktivieren  
      relait2check = 1;
      watercontrol_active_ausgabe();
      digitalWrite(relaitPin2, HIGH);           //Schalte Relait Pin 2 ein
      
      //Bewässerung deaktivieren
      digitalWrite(relaitPin2, LOW);           //Schalte Relait Pin 2 aus
      relait2check = 0;
      water_applied = 1;
      EEPROM.write(eeprom_address_watered, water_applied); 
      watercontrol_active_ausgabe2();
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
      //Bewässerung aktivieren  
      relait2check = 1;
      digitalWrite(relaitPin2, HIGH);           //Schalte Relait Pin 2 ein
      flushcontrol_active_ausgabe();
      

      //Bewässerung deaktivieren
      
      digitalWrite(relaitPin2, LOW);           //Schalte Relait Pin 2 aus
      relait2check = 0;
      water_applied = 1;

      flushcontrol_active_ausgabe2();

}
