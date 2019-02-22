#ifndef led_signal_h
#define led_signal_h


//*********************************************************************************************************
//PIN fÃ¼r die Statusled
//*********************************************************************************************************
#define LedPin1 13     //Namen fuer den Ledpin
//*********************************************************************************************************

void led_cycle_check();
void led_temp_critical();
void led_hum_critical();
void led_water_check();
void led_blinker();

#endif
