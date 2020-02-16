#include <ArduControllerBluetooth.h>

uint8_t btRxPin = 10;
uint8_t btTxPin = 11;
int btBaudRate = 9600;

ArduControllerBluetooth arduControllerBluetooth(btRxPin, btTxPin, btBaudRate);

void setup() {
  arduControllerBluetooth.begin();  
  arduControllerBluetooth.sendATCommand("AT+NAMEArduinoBT"); //[OPTIONAL] You can change the name of your module here (ArduinoBT). No spaces allowed.
}

void loop() {
  arduControllerBluetooth.communication();  
}

