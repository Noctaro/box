#ifndef global_var_h
#define global_var_h

//*********************************************************************************************************
//Globale Variablen (Bitte nicht ändern) -> Gewünschte Werte sind in mode_settings.ino anpassbar
//*********************************************************************************************************
int zaehler = 0;
//int zaehler2 = 0;
int air_zaehler = 0;

int feuchtewert = 0;
int temperaturwert = 0;


int maxTemperatur = 0;
int minTemperatur = 0;
int optimaleTemperatur = 0;

int maxLuftfeuchte = 0;
int minLuftfeuchte = 0;
int optimaleLuftfeuchte = 0;
//int dht_adjust = 10; //Sollte der DHT Sensor die Luftfeuchte falsch anzeigen, kann hier eine Anpassung vorgenommen werden.

int Messpause = 0;
int Messdurchgaenge = 0;
int Messdurchgaenge_negativ = 0;

int Absaugung_aktiv = 0;

int water_with_air = 0;

int air_refresh_secound = 0;

int dht_adjustment_h = 0;
int dht_adjustment_t = 0;

float h = 0; //Variable für aktuelle Luftfeuchte in %
float t = 0; //Variable für aktuelle Temperatur in Celsius
float f = 0; //Variable für aktuelle Temperatur in Fahrenheit
float hif = 0;
float hic = 0;

int minute_global = 0;
int hour_global = 0;
int second_global = 0;
long unix_secounds = 0;
long air_refresh_time = 0;



boolean errorcheck = 0;

int water_hour_01 = 99;
int water_hour_02 = 99;
int water_hour_03 = 99;
int water_hour_04 = 99;
int water_hour_05 = 99;
int water_hour_06 = 99;
int water_hour_07 = 99;
int water_hour_08 = 99;
int water_hour_09 = 99;
int water_hour_10 = 99;

int water_hour_cycles_01 = 1;
int water_hour_cycles_02 = 1;
int water_hour_cycles_03 = 1;
int water_hour_cycles_04 = 1;
int water_hour_cycles_05 = 1;
int water_hour_cycles_06 = 1;
int water_hour_cycles_07 = 1;
int water_hour_cycles_08 = 1;
int water_hour_cycles_09 = 1;
int water_hour_cycles_10 = 1;

int air_refresh_minute_01 = 99; //Minute zu der die Belüftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
int air_refresh_minute_02 = 99; //Minute zu der die Belüftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
int air_refresh_minute_03 = 99; //Minute zu der die Belüftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
int air_refresh_minute_04 = 99; //Minute zu der die Belüftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.

int air_refresh_times = 0;

int print_delay = 0;

//String inData = 0;

boolean water_applied = 1;
int water_cycles_done = 0;
boolean water_check = 1;

boolean hourly_air_active = 0;

long flush_time_secounds = 90;  //Dauer der Wasserzufuhr bei dem Bewässern
long flush_timer_secounds = 60; //Dauer der Pause bis zur nächsten Spülung

byte Mode = 0; 

//Box Funktionen 
boolean Luftfeuchte_regulieren = 1; 
boolean Temperatur_regulieren = 1;
boolean Abluft_regulieren = 1;
boolean Bewaesserung_regulieren = 1;

boolean Temperatur_anzeigen = 1;        //Gibt die aktuelle Temperatur am Serial Monitor aus.
boolean Luftfeuchte_anzeigen = 1;       //Gibt die aktuelle Luftfeuchte am Serial Monitor aus
boolean Wasserstand_anzeigen = 1;
boolean Relaticheck_anzeigen = 1;
boolean Messdurchgang_anzeigen = 1;
boolean TemperaturStatus_anzeigen = 1;
boolean Schaltvorgang_anzeigen = 1;
boolean Schaltzyklus_anzeigen = 1;
boolean Modeschalter_anzeigen = 1;

boolean Uhrzeit_anzeigen = 1;
boolean Wochentag_anzeigen = 1;
boolean Datum_anzeigen = 1;

boolean excel_output = 1;

#endif
