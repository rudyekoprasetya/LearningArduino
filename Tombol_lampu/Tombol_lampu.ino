const int Tombol=2;
const int LED=4;

//untuk menampung nilai tombol
int Button=0;
void setup() {
  pinMode(Tombol, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Button=digitalRead(Tombol);
  Serial.println(Button);
  
  if(Button==HIGH) {
    digitalWrite(LED,HIGH);
  } else {
    digitalWrite(LED,LOW);
  }
}
