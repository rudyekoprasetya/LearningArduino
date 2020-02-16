#include <ArduControllerEthernet.h>



byte mac[] = {0x84, 0xA0, 0xB5, 0xEF, 0x1E, 0xED}; // mac address
byte ip[] = {192, 168, 1, 10};                     // ip address
byte gateway[] = {192, 168, 1, 1};                 // address router
byte subnet[] = {255, 255, 255, 0};                // subnet mask
int port = 80;                                     // server port


/*
 Note:
 Arduino communicates with both the W5500 and SD card using the SPI bus (through the ICSP header). 
 This is on digital pins 10, 11, 12, and 13 on the Uno and pins 50, 51, and 52 on the Mega. 
 On both boards, pin 10 is used to select the W5500 and pin 4 for the SD card. 
 These pins cannot be used for general I/O.
  
 On the Mega, the hardware SS pin, 53, is not used to select either the W5500 or the SD card, 
 but it must be kept as an output or the SPI interface won't work.
 */



ArduControllerEthernet arduControllerEthernet(mac, ip, gateway, subnet, port);


void setup() {
  // put your setup code here, to run once:
  arduControllerEthernet.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  arduControllerEthernet.communication();
}
