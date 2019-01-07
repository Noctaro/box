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

-------------------
# GUI:
The interface is based on node-red. So you will need a computer, raspberry or similar to run the GUI on.
Your Arduino must be connected via USB port to the mentioned machine.

-------------------
You will need:

-Node Red 

Best to read the documentation

https://nodered.org/docs/getting-started/installation


Additional Node Red modules can be installed with these commands:

-Node arduino (Allows your node red interface to communicate with the arduino)

npm install node-red-node-arduino


-Node smooth (Used to smooth Data in weather report)

npm install node-red-node-smooth


-Open Weather for weather report. (You need an open weather id for this)

npm install node-red-node-openweathermap 


-Node random (Currently only used for testing, you might not need it)

npm install node-red-node-random

-Node contrib timeout (Used for a watchdog, it will restart your serialport if timed out. This helps if the arduino froze.)

npm install node-red-contrib-timeout


