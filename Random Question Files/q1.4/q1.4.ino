#include <Servo.h>

Servo myservo;

void setup() {
  myservo.attach(3);
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

int Analog2Angle(int analogInput){
  return analogInput/(1023/180);
}

void loop() {
  int v = analogRead(A0);
  
//  Serial.println(Analog2Angle(v));
  int voltage = map(v,0,1023,5000,0);
  int angle = map(v,0,1023,270,0);
  Serial.print(voltage);
  Serial.print(", ");
  Serial.print(angle);
  Serial.print(", ");
  Serial.println(v);
  delay(500);
  myservo.write(Analog2Angle(v));
  }
