
#ifndef water_control_h
#define water_control_h
//*********************************************************************************************************
//BewÃ¤sserung
//*********************************************************************************************************

//*********************************************************************************************************
//BewÃ¤sserung fÃ¼r die kommende Stunde wieder aktivieren
//*********************************************************************************************************
void watercontrol_reset();

//*********************************************************************************************************
//Der Schaltvorgang fÃ¼r die BewÃ¤sserung falls eine fÃ¼r die BewÃ¤sserung gewÃ¤hlte Stunde eintritt.
//*********************************************************************************************************
void watercontrol_active();

//*********************************************************************************************************
//Wasser Sensor auslesen
//*********************************************************************************************************

void water_level();
//*********************************************************************************************************


//*********************************************************************************************************
//Flush Mode
//*********************************************************************************************************
void flushcontrol_active();

#endif