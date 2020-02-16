int sensorKetAir=A0;
int ledMerah=2;
float tinggi;

void setup() {
  pinMode(sensorKetAir, INPUT);
  pinMode(ledMerah, OUTPUT);
  Serial.begin(9600);
}

void loop() {
 if(tinggi>280)
 {
   digitalWrite(ledMerah,HIGH);
   delay(1000);
 }
 else
 {
   digitalWrite(ledMerah,LOW);
   delay(1000);
 }
 
 tinggi=analogRead(sensorKetAir);
 
 
 Serial.print("Nilai Ketinggian Adalah = ");
 Serial.println(tinggi);
 delay(1000);
}
