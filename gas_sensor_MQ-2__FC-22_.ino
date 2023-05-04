int analog_gas_pin = A7;

void setup() {
  Serial.begin(9600);

  pinMode(analog_gas_pin, INPUT);
}

void loop() {
 int gas_value = analogRead(analog_gas_pin);

 Serial.print("gas value: ");
 Serial.print(gas_value);
 Serial.println(" PPM of gas");

 delay(1000);
}
