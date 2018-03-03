#ifndef releais_h
#define relais_h

//*********************************************************************************************************
//RELAIS PINS
//*********************************************************************************************************
#define relaisPin1 5 //Definiere den Namen und Pin fÃ¼r das 1. relais - Feuchte
#define relaisPin2 6 //Definiere den Namen und Pin fÃ¼r das 2. relais - Wasser  
#define relaisPin3 7 //Definiere den Namen und Pin fÃ¼r das 3. relais - Heizung 
#define relaisPin4 4 //Definiere den Namen und Pin fÃ¼r das 4. relais - Abluft

//*********************************************************************************************************
//Relais Globale Variablen
//*********************************************************************************************************
boolean relais1check = 0;
boolean relais2check = 0;
boolean relais3check = 0;
boolean relais4check = 0;

int relais_1_guard_time = 20;
int relais_1_guard = 0;
int relais_2_guard_time = 20;
int relais_2_guard = 0;
int relais_3_guard_time = 20;
int relais_3_guard = 0;
int relais_4_guard_time = 20;
int relais_4_guard = 0;



void relaisinit()
{
  digitalWrite(relaisPin1, LOW);         //Schalte relaisPin1 aus 
  digitalWrite(relaisPin2, LOW);         //Schalte relaisPin2 aus
  digitalWrite(relaisPin3, LOW);         //Schalte relaisPin3 aus - umgekehrte schaltlogik
  digitalWrite(relaisPin4, LOW); 
  
  //PIN Modus festlegen  
  pinMode(relaisPin1, OUTPUT); //Setze den Steuerpin fÃ¼r relais 1 als Ausgang
  pinMode(relaisPin2, OUTPUT); //Setze den Steuerpin fÃ¼r relais 2 als Ausgang
  pinMode(relaisPin3, OUTPUT); //Setze den Steuerpin fÃ¼r relais 3 als Ausgang
  pinMode(relaisPin4, OUTPUT); //Setze den Steuerpin fÃ¼r relais 4 als Ausgang
}



//*********************************************************************************************************
//RELAIS 1
//*********************************************************************************************************
void relais_1_on()
{
  if(relais1check==0 && relais_1_guard <= unix_secounds+relais_1_guard_time)
  {     
  digitalWrite(relaisPin1, HIGH);
  relais1check = 1;
  relais_1_guard = unix_secounds;
  delay(1000);
  }
    
}


void relais_1_off()
{
  if(relais1check==1 && relais_1_guard <= unix_secounds+relais_1_guard_time)
  {     
  digitalWrite(relaisPin1, LOW);
  relais1check = 0;
  relais_1_guard = unix_secounds;
  delay(1000);
  }
    
}


//*********************************************************************************************************
//RELAIS 2
//*********************************************************************************************************

void relais_2_on()
{
  if(relais2check==0 && relais_2_guard <= unix_secounds+relais_2_guard_time)
  {     
  digitalWrite(relaisPin2, HIGH);
  relais2check = 1;
  relais_2_guard = unix_secounds;
  delay(1000);
  }
    
}


void relais_2_off()
{
  if(relais2check==1 && relais_2_guard <= unix_secounds+relais_2_guard_time)
  {     
  digitalWrite(relaisPin2, LOW);
  relais2check = 0;
  relais_2_guard = unix_secounds;
  delay(1000);
  }
    
}


//*********************************************************************************************************
//RELAIS 3
//*********************************************************************************************************

void relais_3_on()
{
  if(relais3check==0 && relais_3_guard <= unix_secounds+relais_3_guard_time)
  {     
  digitalWrite(relaisPin3, HIGH);
  relais3check = 1;
  relais_3_guard = unix_secounds;
  delay(1000);
  }
    
}


void relais_3_off()
{
  if(relais3check==1 && relais_3_guard <= unix_secounds+relais_3_guard_time)
  {     
  digitalWrite(relaisPin3, LOW);
  relais3check = 0;
  relais_3_guard = unix_secounds;
  delay(1000);
  }
    
}


//*********************************************************************************************************
//RELAIS 4
//*********************************************************************************************************

void relais_4_on()
{
  if(relais4check==0 && relais_4_guard <= unix_secounds+relais_4_guard_time)
  {     
  digitalWrite(relaisPin4, HIGH);
  relais4check = 1;
  relais_4_guard = unix_secounds;
  delay(1000);
  }
    
}


void relais_4_off()
{
  if(relais4check==1 && relais_4_guard <= unix_secounds+relais_4_guard_time)
  {     
  digitalWrite(relaisPin4, LOW);
  relais4check = 0;
  relais_4_guard = unix_secounds;
  delay(1000);
  }
    
}


#endif
