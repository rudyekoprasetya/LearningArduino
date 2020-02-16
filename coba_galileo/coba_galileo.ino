int led = 3;
int buzz = 2;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(led, HIGH);
 tone(buzz,500);
 delay(1000);
 digitalWrite(led, LOW);
 tone(buzz,-2);
 delay(1000);
}
