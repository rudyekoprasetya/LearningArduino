
/*  * * * * * * * * * * * * * * * * * * * * * * * * * * *
 Code for ArduController by Ettore Gallina
 http://www.gallinaettore.com
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */



#ifndef ArduControllerBluetooth_h
#define ArduControllerBluetooth_h

#include "Arduino.h"
#include <ArduControllerUtils.h>
#include <SoftwareSerial.h>


class ArduControllerBluetooth{
   public:
      ArduControllerBluetooth(uint8_t rxPin, uint8_t txPin, int baudRate);
	  void begin();
	  void communication();
	  void sendATCommand(String command);
	  void putCustomWidgetValues(uint8_t widgetId, float value1, float value2, float value3, float value4, float value5, float value6);
   private:
      SoftwareSerial _bluetooth;
	  ArduControllerUtils _utils;
	  int _baudRate;
};
#endif