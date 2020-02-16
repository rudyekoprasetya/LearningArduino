int relay=3;
int perintah;

void setup() {
  // put your setup code here, to run once:
  pinMode(relay, OUTPUT);
  Serial.begin(9600); //untuk bluetooth
  digitalWrite(relay, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available() > 0) {
    perintah = Serial.read(); //membaca perintah dari serial

      if(perintah=='1') {
        digitalWrite(relay, HIGH);  
      } else {
        digitalWrite(relay, LOW);
      }
    
  }

}
