
/*  * * * * * * * * * * * * * * * * * * * * * * * * * * *
 Code for ArduController by Ettore Gallina
 http://www.gallinaettore.com
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#include "Arduino.h"
#include "ArduControllerEthernet.h"
#include "ArduControllerUtils.h"
#include <Ethernet.h>
#include <SPI.h>




ArduControllerEthernet::ArduControllerEthernet(uint8_t *mac, uint8_t *ip, uint8_t *gateway, uint8_t *subnet, uint16_t port) : _server(port), _utils(CONTROLLER_TYPE_ETHERNET) {
	_mac = mac;
	_ip = ip;
	_gateway = gateway;
	_subnet = subnet;
}


void ArduControllerEthernet::begin(){
	Ethernet.begin(_mac, _ip, _gateway, _subnet);
	_server.begin();
	
	Serial.begin(9600); //set baud rate
	/*while (!Serial) {
		; // wait for serial port to connect. Needed for native USB port only
	}*/
}


void ArduControllerEthernet::communication() {
	EthernetClient client = _server.available();
    if (client) {
      String httpString;
      while (client.connected()) {   
        if (client.available()) {
          delay(1);
          char c = client.read();
          httpString += c;
          if (c == '\n') {
             client.println("HTTP/1.1 200 OK");
             client.println("Content-Type: text/html");
             client.println();
  
             int startString = httpString.indexOf("/") + 1;
             int endString = httpString.indexOf(" HTTP");
             String receivedString = httpString.substring(startString, endString);
			 _utils.updateReceivedString(receivedString);
             httpString = "";
             
             _utils.manageReceivedString();  
             client.println(_utils.getResString());
             Serial.println((String)"Return: " + _utils.getResString());
             _utils.updateResString("");  
             client.stop();
          }  
        }
      }
    }
}


void ArduControllerEthernet::putCustomWidgetValues(uint8_t widgetId, float value1, float value2, float value3, float value4, float value5, float value6){
	_utils.putBundleValues(widgetId, value1, value2, value3, value4, value5, value6);
}

