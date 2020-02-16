
/*  * * * * * * * * * * * * * * * * * * * * * * * * * * *
 Code for ArduController by Ettore Gallina
 http://www.gallinaettore.com
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#include "Arduino.h"
#include "StateOfLife.h"



StateOfLife::StateOfLife(uint8_t pin){
	_pin = pin;
}


void StateOfLife::pulse(){
  unsigned long now = millis();
  if(now - _lastLifeStateUpdate > 300){
    pinMode(_pin, OUTPUT);
    if(_lifePinState == LOW){
      digitalWrite(_pin, HIGH);
	  _lifePinState = HIGH;
    } else {
      digitalWrite(_pin, LOW);
	  _lifePinState = LOW;
    }
    _lastLifeStateUpdate = now;
  }
}







