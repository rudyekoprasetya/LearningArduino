int sensorTanah=15;
int ledMerah=2;
float kelembaban;

void setup() {
  pinMode(sensorTanah, INPUT);
  pinMode(ledMerah, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //untuk LED kedap-kedip
 if(kelembaban>330)
 {
 digitalWrite(ledMerah, HIGH);
 delay(1000);
 }
 else
 {
 digitalWrite(ledMerah, LOW);
 delay(1000);
 }
 
 kelembaban=analogRead(sensorTanah);


 Serial.print("Nilai Kelembaban adalah = ");
 Serial.println(kelembaban);
}
