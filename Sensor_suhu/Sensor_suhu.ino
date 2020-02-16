int sensorsuhu=A1; //port untuk sensor LM35 A0
int buzzer=2; //untuk speaker
int LED=3; //untuk lED
int kipas=5; //untuk kipas
float nilai=0;
int perintah=0;

void setup() {
  Serial.begin(9600); //komunikasi dengan komputer
  pinMode(sensorsuhu, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(kipas, OUTPUT);
}

void loop() {
  nilai=analogRead(sensorsuhu);
  nilai=ceil(nilai/2.0479);
  if(Serial.available() > 0) {
     perintah=Serial.read();
     analogWrite(kipas, perintah);
  }
  
  
  if(nilai>=38) { //jika suhu ruangan mencapai 38 derajat lebih 
    digitalWrite(buzzer, HIGH);
    tone(buzzer,4000);    
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
    tone(buzzer,-1); 
    digitalWrite(LED, LOW);
  }
  Serial.print(nilai);
  Serial.println(' ');
  delay(1000);
}
