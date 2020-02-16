int LDR=A0; //pin Analog0
int LED2=2; //untuk LED Otomatis
int buzzer=3; //untuk buzzer
int hasilLDR; //hasil dari LDR


void setup() {
  Serial.begin(9600); //untuk komunikasi
  pinMode(LDR, INPUT); //untuk membaca sensor
  pinMode(LED2, OUTPUT); //untuk lampu otomatis
  pinMode(buzzer, OUTPUT); //untuk lampu otomatis
}

void loop() {
  hasilLDR=analogRead(LDR);
  Serial.print("Hasil dari LDR adalah ");
  Serial.println(hasilLDR);
  
  //jika intensitas cahaya kurang dari 150
  if(hasilLDR<=200) {
    digitalWrite(LED2, HIGH); //lampu nyala
    tone(buzzer,4000);
    Serial.println("Waktu Malam dan Lampu Nyala");
  } else {
    digitalWrite(LED2, LOW); //lampu nyala
    tone(buzzer,-1);
    Serial.println("Waktu Siang dan Lampu Mati");
  }
  delay(500);
}
