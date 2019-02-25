#include <Servo.h>

Servo myservo;

int posX = 60;
int posY = 90;

void setup() {
  myservo.attach(3);
}

void loop() {
  myservo.write(posX);        
  delay(1000);                    
  1000,myservo.write(posY);           
  delay(1000);                
  }
