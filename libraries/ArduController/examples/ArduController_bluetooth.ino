#include <ArduControllerBluetooth.h>


/*
 Note:
 Not all pins on the Mega and Mega 2560 support change interrupts,
 so only the following can be used for RX:
 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69

 Not all pins on the Leonardo and Micro support change interrupts,
 so only the following can be used for RX:
 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI)

 On Arduino or Genuino 101 RX doesn't work on Pin 13
 */
 

uint8_t btRxPin = 10;
uint8_t btTxPin = 11;
int btBaudRate = 9600;

ArduControllerBluetooth arduControllerBluetooth(btRxPin, btTxPin, btBaudRate);


void setup() {
  // put your setup code here, to run once:
  arduControllerBluetooth.begin();
  arduControllerBluetooth.sendATCommand("AT+NAMEArduinoBT"); //[OPTIONAL] You can change the name of your module here (ArduinoBT). No spaces allowed.
}

void loop() {
  // put your main code here, to run repeatedly:
  arduControllerBluetooth.communication();
}
