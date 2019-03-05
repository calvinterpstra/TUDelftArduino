void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int v = analogRead(A0);
  int voltage = map(v,0,1023,5000,0);
  Serial.println(voltage); 
  delay(500);              
}
