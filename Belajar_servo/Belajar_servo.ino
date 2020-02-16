#include <Servo.h> 

Servo myservo;  //buat object servo untuk project

int pos=0; //variable untuk memuat posisi servo

int pinServo=9; //PIN 9 untuk Servo 

int button=2; //untuk tombol 

void setup() {
  pinMode(button,INPUT);
  myservo.attach(pinServo);  
   for(pos = 90; pos>=0; pos-=1) {                             
    myservo.write(pos);             
    delay(15); }
    delay(2215);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(button)==HIGH) {
    for(pos=90; pos>=0; pos-=1)   
      { myservo.write(pos);             
        delay(10);}
  } else {
    for(pos=0; pos<=80; pos+=1)   
      { myservo.write(pos);             
        delay(10);}    
  } 
}
