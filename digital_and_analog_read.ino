int anal_pin = A7; //musí být analog pin
int digit_pin = 2; //pullup nebo down podle toho co je "default"

void setup() {
  Serial.begin(9600);

  pinMode(anal_pin, INPUT);
  pinMode(digit_pin, INPUT); //INPUT_PULLUP (PULLDOWN)
}

void loop() {
  int analog_value = analogRead(anal_pin);
  int digit_value =  digitalRead(digit_pin);

  Serial.print("analog value: ");
  Serial.println(analog_value);
  Serial.print("digital value: ");
  Serial.println(digit_value);

  delay(1000);
}
