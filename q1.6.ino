#include <Servo.h>

Servo myservo;

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void state1(){

}

void state2(){
    
}

void state3(){
    
}

void setup() {
  Serial.begin(9600);
  myservo.attach(3);
}

int state = 0;
void loop() {
    switch (state) {
        case 1:
            break;
        case 2:
            break;
        default:
            break;
    }
}