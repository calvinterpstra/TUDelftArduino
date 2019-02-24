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
  
  Serial.println(Analog2Angle(v));
  myservo.write(Analog2Angle(v));
  }
