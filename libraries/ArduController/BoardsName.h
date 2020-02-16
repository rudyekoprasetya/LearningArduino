
/*  * * * * * * * * * * * * * * * * * * * * * * * * * * *
 Code for ArduController by Ettore Gallina
 http://www.gallinaettore.com
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// From libraries/Firmata/Boards.h


#ifndef BoardsName_h
#define BoardsName_h

String getArduinoName(){
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