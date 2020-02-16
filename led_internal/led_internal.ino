//buat variable untuk pin mana yang dipake
int led=13;

void setup() {
  // setting pin itu OUTPUT atau INPUT
  pinMode(led, OUTPUT);
  //serial monitor untuk melihat perintah
  Serial.begin(9600);
}

void loop() {
 digitalWrite(led, HIGH); //LED MENYALA
 Serial.println("LED Menyala");
 delay(1000); //Jeda 1 detik
 digitalWrite(led, LOW); //LED MATI
 Serial.println("LED Mati");
 delay(1000);
}

