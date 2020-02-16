
/*  * * * * * * * * * * * * * * * * * * * * * * * * * * *
 Code for ArduController by Ettore Gallina
 http://www.gallinaettore.com
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */



#ifndef StateOfLife_h
#define StateOfLife_h

#include "Arduino.h"



class StateOfLife {
   public:
      StateOfLife(uint8_t pin);
	  void pulse();
   private:
      unsigned long _lastLifeStateUpdate;
	  uint8_t _pin;
      uint8_t _lifePinState;
};
#endif