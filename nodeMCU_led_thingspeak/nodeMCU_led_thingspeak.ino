//header untuk Wifi dan thingspeak
#include <WiFi.h>
#include <ThingSpeak.h>

//setting akses ke Hotspot
const char *ssid = "Front Office";
const char *password = "smktipnluarbiasa";

//untuk channel ID thingspeak
unsigned long mychannel = 803608;
const char *apikey= "54DY12JBGAFELPLL";

//Led
unsigned int led = 2;

//konfigurasi client thingspeak
WiFiClient  client;

void setup() {
  Serial.begin(115200);    
  //led setup
  pinMode(led, OUTPUT);
  // wifi setup
  WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  } 
  Serial.println("");
  Serial.println("WiFi Connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());

  //inisialisasi thingspeak
  ThingSpeak.begin(client);
}

void loop() {
  // put your main code here, to run repeatedly:
  //inisialisasi nilai yang dikirimkan dan nomor field di thingspeak
  /*int nilai = 1;
  int field = 1;
  //mengirim data ke channel thingspeak
  int x = ThingSpeak.writeField(mychannel, field, nilai, apikey);
  if(x == 200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
 nilai++;*/

   //membaca data dari thingspeak
   int hasilLed = ThingSpeak.readFloatField(mychannel, 1, apikey);
   Serial.println(hasilLed);
   if (hasilLed == 1) { //jika data dari postman 1 maka led menyala
    digitalWrite(led, HIGH); 
   } else { //jika data dari postman 2 maka led mati
    digitalWrite(led, LOW); 
   }
  delay(2000);
}
