
/*  * * * * * * * * * * * * * * * * * * * * * * * * * * *
 Code for ArduController by Ettore Gallina
 http://www.gallinaettore.com
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */



#ifndef ArduControllerBundle_h
#define ArduControllerBundle_h

#include "Arduino.h"



class ArduControllerBundle{
   public:
      ArduControllerBundle();
	  void putValues(float value1, float value2, float value3, float value4, float value5, float value6);
	  String toString();
   private:
      float _value1, _value2, _value3, _value4, _value5, _value6;
};
#endif