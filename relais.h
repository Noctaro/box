#ifndef relais_h
#define relais_h
void relais_init()
{
  //PIN Modus festlegen  
  pinMode(relaitPin1, OUTPUT); //Setze den Steuerpin fÃ¼r Relait 1 als Ausgang
  pinMode(relaitPin2, OUTPUT); //Setze den Steuerpin fÃ¼r Relait 2 als Ausgang
  pinMode(relaitPin3, OUTPUT); //Setze den Steuerpin fÃ¼r Relait 3 als Ausgang
  pinMode(relaitPin4, OUTPUT); //Setze den Steuerpin fÃ¼r Relait 4 als Ausgang
  
  digitalWrite(relaitPin1, LOW);         //Schalte relaitPin1 aus 
  digitalWrite(relaitPin2, LOW);         //Schalte relaitPin2 aus
  digitalWrite(relaitPin3, LOW);         //Schalte relaitPin3 aus
  digitalWrite(relaitPin4, LOW);         //Schalte relaitPin4 aus
}



#endif
