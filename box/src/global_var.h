#ifndef global_var_h
#define global_var_h

//*********************************************************************************************************
//Globale Variablen (Bitte nicht Ã¤ndern) -> GewÃ¼nschte Werte sind in mode_settings.ino anpassbar
//*********************************************************************************************************

//*********************************************************************************************************
//Globale Variablen (Bitte nicht Ã¤ndern) -> GewÃ¼nschte Werte sind in mode_settings.ino anpassbar
//*********************************************************************************************************


int zaehler;
//int zaehler2;
int air_zaehler;

int feuchtewert;
int temperaturwert;


int maxTemperatur;
int minTemperatur;
int optimaleTemperatur;

int maxLuftfeuchte;
int minLuftfeuchte;
int optimaleLuftfeuchte;
//int dht_adjust = 10; //Sollte der DHT Sensor die Luftfeuchte falsch anzeigen, kann hier eine Anpassung vorgenommen werden.

int Messpause;
int Messdurchgaenge;
int Messdurchgaenge_negativ;

int Absaugung_aktiv;

int water_with_air;

int air_refresh_second;

int dht_adjustment_h;
int dht_adjustment_t;


float h; //Variable fÃ¼r aktuelle Luftfeuchte in %
float t; //Variable fÃ¼r aktuelle Temperatur in Celsius
float f; //Variable fÃ¼r aktuelle Temperatur in Fahrenheit
float hif;
float hic;

bool heat_water_compensation;
bool h_w_compenstation_active;


int minute_global;
int hour_global;
int second_global;
long unix_seconds;
long air_refresh_time;



bool errorcheck;



int water_hour_01;
int water_hour_02;
int water_hour_03;
int water_hour_04;
int water_hour_05;
int water_hour_06;
int water_hour_07;
int water_hour_08;
int water_hour_09;
int water_hour_10;

int water_hour_cycles_01;
int water_hour_cycles_02;
int water_hour_cycles_03;
int water_hour_cycles_04;
int water_hour_cycles_05;
int water_hour_cycles_06;
int water_hour_cycles_07;
int water_hour_cycles_08;
int water_hour_cycles_09;
int water_hour_cycles_10;

int air_refresh_minute_01; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
int air_refresh_minute_02; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
int air_refresh_minute_03; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
int air_refresh_minute_04; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.

int air_refresh_times;

//Wasserstand
int water_lev;
int water_check_counter;
int water_check_counter_cycles;

//Serial output delay
int print_delay;



bool water_applied;
int water_cycles_done;
bool water_check;

bool hourly_air_active;

long flush_time_seconds;  //Dauer der Wasserzufuhr bei dem BewÃ¤ssern
long flush_timer_seconds; //Dauer der Pause bis zur nÃ¤chsten SpÃ¼lung

int Mode;

//Box Funktionen
bool Luftfeuchte_regulieren;
bool Temperatur_regulieren;
bool Abluft_regulieren;
bool Bewaesserung_regulieren;

bool Temperatur_anzeigen;        //Gibt die aktuelle Temperatur am Serial Monitor aus.
bool Luftfeuchte_anzeigen;       //Gibt die aktuelle Luftfeuchte am Serial Monitor aus
bool Wasserstand_anzeigen;
bool Relaticheck_anzeigen;
bool Messdurchgang_anzeigen;
bool TemperaturStatus_anzeigen;
bool Schaltvorgang_anzeigen;
bool Schaltzyklus_anzeigen;
bool Modeschalter_anzeigen;

bool Uhrzeit_anzeigen;
bool Wochentag_anzeigen;
bool Datum_anzeigen;

bool excel_output;

bool tag_active;
bool tag_active_boot;
bool tag_active_start;

int sonnenaufgang;
int sonnenuntergang;



//GUI EINGABE
int gui_input_01;
int gui_input_02;
int gui_input_03;
int gui_input_04;

int gui_form_01;
int gui_form_02;
int gui_form_03;


int gui_opt_temp;
int gui_min_temp;
int gui_max_temp;
int gui_opt_hum;
int gui_min_hum;
int gui_max_hum;

int eeprom_address_watered;

void load_variables();

//*********************************************************************************************************
//PIN settings - Watersensor (YL-69 + YL-39 sensor combo)
//*********************************************************************************************************
#define Water_Sensor A3 //Define the analog input pin
#define Water_Sensor_Power 2 //Define the power pin
//*********************************************************************************************************

#endif
