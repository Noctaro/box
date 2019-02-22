
#include "gui_comm.h"
#include "arduino.h"
#include "global_var.h"

void gui_read()
{
if (Serial.available()>0)
  // Wenn Daten empfangen wurden und zum Lesen bereitstehen
  {
  gui_input_01 = Serial.parseInt();
  gui_input_02 = Serial.parseInt();
  gui_input_03 = Serial.parseInt();
  gui_input_04 = Serial.parseInt();

  int form_trash_gui = Serial.parseInt();
  //needed for some case, gui form seems to put a 0 at the end, could not change this
  delay(500);
  }
}

void gui_apply_settings()
{

  if (gui_input_04 == 1)
    {
    optimaleTemperatur = gui_input_01;
    minTemperatur = gui_input_02;
    maxTemperatur = gui_input_03;
    gui_form_01 = 1;
    gui_input_04 = 0;
    }

    if (gui_input_04 == 2)
    {
    optimaleLuftfeuchte = gui_input_01;
    minLuftfeuchte = gui_input_02;
    maxLuftfeuchte = gui_input_03;
    gui_form_02 = 1;
    gui_input_04 = 0;
    }

    if (gui_input_04 == 3)
    {
    tag_active = gui_input_01;
    sonnenaufgang = gui_input_02;
    sonnenuntergang = gui_input_03;
    gui_form_03 = 1;
    gui_input_04 = 0;
    }
}



/*
  Serial.print(F("GUI TEMP:"));
  Serial.print(F("GUI OPT TEMP:"));
  Serial.print(gui_opt_temp);
  Serial.print(F(" GUI MIN TEMP:"));
  Serial.print(gui_min_temp);
  Serial.print(F(" GUI MAX TEMP:"));
  Serial.println(gui_max_temp);

  Serial.print(F("GUI HUM:"));
  Serial.print(F("GUI OPT HUM:"));
  Serial.print(gui_opt_hum);
  Serial.print(F(" GUI MIN HUM:"));
  Serial.print(gui_min_hum);
  Serial.print(F(" GUI MAX HUM:"));
  Serial.println(gui_max_hum);
  delay(200);  */
