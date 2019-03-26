#include <TimerOne.h>
#include <math.h>

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

float first_filt(float x0){
  static float y1=0;  // y[n-1]
  static float x1=0;  // x[n-1]
  
  float k_x0 = 0.31353; // 0.6507
  float k_x1 = 0.31353; // 0.6507
  float k_y1 = 0.37293; // -0.3013

  float y0 = k_x0*x0 + k_x1*x1 + k_y1*y1; // TODO: Fill in this line

  y1 = y0;  // Shift y[n] to y[n-1]
  x1 = x0;  // Shift x[n] to x[n-1]
  
  return y0;
}

float second_filt(float x0){
  static float y1=0;  // y[n-1]
  static float y2=0;  // y[n-2]
  static float x1=0;  // x[n-1]
  static float x2=0;  // x[n-2]
  
  float k_x0 = ; // 
  float k_x1 = ; // 
  float k_y1 = ; // 
  float k_x2 = ; // 
  float k_y2 = ; // 

  float y0 = k_x0*x0 + k_x1*x1 + k_y1*y1 + k_x2*x2 + k_y2*y2; // TODO: Fill in this line
  
  // Shift values
  y2 = y1;  // Shift y[n-1] to y[n-2]
  y1 = y0;  // Shift y[n] to y[n-1]
  x2 = x1;  // Shift x[n-1] to x[n-2]
  x1 = x0;  // Shift x[n] to x[n-1]
  
  return y0;
}


void setup() {
  Timer1.initialize(32); //Initialize timer with a period of 32 us
  Timer1.pwm(9,0); // Use pin 9 for PWM
}

void loop() {
  if (isTime()){
    float filtered = first_filt(analogRead(0));
    Timer1.setPwmDuty(9, filtered); //Sets the duty cycle to the analog value on pin 0
  }
}