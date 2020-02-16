
/*  * * * * * * * * * * * * * * * * * * * * * * * * * * *
 Code for ArduController by Ettore Gallina
 http://www.gallinaettore.com
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */



#ifndef ArduControllerUtils_h
#define ArduControllerUtils_h

#include "Arduino.h"
#include <ArduControllerBundle.h>

#define CONTROLLER_TYPE_ETHERNET 0
#define CONTROLLER_TYPE_BLUETOOTH 1

#define CUSTOM_WIDGET_1 1
#define CUSTOM_WIDGET_2 2 
#define CUSTOM_WIDGET_3 3
#define CUSTOM_WIDGET_4 4
#define CUSTOM_WIDGET_5 5
#define CUSTOM_WIDGET_6 6



class ArduControllerUtils {
   public:
      ArduControllerUtils(uint8_t controllerType);
	  void updateReceivedString(String receivedString);
	  void addCharToReceivedString(char c);
	  void updateResString(String resString);
	  String getResString();
	  void manageReceivedString();
	  void reserveBluetoothPin(uint8_t rxPin, uint8_t txPin);
	  void putBundleValues(uint8_t idBundle, float v1, float v2, float v3, float v4, float v5, float v6);
   private:
	  uint8_t _controllerType;
	  String _receivedString;
	  String _resString;
	  int8_t _btTxPin, _btRxPin;
	  void manageInfoRequest();
	  void manageMultipleCommands();
	  String manageCommand(String command);
	  String pinListPwm(uint8_t pins);
	  int outputPinState(uint8_t pin);
	  int pwmState(uint8_t pin);
	  String digitalStateMessage(uint8_t pin);
	  String retMessage(String operation, uint8_t pin, float value);
	  String pwmStateMessage(uint8_t pin);
	  ArduControllerBundle _bundle1, _bundle2, _bundle3, _bundle4, _bundle5, _bundle6;
	  String bundleString(uint8_t idBundle);
	  String ArduControllerUtils::getArduinoName();
};
#endif