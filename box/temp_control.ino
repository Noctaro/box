void heat_control()
{
 
 if (t <= minTemperatur && t < optimaleTemperatur)
 {
 Serial.println("Heizung aktiv*");
 digitalWrite(relaitPin3, HIGH);         //Schalte relaitPin3 ein      
 //relait3check = 1;
 boolean heatup =1;
 delay(100);
 }

 else
 {
 Serial.println("Heizung inaktiv*");
 digitalWrite(relaitPin3, LOW);         //Schalte relaitPin3 aus 
 //relait3check = 0;    
 delay(100);
 }

 
}

