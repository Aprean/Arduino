//asi 3,3 V, ale idk
const int pingPin = 7; // Trigger Pin
const int echoPin = 6; // Echo Pin

void setup() {
   Serial.begin(9600);
   pinMode(pingPin, OUTPUT);
   pinMode(echoPin, INPUT);
}

void loop() {
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
 
   int duration = pulseIn(echoPin, HIGH);
   int cm = duration / 29 / 2; // převést čas na cm
   //2 je jakoože půlení času
   //29 je asi rychlost, úpravou se nastaví dálka
   
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(100);
}
