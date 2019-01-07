# box
a box for you and me because i never cooperate without my team
-------------------
If you want to use the RTC Module, you have to run setserial.ino one time. Here you can set the date via serialmonitor. Read the header information in setserial for more info ;) Btw. the pins are the same like in the main code. 

You will need these libraries:

Adafruit_Sensor-master https://codeload.github.com/adafruit/Adafruit_Sensor/zip/master

DHT-sensor-library-master https://codeload.github.com/adafruit/DHT-sensor-library/zip/master

Streaming library http://arduiniana.org/Streaming/Streaming5.zip

Time library https://codeload.github.com/PaulStoffregen/Time/zip/v1.5

DS1302RTC library http://playground.arduino.cc/uploads/Main/DS1302RTC.zip

Sensor:
DHT Series (DHT11, DHT21, DHT22)

Clock Module:
DS1302


GUI:
Node Red and these modules

npm install node-red-node-openweathermap //if you want some weather report

npm install node-red-node-random

npm install node-red-node-arduino

npm install node-red-node-smooth

npm install node-red-contrib-timeout
