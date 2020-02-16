
/*  * * * * * * * * * * * * * * * * * * * * * * * * * * *
 Code for ArduController by Ettore Gallina
 http://www.gallinaettore.com
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */



#ifndef ArduControllerEthernet_h
#define ArduControllerEthernet_h

#include "Arduino.h"
#include <EthernetServer.h>
#include <ArduControllerUtils.h>



class ArduControllerEthernet{
   public:
      ArduControllerEthernet(uint8_t *mac, uint8_t *ip, uint8_t *gateway, uint8_t *subnet, uint16_t port);
	  void begin();
	  void communication();
	  void putCustomWidgetValues(uint8_t widgetId, float value1, float value2, float value3, float value4, float value5, float value6);
   private:
      EthernetServer _server;
	  ArduControllerUtils _utils;
	  uint8_t *_mac, *_ip, *_gateway, *_subnet;	  
};
#endif