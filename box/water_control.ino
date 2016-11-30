
//*********************************************************************************************************
//Bewässerung
//*********************************************************************************************************

//*********************************************************************************************************
//Bewässerung für die kommende Stunde wieder aktivieren
//*********************************************************************************************************
void watercontrol_reset() 
{      
       //Bewässerung ab Minute 59 wieder ermöglichen.
       Serial.println("Bewaesserung wird zur gewaehlten Stunde aktiviert.");
       water_applied = 0;
       EEPROM.write(eeprom_address_watered, water_applied);
       Serial.print(water_applied);
       Serial.println(" ins EEPROM geschrieben, Bewaesserung moeglich");
       Serial.println("Warte 1 Minute");
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
      Serial.println("Bewaesserung wird deaktiviert.");
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
           Get the Arduino to illuminate the LED when water is detected, and switch off when no water is present */
         
void water_level()
{
  if(digitalRead(Water_Sensor) == LOW)
  {
  digitalWrite(LedPin1,HIGH);  
  delay(100);
  digitalWrite(LedPin1, LOW);  
  delay(100);
  digitalWrite(LedPin1,HIGH);
  delay(40);
  Serial.println("Wasserstand Abwaesser OK!");
  }
  
  else
        {
        Serial.println("Wasserstand Bewaesserung KRITISCH!"); 
        digitalWrite(LedPin1,LOW);
        }  
}
//*********************************************************************************************************
