#ifndef releais_h
#define relais_h

//*********************************************************************************************************
//RELAIS PINS
//*********************************************************************************************************
#define relaisPin1 5 //Definiere den Namen und Pin für das 1. relais - Feuchte
#define relaisPin2 6 //Definiere den Namen und Pin für das 2. relais - Wasser  
#define relaisPin3 7 //Definiere den Namen und Pin für das 3. relais - Heizung 
#define relaisPin4 4 //Definiere den Namen und Pin für das 4. relais - Abluft

//*********************************************************************************************************
//Relais Globale Variablen
//*********************************************************************************************************
boolean relais1check = 0;
boolean relais2check = 0;
boolean relais3check = 0;
boolean relais4check = 0;

int relais_1_guard_time = 180;

void relaisinit()
{
  digitalWrite(relaisPin1, LOW);         //Schalte relaisPin1 aus 
  digitalWrite(relaisPin2, LOW);         //Schalte relaisPin2 aus
  digitalWrite(relaisPin3, LOW);         //Schalte relaisPin3 aus - umgekehrte schaltlogik
  digitalWrite(relaisPin4, LOW); 
  
  //PIN Modus festlegen  
  pinMode(relaisPin1, OUTPUT); //Setze den Steuerpin für relais 1 als Ausgang
  pinMode(relaisPin2, OUTPUT); //Setze den Steuerpin für relais 2 als Ausgang
  pinMode(relaisPin3, OUTPUT); //Setze den Steuerpin für relais 3 als Ausgang
  pinMode(relaisPin4, OUTPUT); //Setze den Steuerpin für relais 4 als Ausgang
}



//*********************************************************************************************************
//RELAIS 1
//*********************************************************************************************************
void relais_1_on()
{
  if(relais1check==0)
  {     
  digitalWrite(relaisPin1, HIGH);
  relais1check = 1;
  delay(1000);
  }
    
}


void relais_1_off()
{
  if(relais1check==1)
  {     
  digitalWrite(relaisPin1, LOW);
  relais1check = 0;
  delay(1000);
  }
    
}


//*********************************************************************************************************
//RELAIS 2
//*********************************************************************************************************

void relais_2_on()
{
  if(relais2check==0)
  {     
  digitalWrite(relaisPin2, HIGH);
  relais2check = 1;
  delay(1000);
  }
    
}


void relais_2_off()
{
  if(relais2check==1)
  {     
  digitalWrite(relaisPin2, LOW);
  relais2check = 0;
  delay(1000);
  }
    
}


//*********************************************************************************************************
//RELAIS 3
//*********************************************************************************************************

void relais_3_on()
{
  if(relais1check==0)
  {     
  digitalWrite(relaisPin3, HIGH);
  relais3check = 1;
  delay(1000);
  }
    
}


void relais_3_off()
{
  if(relais3check==1)
  {     
  digitalWrite(relaisPin3, LOW);
  relais3check = 0;
  delay(1000);
  }
    
}


//*********************************************************************************************************
//RELAIS 4
//*********************************************************************************************************

void relais_4_on()
{
  if(relais4check==0)
  {     
  digitalWrite(relaisPin4, HIGH);
  relais4check = 1;
  delay(1000);
  }
    
}


void relais_4_off()
{
  if(relais4check==1)
  {     
  digitalWrite(relaisPin4, LOW);
  relais4check = 0;
  delay(1000);
  }
    
}


#endif
