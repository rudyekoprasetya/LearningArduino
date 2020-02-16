int sensorHeart=A0;
float detak;

void setup() {
  pinMode(sensorHeart, INPUT);
  Serial.begin(9600);
}

void loop() {
 detak=analogRead(sensorHeart);
 Serial.print("Nilai Detak Jantung  = ");
 Serial.println(detak);
 delay(1000);
}
