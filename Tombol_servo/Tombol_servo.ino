#include <Servo.h> 

Servo myservo;  //buat object servo untuk project
int pinServo=9; //PIN 9 untuk Servo 
const int Tombol=2;
const int LED=4;
//untuk menampung nilai tombol
int Button=0;

void setup() {
  myservo.attach(pinServo);
  pinMode(Tombol, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Button=digitalRead(Tombol);
  Serial.println(Button);
  
  if(Button==HIGH) {
    digitalWrite(LED,HIGH);
    myservo.write(90);
    delay(1000);
  } else {
    digitalWrite(LED,LOW);
    myservo.write(0);
    delay(1000);
  }
}
