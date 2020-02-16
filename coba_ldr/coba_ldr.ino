int ledkuning=2; //digital 2
int sensor=A0; //analog 0
int hasil; //untuk hasil sensor

void setup() {
  pinMode(ledkuning, OUTPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  //kita tampung hasil sensor
  hasil=analogRead(sensor);
  Serial.println(hasil);
  delay(500);
 
  if(hasil<100) {
    digitalWrite(ledkuning, HIGH);
  } else if(hasil>100){
    digitalWrite(ledkuning, LOW);
    
  }
 

}
