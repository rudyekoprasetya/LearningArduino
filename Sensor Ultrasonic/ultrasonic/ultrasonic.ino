int penerima=2; //untuk echo
int pemancar=4; //untuk triger
int led3=3; //untuk LED indikator
//int buzz=5; //untuk buzzer
long sinyal, jarak; //variabel untuk menghitung jarak

void setup() {
  pinMode(penerima,INPUT); //untuk echo
  pinMode(pemancar,OUTPUT); //untuk triger
  pinMode(led3,OUTPUT);//untuk indikator
  //pinMode(buzz,OUTPUT);//untuk buzzer
  Serial.begin(9600);
}

void loop() {
  //untuk memancarkan suara ultrasonic
  digitalWrite(pemancar, LOW);
  delayMicroseconds(5);
  digitalWrite(pemancar, HIGH);
  delayMicroseconds(10);
  digitalWrite(pemancar, LOW);
  
  sinyal=pulseIn(penerima, HIGH); //menerima pantulan pemancar
  jarak=(sinyal/2)/29.1; //konversi dalam cm

    
  //jika jarak <15 maka lampu nyala
  if (jarak<15) {
    digitalWrite(led3, HIGH);
    //digitalWrite(buzz, HIGH);
    //tone(buzz,4000);
    //delay(200);
  } else {
    digitalWrite(led3, LOW);
    //tone(buzz,-2);
    //delay(200);
  }
  
  //tampilkan jarak pada monitor 
  Serial.print("jarak Benda adalah ");
  Serial.print(jarak); 
  //Serial.print(sinyal);
  Serial.println(" cm"); 
  //Serial.println();
  delay(500); 
}

