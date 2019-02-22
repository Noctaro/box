#ifndef global_var_h
#define global_var_h

//*********************************************************************************************************
//Globale Variablen (Bitte nicht Ã¤ndern) -> GewÃ¼nschte Werte sind in mode_settings.ino anpassbar
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

int air_refresh_second = 0;

int dht_adjustment_h = 0;
int dht_adjustment_t = 0;


float h = 0; //Variable fÃ¼r aktuelle Luftfeuchte in %
float t = 0; //Variable fÃ¼r aktuelle Temperatur in Celsius
float f = 0; //Variable fÃ¼r aktuelle Temperatur in Fahrenheit
float hif = 0;
float hic = 0;

bool heat_water_compensation = 0;
bool h_w_compenstation_active = 0;


int minute_global = 0;
int hour_global = 0;
int second_global = 0;
long unix_seconds = 0;
long air_refresh_time = 0;



bool errorcheck = 0;



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

int air_refresh_minute_01 = 99; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
int air_refresh_minute_02 = 99; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
int air_refresh_minute_03 = 99; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.
int air_refresh_minute_04 = 99; //Minute zu der die BelÃ¼ftung eingeschaltet wird, sofern es die Luftfeuchtigkeit erlaubt.

int air_refresh_times = 0;

//Wasserstand
int water_lev = 0;
int water_check_counter = 5;
int water_check_counter_cycles = 0;

//Serial output delay
int print_delay = 0;



bool water_applied = 1;
int water_cycles_done = 0;
bool water_check = 1;

bool hourly_air_active = 0;

long flush_time_seconds = 90;  //Dauer der Wasserzufuhr bei dem BewÃ¤ssern
long flush_timer_seconds = 60; //Dauer der Pause bis zur nÃ¤chsten SpÃ¼lung

int Mode = 0;

//Box Funktionen
bool Luftfeuchte_regulieren = 1;
bool Temperatur_regulieren = 1;
bool Abluft_regulieren = 1;
bool Bewaesserung_regulieren = 1;

bool Temperatur_anzeigen = 1;        //Gibt die aktuelle Temperatur am Serial Monitor aus.
bool Luftfeuchte_anzeigen = 1;       //Gibt die aktuelle Luftfeuchte am Serial Monitor aus
bool Wasserstand_anzeigen = 1;
bool Relaticheck_anzeigen = 1;
bool Messdurchgang_anzeigen = 1;
bool TemperaturStatus_anzeigen = 1;
bool Schaltvorgang_anzeigen = 1;
bool Schaltzyklus_anzeigen = 1;
bool Modeschalter_anzeigen = 1;

bool Uhrzeit_anzeigen = 1;
bool Wochentag_anzeigen = 1;
bool Datum_anzeigen = 1;

bool excel_output = 1;

bool tag_active = 1;
bool tag_active_boot = 1;
bool tag_active_start = 1;

int sonnenaufgang = 0;
int sonnenuntergang = 0;



//GUI EINGABE
int gui_input_01 = 0;
int gui_input_02 = 0;
int gui_input_03 = 0;
int gui_input_04 = 0;

int gui_form_01 = 0;
int gui_form_02 = 0;
int gui_form_03 = 0;


int gui_opt_temp = 0;
int gui_min_temp = 0;
int gui_max_temp = 0;
int gui_opt_hum = 0;
int gui_min_hum = 0;
int gui_max_hum = 0;

int eeprom_address_watered = 0;

//*********************************************************************************************************
//PIN settings - Watersensor (YL-69 + YL-39 sensor combo)
//*********************************************************************************************************
#define Water_Sensor A3 //Define the analog input pin
#define Water_Sensor_Power 2 //Define the power pin
//*********************************************************************************************************

#endif
