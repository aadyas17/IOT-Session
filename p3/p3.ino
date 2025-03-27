//second
int led=LED_BUILTIN;
void setup() {
pinMode(led, OUTPUT);
}

void loop() {
digitalWrite(led, HIGH);
Serial.println("Led is ON");
delay(2000);
digitalWrite(led, LOW);
Serial.println("Led is OFF");
delay(2000);
}


