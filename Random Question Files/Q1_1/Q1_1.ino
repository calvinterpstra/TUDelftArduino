#include <TimerOne.h>

void setup() {
  Timer1.initialize(32); //Initialize timer with a period of 32 us
  Timer1.pwm(9,0); // Use pin 9 for PWM
}

void loop() {
  if (isTime()){
    Timer1.setPwmDuty(9,analogRead(0)); //Sets the duty cycle to the analog value on pin 0
  }
}

bool isTime(){ //Checks if 300 us elapsed since the last call
  static unsigned long t0=0;
  static unsigned long t1=0;
  t1 = micros();
  bool res = (t1-t0)>300;
  if(res){
    t0 = t1;
  }
  return res;
}
