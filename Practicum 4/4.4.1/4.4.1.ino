int motor[] = {9, 10};

void forward(){
digitalWrite(motor[0], HIGH);
digitalWrite(motor[1], LOW);
}

void backward(){
digitalWrite(motor[0], LOW);
digitalWrite(motor[1], HIGH);
}

void stop_motor(){
digitalWrite(motor[0], LOW);
digitalWrite(motor[1], LOW);
}

void setup() {
Serial.begin(9600);

int i;
for(i = 0; i < 2; i++){
pinMode(motor[i], OUTPUT);
}

}

void loop() {

forward();
delay(2000);
stop_motor();
Serial.println("1");

backward();
delay(2000);
stop_motor();
}
