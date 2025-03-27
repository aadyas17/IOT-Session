const int trigPin = 7;
const int echoPin = 8;
const int buzzPin = 6;
long duration;
int distance;
void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = duration * 0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance < 5){
    digitalWrite(buzzPin, HIGH);
  }
  else{
    digitalWrite(buzzPin, LOW);
  }
  delay(500);
}


//pin 6, when distance less tha 5 it buzzes 