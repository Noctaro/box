
//*********************************************************************************************************
//Bewässerung
//*********************************************************************************************************

//*********************************************************************************************************
//Bewässerung für die kommende Stunde wieder aktivieren
//*********************************************************************************************************
void watercontrol_reset() 
{ //Bewässerung ab Minute 59 wieder ermöglichen.
       Serial.println("Bewaesserung wird zur naechsten gewaehlten Stunde aktiviert.");
       water_applied = 0;
       int eeprom_watered = water_applied;
       EEPROM.write(eeprom_address_watered, eeprom_watered);
       Serial.print(eeprom_watered);
       Serial.println(" ins EEPROM geschrieben um die naechste Bewaesserung zu ermoeglichen");
       Serial.println("Warte 1 Minute bis zum naechsten Zyklus");
       delay(65000);
}

//*********************************************************************************************************
//Der Schaltvorgang für die Bewässerung falls eine für die Bewässerung gewählte Stunde eintritt.
//*********************************************************************************************************
void watercontrol_active() 
{
      //Bewässerung aktivieren  
      relait2check = 1;
      digitalWrite(relaitPin2, HIGH);           //Schalte Relait Pin 2 ein
      Serial.print("Relait 2 Power: ");
      Serial.println(relait2check);
      Serial.print("Bewaesserung laeuft fuer ");
      Serial.print(flush_time_secounds);
      Serial.println(" Sekunden");
      delay(flush_time_secounds*1000);                            //Verzögerung ca 30 Sekunden   

      //Bewässerung deaktivieren
      Serial.println("Bewaesserung abgeschlossen");
      digitalWrite(relaitPin2, LOW);           //Schalte Relait Pin 2 aus
      relait2check = 0;
      Serial.println("Bewaesserung wird fuer die aktuelle Stunde deaktiviert.");
      water_applied = 1;
      EEPROM.write(eeprom_address_watered, water_applied); 
      Serial.print(water_applied);
      Serial.println(" ins EEPROM geschrieben");
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
  digitalWrite(LedPin1,HIGH);
  delay(40);
  Serial.println("Wasserstand fuer Bewaesserung kritisch!!");
  }
  
  else
        {
        Serial.println("Wasserstand fuer Bewaesserung OK!"); 
        digitalWrite(LedPin1,LOW);
        }  
}
//*********************************************************************************************************
