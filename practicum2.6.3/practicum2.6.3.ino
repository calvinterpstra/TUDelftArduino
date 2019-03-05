void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int v = analogRead(A0);
  int voltage = map(v, 0, 1023, 0, 5000);
  Serial.println(voltage); 
  delay(500);              
}
