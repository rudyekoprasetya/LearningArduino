#include <Servo.h> 

Servo myservo;  //buat object servo untuk project

int pos=0; //variable untuk memuat posisi servo

int pinServo=9; //PIN 9 untuk Servo 

void setup() {
  myservo.attach(pinServo);
}

void loop() {
  myservo.write(0);
  delay(1000);
  myservo.write(45);
  delay(1000);
  myservo.write(90);
  delay(1000);
  myservo.write(180);
  delay(1000);
}
