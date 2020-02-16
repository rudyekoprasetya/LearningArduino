
/*  * * * * * * * * * * * * * * * * * * * * * * * * * * *
 Code for ArduController by Ettore Gallina
 http://www.gallinaettore.com
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#include "Arduino.h"
#include "ArduControllerBundle.h"





ArduControllerBundle::ArduControllerBundle() {
	
}


void ArduControllerBundle::putValues(float value1, float value2, float value3, float value4, float value5, float value6){
	_value1 = value1;
	_value2 = value2;
	_value3 = value3;
	_value4 = value4;
	_value5 = value5;
	_value6 = value6;
}


String ArduControllerBundle::toString(){
	String retString = (String)"" + _value1 + "+" + _value2 + "+" + _value3 + "+" + _value4 + "+" + _value5 + "+" + _value6;
    return retString;
}



