int LEDMerah=2;
int perintah;

void setup () {
  pinMode(LEDMerah, OUTPUT);
  Serial.begin(9600); //untuk bluetooth
}

void loop () {
  if(Serial.available() > 0){  
   
      perintah = Serial.read(); //membaca data yang dikirm di bluetooth   
    
  // perintah dari HP
  if(perintah == '1') { 
  digitalWrite(LEDMerah, HIGH);
    
  } else if (perintah == '2') { 
  digitalWrite(LEDMerah, LOW);  
  }
  
 } 
  
}
