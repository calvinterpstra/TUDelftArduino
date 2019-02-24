#include <Servo.h>

Servo myservo;

int posX = 60;
int posY = 90;

void setup() {
  myservo.attach(3);
}

void loop() {
  myservo.write(posX);              // tell servo to go to position X
  delay(1000);                       // waits 1000ms for the servo to reach the position
  myservo.write(posY);              // tell servo to go to position Y
  delay(1000);                       // waits 1000ms for the servo to reach the position
  }