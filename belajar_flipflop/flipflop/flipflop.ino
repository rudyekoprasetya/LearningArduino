int led2 = 3;
int led1 = 5;
int led3 = 2;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop () {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  delay(500);
  //digitalWrite(led1, LOW);
  //digitalWrite(led2, HIGH);
  //digitalWrite(led3, LOW);
  //delay(500);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  delay(500);
}
