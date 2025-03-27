#include <Wire.h>

void setup() {
Wire.begin();
Serial.begin(9600); 
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
Wire.requestFrom(8,6);
while(Wire.available()) {
  char c= Wire.read();
}
delay(500);
}
