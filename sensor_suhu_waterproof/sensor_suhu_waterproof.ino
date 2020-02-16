#include <OneWire.h>
#include <DallasTemperature.h>
 
// sensor diletakkan di pin 2
#define ONE_WIRE_BUS 2
 
// setup sensor
OneWire oneWire(ONE_WIRE_BUS);
 
// berikan nama variabel,masukkan ke pustaka Dallas
DallasTemperature sensorSuhu(&oneWire);

//untuk sensor heartRate

int sensorHeart=A0;
 
float suhuSekarang;
float heart;
 
void setup(void) {
  Serial.begin(9600);
  sensorSuhu.begin();
  pinMode(sensorHeart, INPUT);
}
 
void loop(void) {  
  suhuSekarang = ambilSuhu();
  heart=analogRead(sensorHeart);
  
  Serial.print("Suhu Sekarang adalah ");
  Serial.print(suhuSekarang);
  Serial.print(" C dan detak jantungny adalah ");
  Serial.println(heart);  
  delay(1000);
}
 
float ambilSuhu() {
   sensorSuhu.requestTemperatures();
   float suhu = sensorSuhu.getTempCByIndex(0);
   return suhu;
}
