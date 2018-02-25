//Einmal kurz blinken um den Start eines neuen Zyklus darzustellen
  void led_cycle_check()
  { 
  digitalWrite(LedPin1, LOW);
  delay(100);
  digitalWrite(LedPin1, HIGH); 
  delay(50);
  digitalWrite(LedPin1, LOW);
  delay(100);
  }

//Temperatur, Luftfeuchtigkeit und Wasserstand werden bei kritischem Status per LED angezeigt. -> 1x Lang = Temperatur kritisch, 2x Lang = Luftfeuchtigkeit kritisch, 3x Lang = Beide Werte kritisch, 3x Kurz = Wasserstand kritisch

  void led_temp_critical()
  {
  digitalWrite(LedPin1, LOW);
  delay(100);
  digitalWrite(LedPin1, HIGH); 
  delay(500);
  digitalWrite(LedPin1, LOW);
  delay(100);  
  }

  void led_hum_critical()
  {
  digitalWrite(LedPin1, LOW);
  delay(100);
  digitalWrite(LedPin1, HIGH); 
  delay(500);
  digitalWrite(LedPin1, LOW);
  delay(100);   
  digitalWrite(LedPin1, LOW);
  delay(100);
  digitalWrite(LedPin1, HIGH); 
  delay(500);
  digitalWrite(LedPin1, LOW);
  delay(100);   
  }

  void led_water_check()
  { 
  digitalWrite(LedPin1, LOW);
  delay(100);
  digitalWrite(LedPin1, HIGH); 
  delay(100);
  digitalWrite(LedPin1, LOW);
  delay(100);
  digitalWrite(LedPin1, HIGH); 
  delay(100);
  digitalWrite(LedPin1, LOW);
  delay(100);
  digitalWrite(LedPin1, HIGH); 
  delay(100);
  digitalWrite(LedPin1, LOW);
  delay(100);
  }
  
  void led_blinker()
  {
    digitalWrite(LedPin1, HIGH);
    delay(1500);
    digitalWrite(LedPin1, LOW);
    delay(500);
  }
