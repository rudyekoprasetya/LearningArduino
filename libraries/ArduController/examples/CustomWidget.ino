#include <ArduControllerEthernet.h>

//Used only for DS3231 in this example
#include <Wire.h>
#include "RTClib.h" //https://github.com/adafruit/RTClib


//ethernet settings
byte mac[] = {0x84, 0xA0, 0xB5, 0xEF, 0x1E, 0xED};
byte ip[] = {192, 168, 1, 74};
byte gateway[] = {192, 168, 1, 254};
byte subnet[] = {255, 255, 255, 0};
int port = 80;



ArduControllerEthernet arduControllerEthernet(mac, ip, gateway, subnet, port);
RTC_DS3231 rtc; //RTC object (Used only for DS3231 in this example)


void setup() {
  arduControllerEthernet.begin();
  
  Wire.begin(); // Start the I2C interface (Used only for DS3231 in this example)
  if (rtc.lostPower()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // sets the RTC to the date & time this sketch was compiled
  }
}

void loop() {
  
      DateTime dt = rtc.now(); //DateTime object (Used only for DS3231 in this example)

      /*  Configuration of custom widget
       *  You can add 6 custom widgets: CUSTOM_WIDGET_1, CUSTOM_WIDGET_2...
       *  putCustomWidgetValues(widgetId, value1, value2, value3, value4, value5, value6)
       */
      arduControllerEthernet.putCustomWidgetValues(CUSTOM_WIDGET_1, dt.year(), dt.month(), dt.day(), dt.hour(), dt.minute(), dt.second());

      arduControllerEthernet.communication();
}
