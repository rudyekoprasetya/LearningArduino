int merah = 3;
int biru = 2;
int kondisi;
int sensor = A0;
int cahaya;

void setup() {
pinMode (biru, OUTPUT);
pinMode (merah, OUTPUT);
pinMode (sensor, INPUT);
Serial.begin(9600);
}

void loop() {
  cahaya = analogRead(sensor);
  Serial.println(cahaya);
  kondisi=0;
  
   
  if (cahaya <= 50){
      digitalWrite(merah, HIGH);
      digitalWrite(biru, HIGH);
                      }
                      
  else  if (cahaya >= 50){
      digitalWrite(merah, HIGH);
      delay (500);
      digitalWrite(merah, LOW);
      digitalWrite(biru, HIGH);
      delay (500);
      digitalWrite(biru, LOW); }
      
  
 if (Serial.available() > 0)
  { 
    kondisi=0;
    kondisi = Serial.parseInt();
     
    if (kondisi == 1 && cahaya <= 50){
      
      digitalWrite(merah, LOW);
      digitalWrite(biru, LOW);
      delay (3000);
                          }
      
      else  if (kondisi == 1 && cahaya >= 50){
      
      digitalWrite(merah, HIGH);
      digitalWrite(biru, HIGH);
      delay (3000);
    }
      
      
  }
 
  
    
    
    
  }


