#include <TimerOne.h>

#define FREQUENCY 44141

float meas = 0;
float freq_meas = 0;
int count = 0;

void setup () {
	Serial.begin(9600);
	pinMode(9,OUTPUT);
}

void loop () {
	// Do the measurement and apply a ( digital ) filter

	meas = meas *0.999+0.001*((float)(analogRead(0)));
	freq_meas = freq_meas*0.995+0.005*((float)(analogRead(1)));
	// Once every 512 measurements :
	count ++;
	if (count %512 == 0) {
		unsigned int freq = map(freq_meas,0,1023,0.9*FREQUENCY,1.1*FREQUENCY); // Fill in appropriate values
		tone(9, freq ) ;
		Serial.print("Frequency: ");
//		Serial.print(freq);
		Serial.print(", Measurement: ") ;
		Serial.println(meas);
	}
}
