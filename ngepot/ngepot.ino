//header untuk Wifi dan thingspeak
#include <WiFi.h>
//#include <ThingSpeak.h>
//header untuk DHT Sensor
#include <dht.h>
#define sensorDHT 2 //sensor DHT di pin D2
#define sensorTanah 15 //sensor tanah di pin 15
#define sensorCahaya 4 //sensor cahaya di pin 4

//setting akses ke Hotspot
const char *ssid = "Front Office";
const char *password = "smktipnluarbiasa";

//untuk channel ID thingspeak
/*unsigned long mychannel = 805457;
const char *apikey= "5CS2K0DUNVMRRUUY";

//konfigurasi client thingspeak
WiFiClient  client;*/

dht DHT;
//int sensorTanah=15; //sensor tanah di D15
//int sensorCahaya=4; //sensor cahaya di D4

int led=2;
float tanah;
float suhu;
float kelembaban;
float cahaya;

void setup() {
  pinMode(sensorTanah, INPUT);
  pinMode(led, OUTPUT);
  pinMode(sensorCahaya, INPUT);
  Serial.begin(115200);
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
  //ThingSpeak.begin(client);
}

void loop() {
  // menampung hasil ke variabel
  DHT.read11(sensorDHT);
  tanah = analogRead(sensorTanah);
  suhu = DHT.temperature;
  kelembaban = DHT.humidity;
  cahaya = analogRead(sensorCahaya);

  //membaca ke serial
  Serial.print("Kelembaban udara = ");
  Serial.print(kelembaban);
  Serial.println("% ");
  Serial.print("Suhu = ");
  Serial.print(suhu); 
  Serial.println(" C ");
  Serial.print("Kondisi tanah = ");
  Serial.println(tanah);
  Serial.print("Kondisi Cahaya = ");
  Serial.println(cahaya);
  Serial.println("");

  //mengirimkan ke thingspeak
  // set the fields with the values
//  ThingSpeak.setField(1, tanah);
//  ThingSpeak.setField(2, suhu);
//  ThingSpeak.setField(3, kelembaban);
//  ThingSpeak.setField(4, cahaya);
  
  // write to the ThingSpeak channel
  /*int x = ThingSpeak.writeFields(mychannel, apikey);
  if(x == 200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }*/

  //delay
  delay(5000);

}
