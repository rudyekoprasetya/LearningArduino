#include <ArduControllerEthernet.h>
#include <StateOfLife.h>


//Ethernet settings
byte mac[] = {0x84, 0xA0, 0xB5, 0xEF, 0x1E, 0xED};
byte ip[] = {192, 168, 1, 10}; 
byte gateway[] = {192, 168, 1, 254};  
byte subnet[] = {255, 255, 255, 0};  
int port = 80; 



ArduControllerEthernet arduControllerEthernet(mac, ip, gateway, subnet, port);
StateOfLife stateOfLife(2); //state led connected to pin 2





void setup() {
  arduControllerEthernet.begin();
}

void loop() {
  arduControllerEthernet.communication();
  //The led flashes. Fixed led notify Arduino error (Reset needed)
  stateOfLife.pulse(); //
}