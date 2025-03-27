//third: capacity touch
int touch = 7;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(touch,INPUT);
}

void loop() {
  Serial.println(touchRead(touch));
  delay(500);
  // put your main code here, to run repeatedly:

}