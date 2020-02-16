int LEDMerah=5;
int LEDBiru=3;
int LEDKuning=2;
int perintah;

void setup () {
  pinMode(LEDMerah, OUTPUT);
  pinMode(LEDBiru, OUTPUT);
  pinMode(LEDKuning, OUTPUT);
  Serial.begin(9600); //untuk bluetooth
}

void loop () {
  if(Serial.available() > 0){     
      perintah = Serial.read(); //membaca data yang dikirm di bluetooth   
    
  if(perintah == '1') { //untuk perintah LED MERAH
    digitalWrite(LEDMerah, HIGH);
    digitalWrite(LEDBiru, LOW);
    digitalWrite(LEDKuning, LOW);
  } else if (perintah == '2') { //untuk perintah LED BIRU
    digitalWrite(LEDMerah, LOW);
    digitalWrite(LEDBiru, HIGH);
    digitalWrite(LEDKuning, LOW);
  } else if (perintah == '3') { //untuk perintah LED KUNING
    digitalWrite(LEDMerah, LOW);
    digitalWrite(LEDBiru, LOW);
    digitalWrite(LEDKuning, HIGH);
  } else if (perintah == '4') { //untuk perintah NYALA SEMUA
    digitalWrite(LEDMerah, HIGH);
    digitalWrite(LEDBiru, HIGH);
    digitalWrite(LEDKuning, HIGH);
  } else if (perintah == '5') { //untuk perintah MATI SEMUA
    digitalWrite(LEDMerah, LOW);
    digitalWrite(LEDBiru, LOW);
    digitalWrite(LEDKuning, LOW);
  }
  
 } 
  
}
