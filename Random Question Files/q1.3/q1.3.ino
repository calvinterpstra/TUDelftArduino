void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT);
  digitalWrite(2, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int OnOff = digitalRead(2);

  if (OnOff == LOW) {
    digitalWrite(13,LOW);
  }
  else {
    digitalWrite(13,HIGH);
  }
}
