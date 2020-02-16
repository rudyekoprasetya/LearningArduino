
/*  * * * * * * * * * * * * * * * * * * * * * * * * * * *
 Code for ArduController by Ettore Gallina
 http://www.gallinaettore.com
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */



#include "Arduino.h"
#include "ArduControllerUtils.h"

#include <ArduControllerDHT.h>
#include <ArduControllerDallasTemperature.h>
#include <ArduControllerOneWire.h>

#define LIB_VERSION 1



#ifndef analogInputToDigitalPin
uint8_t analogInputToDigitalPin(uint8_t i){
    switch(i){
        case 0: return A0;
        case 1: return A1;
        case 2: return A2;
        case 3: return A3;
        case 4: return A4;
        case 5: return A5;
		#ifdef PIN_A6
        case 6: return A6;
		#endif
		#ifdef PIN_A7
        case 7: return A7;
		#endif
		#ifdef PIN_A8
        case 8: return A8;
		#endif
		#ifdef PIN_A9
        case 9: return A9;
		#endif
		#ifdef PIN_A10
        case 10: return A10;
		#endif
		#ifdef PIN_A11
        case 11: return A11;
		#endif
		#ifdef PIN_A12
        case 12: return A12;
		#endif
		#ifdef PIN_A13
        case 13: return A13;
		#endif
		#ifdef PIN_A14
        case 14: return A14;
		#endif
		#ifdef PIN_A15
        case 15: return A15;
		#endif
		#ifdef PIN_A16    
        case 16: return A16;
		#endif
		default: return -1;
    }
}
#endif






ArduControllerUtils::ArduControllerUtils(uint8_t controllerType) {
	_controllerType = controllerType;
	_btRxPin = -1;
	_btTxPin = -1;
}


void ArduControllerUtils::updateReceivedString(String receivedString) {
	_receivedString = receivedString;
}


void ArduControllerUtils::addCharToReceivedString(char c) {
	_receivedString += c;
}


void ArduControllerUtils::updateResString(String resString) {
	_resString = resString;
}


String ArduControllerUtils::getResString() {
	return _resString;
}


void ArduControllerUtils::manageReceivedString() {
  Serial.println((String)"Received string: " + _receivedString);
  if(_receivedString != ""){
	if(_receivedString.startsWith("?")){
	  manageInfoRequest();
	} else {
	  manageMultipleCommands();
	}
	_receivedString = "";
  }
}


void ArduControllerUtils::manageInfoRequest() {
  if(_receivedString == "?gen"){
    uint8_t digitalPins = NUM_DIGITAL_PINS - NUM_ANALOG_INPUTS;
    String pwm_list = pinListPwm(digitalPins);
    uint8_t isEthernet = 0;
    if(_controllerType == CONTROLLER_TYPE_ETHERNET){
		isEthernet = 1;
	}
	//lib version, digital pins, anolog pins, bluetooth tx pin, bluetooth rx pin, pwm pin list, is ethernet, arduino name
    _resString = ((String)"?" + LIB_VERSION + "+" + NUM_ANALOG_INPUTS + "+" + digitalPins + "+" + _btTxPin + "+" + _btRxPin + "+" + pwm_list + "+" + isEthernet + "+" + getArduinoName());
  }
}


String ArduControllerUtils::pinListPwm(uint8_t pins){
  String list = "";
  for(uint8_t i=0; i < pins; i++){
    if(digitalPinHasPWM(i)){
      list += i;
      list += ",";
    }
  }
  return list;
}


void ArduControllerUtils::manageMultipleCommands(){
  String remainString = _receivedString;
  while(remainString.length() > 0){
    //Serial.println((String)"Remain: " + remainString);
    int indexSplit = remainString.indexOf("_");
    if(indexSplit == -1){
      Serial.println((String)"Error... String not contais '_': " + remainString);
      //_resString = "!"; //error notify
      break;
    }
    String singleCommand = remainString.substring(0, indexSplit);
    remainString = remainString.substring(indexSplit+1, remainString.length());
    //Serial.println((String)"Single command: " + singleCommand);
    String result = manageCommand(singleCommand);
    if(result != ""){
      _resString += (result + "_");
    }
  }
  if(_resString == ""){
    _resString = "!"; //error notify
  }
}


String ArduControllerUtils::manageCommand(String command){
  if(command.length() != 9) {
    return "";
  }
  String operation = command.substring(0,2);
  String pinString = command.substring(2,5);
  int pinNumber = pinString.toInt();
  String valueString = command.substring(5,9);
  int valueNumber = valueString.toInt();


  if(operation == "do"){
    //digital output
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, valueNumber);
    return digitalStateMessage(pinNumber);
  } else if(operation == "pb"){
    //push button
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, HIGH);
    delay(250);
    digitalWrite(pinNumber, LOW);
    return digitalStateMessage(pinNumber);
  } else if (operation == "pw"){
    //digital PWM
    pinMode(pinNumber, OUTPUT);
    analogWrite(pinNumber, valueNumber);
    return pwmStateMessage(pinNumber);
  } else if(operation == "di"){
    //digital input
    pinMode(pinNumber, INPUT);
    int reading = digitalRead(pinNumber);
    return retMessage(operation, pinNumber, reading);
  } else if(operation == "ai"){
    //analog input
	uint8_t digitalPin = analogInputToDigitalPin(pinNumber);
    pinMode(digitalPin, INPUT);
    int reading = analogRead(digitalPin);
    return retMessage(operation, pinNumber, reading);
  } else if(operation == "ds"){
	//digital state  
    return digitalStateMessage(pinNumber);   
  } else if (operation == "ps"){
	//pwm state  
    return pwmStateMessage(pinNumber);
  } else if (operation == "ht"){
	//DHT temperature
    ArduControllerDHT dht(pinNumber, valueNumber);
    dht.begin();
    float t = dht.readTemperature();
    return retMessage(operation, pinNumber, t);
  } else if (operation == "hu"){
	//DHT humidity  
    ArduControllerDHT dht(pinNumber, valueNumber);
    dht.begin();
    float h = dht.readHumidity();
    return retMessage(operation, pinNumber, h);
  } else if (operation == "da"){
	//DS18B20  
    ArduControllerOneWire oneWire(pinNumber);
    ArduControllerDallasTemperature dallas(&oneWire);
    dallas.begin();
    dallas.requestTemperatures();
    float t = dallas.getTempCByIndex(0);
    return retMessage(operation, pinNumber, t);
  } else if (operation == "cu"){
	//Custom widget (pin number used as bundle number / widget id)
	String retMessage = (String)"cu" + "+" + pinNumber + "+" + bundleString(pinNumber);
	return retMessage;
  } else {
    return "";
  }
}


int ArduControllerUtils::outputPinState(uint8_t pin){
	uint8_t bit = digitalPinToBitMask(pin);
	uint8_t port = digitalPinToPort(pin);
	if (port == NOT_A_PIN) {
	  return LOW;
	}
	return (*portOutputRegister(port) & bit) ? HIGH : LOW;
}


int ArduControllerUtils::pwmState(uint8_t pin){
  unsigned long highTime = pulseIn(pin, HIGH);
  unsigned long lowTime = pulseIn(pin, LOW);
  unsigned long cycleTime = highTime + lowTime;
  int pwmState;
  if(highTime == 0 && lowTime == 0){
    int pinState = outputPinState(pin);
    pwmState = pinState == LOW ? 0 : 255;
  } else {
    float dutyCycle = (float)highTime / float(cycleTime);
    pwmState = 255 * dutyCycle;
  }
  return pwmState;
}


String ArduControllerUtils::digitalStateMessage(uint8_t pin){
  int reading = outputPinState(pin);
  return retMessage("ds", pin, reading);
}


String ArduControllerUtils::retMessage(String operation, uint8_t pin, float value){
	String retMessage = operation + "+" + pin + "+" + value;
    return retMessage;
}


String ArduControllerUtils::pwmStateMessage(uint8_t pin){
	int reading = pwmState(pin);
    return retMessage("ps", pin, reading);
}


void ArduControllerUtils::reserveBluetoothPin(uint8_t rxPin, uint8_t txPin){
	_btRxPin = rxPin;
	_btTxPin = txPin;
}


void ArduControllerUtils::putBundleValues(uint8_t idBundle, float v1, float v2, float v3, float v4, float v5, float v6){
	switch(idBundle){
		case 1:
			_bundle1 = ArduControllerBundle();
			_bundle1.putValues(v1, v2, v3, v4, v5, v6);
			break;
		case 2:
			_bundle2 = ArduControllerBundle();
			_bundle2.putValues(v1, v2, v3, v4, v5, v6);
			break;
		case 3:
			_bundle3 = ArduControllerBundle();
			_bundle3.putValues(v1, v2, v3, v4, v5, v6);
			break;
		case 4:
			_bundle4 = ArduControllerBundle();
			_bundle4.putValues(v1, v2, v3, v4, v5, v6);
			break;
		case 5:
			_bundle5 = ArduControllerBundle();
			_bundle5.putValues(v1, v2, v3, v4, v5, v6);
			break;
		case 6:
			_bundle6 = ArduControllerBundle();
			_bundle6.putValues(v1, v2, v3, v4, v5, v6);
			break;
	}
}


String ArduControllerUtils::bundleString(uint8_t idBundle){
	switch(idBundle){
		case 1:
			return _bundle1.toString();
			break;
		case 2:
			return _bundle2.toString();
			break;
		case 3:
			return _bundle3.toString();
			break;
		case 4:
			return _bundle4.toString();
			break;
		case 5:
			return _bundle5.toString();
			break;
		case 6:
			return _bundle6.toString();
			break;
	}
}

// from libraries/Firmata/Boards.h
String ArduControllerUtils::getArduinoName(){
	#if defined(__AVR_ATmega168__)
		return "Diecimila";
	#elif defined(__AVR_ATmega328P__)
		return "Uno/Duemilanove";
	#elif defined(__AVR_ATmega328__)
		return "NG";
	#elif defined(WIRING)
		return "Wiring";
	#elif defined(__AVR_ATmega8__)
		return "Old Arduino";
	#elif defined(__AVR_ATmega1280__)
		return "Mega";
	#elif defined(__AVR_ATmega2560__)
		return "Mega 2560";
	#elif defined(__SAM3X8E__)
		return "Due";
	#elif defined(ARDUINO_SAMD_MKR1000)
		return "MKR1000";
	#elif defined(ARDUINO_SAMD_MKRZERO)
		return "MKRZero";
	#elif defined(_VARIANT_ARDUINO_ZERO_)
		return "Zero";
	#elif defined(ARDUINO_PRIMO)
		return "Primo";
	#elif defined(_VARIANT_ARDUINO_101_X_)
		return "101";
	#elif defined(__AVR_AT90USB162__)
		return "Teensy 1.0";
	#elif defined(__AVR_ATmega32U4__) && defined(CORE_TEENSY)
		return "Teensy 2.0";
	#elif defined(__MK64FX512__) || defined(__MK66FX1M0__)
		return "Teensy 3.5/3.6";
	#elif defined(__MK20DX128__) || defined(__MK20DX256__)
		return "Teensy 3.0/3.1/3.2";
	#elif defined(__MKL26Z64__)
		return "Teensy-LC";
	#elif defined(__AVR_AT90USB646__) || defined(__AVR_AT90USB1286__)
		return "Teensy** 1.0/2.0";
	#elif defined(__AVR_ATmega32U4__)
		return "Leonardo";
	#elif defined(ARDUINO_LINUX)
		return "Galileo";
	#elif defined(BLE_NANO)
		return "Ble Nano";
	#elif defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644__)
		return "Sanguino";
	#elif defined(__AVR_ATmega645__)
		return "Illuminato";
	#elif defined(ARDUINO_PINOCCIO)
		return "Pinoccio";
	#else 
		return "Unknown";
	#endif
}










