int echo=2;
int trigger=3;
char perintah;
long jarak, sinyal;

void setup() {
  pinMode(echo, INPUT);
  pinMode(trigger, OUTPUT);
  Serial.begin(9600);
}


void loop() {
        
        //Serial.println(jarak);
  if(Serial.available() > 0 ) {
    perintah=Serial.read();
    if(perintah == 'a') {
       //untuk memancarkan suara ultrasonic
          while(perintah<99) {
            digitalWrite(trigger, LOW);
            delayMicroseconds(5);
            digitalWrite(trigger, HIGH);
            delayMicroseconds(10);
            digitalWrite(trigger, LOW);
            
            sinyal=pulseIn(echo, HIGH); //menerima pantulan pemancar
            jarak=(sinyal/2)/29.1; //konversi dalam cm
            Serial.println(jarak);
            delay(500);
          }
    } else if (perintah=='c') {  
          Serial.println('buka kunci');
          delay(50);
       
    }       
  } 

}

