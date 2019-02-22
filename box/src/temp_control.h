#ifndef temp_control_h
#define temp_control_h
//**************************************************
//TEMPERATURE CONTROL
//If all measuring loops are done, turn on heater while min temperature or less is reached. If temperature has reached optimum or above, turn off heater.
//We take samples of the temperature each loop and add or substract +-1 to "temperaturwert" depending on "optimaleTemperatur". So glitches on the sensor will not cause
//instant switching. You may adjust the amount of samples taken before switching in "mode_settings_box" file.
//**************************************************

void heat_control();
#endif
