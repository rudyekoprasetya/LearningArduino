int relay1=6;
int relay2=7;
void setup() {
  // put your setup code here, to run once:
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, LOW);
  delay(3000);
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, HIGH);
  delay(3000);

}
