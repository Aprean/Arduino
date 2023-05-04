int buzz_pin = 2;
int pot_pin = A7;

void setup() {
  Serial.begin(9600);
  pinMode(pot_pin, INPUT);
  pinMode(buzz_pin, OUTPUT);
  digitalWrite(buzz_pin, LOW);
}

void loop() {
  long value = analogRead(pot_pin)*2;
  Serial.println(value);
  tone(buzz_pin, value, 500); //pravouhly ton po dobu nějakou
  delay(500);
  noTone(buzz_pin); //stop tone
}
