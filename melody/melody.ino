const int trigPin = 7;   // Trigger pin for ultrasonic sensor
const int echoPin = 8;   // Echo pin for ultrasonic sensor
const int buzzPin = 6;   // Buzzer pin

long duration;
int distance;

// Define Jingle Bells melody notes and durations
int melody[] = {  
  330, 330, 330, 330, 330, 330, 330, 392, 262, 294, 330, 
  349, 349, 349, 349, 349, 330, 330, 330, 330, 294, 294, 330, 294, 392
};
int noteDurations[] = {  
  4, 4, 2, 4, 4, 2, 4, 4, 4, 4, 2,  
  4, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 2, 2
};

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Measure distance using ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  
  Serial.print("Distance: ");
  Serial.println(distance);
  
  // If distance < 5 cm, play Jingle Bells melody
  if (distance < 5) {
    for (int i = 0; i < 25; i++) {
      int noteDuration = 1000 / noteDurations[i];  
      tone(buzzPin, melody[i], noteDuration);  
      delay(noteDuration * 1.3);  
    }
    delay(2000);  // Pause before checking distance again
  } 
  else {
    noTone(buzzPin);  // Stop buzzer when no object is close
  }

  delay(500);
}
