
/*  * * * * * * * * * * * * * * * * * * * * * * * * * * *
 Code for ArduController by Ettore Gallina
 http://www.gallinaettore.com
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#include "Arduino.h"
#include "ArduControllerBluetooth.h"
#include "ArduControllerUtils.h"
#include <SoftwareSerial.h>



ArduControllerBluetooth::ArduControllerBluetooth(uint8_t rxPin, uint8_t txPin, int baudRate) : _bluetooth(rxPin, txPin), _utils(CONTROLLER_TYPE_BLUETOOTH) {
	_baudRate = baudRate;
	_utils.reserveBluetoothPin(rxPin, txPin);
}


void ArduControllerBluetooth::begin(){
	_bluetooth.begin(9600); //set baud rate
	Serial.begin(9600); //set baud rate
	/*
	On boards with a direct USB connection, such as the Leonardo or the Yùn it waits for an active serial connection to be established by the PC 
	(i.e., for the serial port to be opened by a piece of software).
	When you open the serial port of a board like the Uno or Mega the whole board usually resets*, so opening the serial port allows you to see 
	the first bits of the serial data. On the Leonardo etc it doesn't reset when you open the serial, so any serial output during the setup() 
	function would be missed. Adding that line makes the board pause until you open the serial port, so you get to see that initial bit of data.
	*/
	/*while (!Serial) {
		; // wait for serial port to connect. Needed for native USB port only
	}*/
}


void ArduControllerBluetooth::communication() {
	bool serialRead = false;
	
	while (_bluetooth.available()) {
		delay(1);
		if(_bluetooth.available() > 0){
			char c = char(_bluetooth.read());
			if (c == '?') {
			  _utils.updateReceivedString(""); //clear string after AT commands
			} 
			if (c == '~') {
			  serialRead = true;
			  break;
			} 
			_utils.addCharToReceivedString(c);
		}
	}

	if(serialRead){
		_utils.manageReceivedString();
		_bluetooth.print(_utils.getResString());
		_bluetooth.print("~");
		Serial.println((String)"Return: " + _utils.getResString());
		_utils.updateResString("");
		serialRead = false;
	}
}


void ArduControllerBluetooth::sendATCommand(String command){
	_bluetooth.println(command);
}


void ArduControllerBluetooth::putCustomWidgetValues(uint8_t widgetId, float value1, float value2, float value3, float value4, float value5, float value6){
	_utils.putBundleValues(widgetId, value1, value2, value3, value4, value5, value6);
}






