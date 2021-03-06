#include <Servo.h>

Servo myservo;

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
int posX = 60;
int posY = 90;
unsigned long time;
unsigned long timeOffest;

void updateTimer(){
    time = millis() - timeOffest;
}

void resetTimer(){
    timeOffest = millis();
    // Serial.println(timeOffest);
}

char getNextState(){
    int incomingByte = 0;
    if (Serial.available() > 0) {
        incomingByte = Serial.read();
        return char(incomingByte);
    }
}

char updateState(char state){
    char nextState = getNextState();
    switch (state){
        case 'R':
            if (nextState == 'S' || nextState == 'B'){
                resetTimer();
                return nextState;
            } else { return state; }
            break;
        case 'S':
            if (nextState == 'F' || nextState == 'R'){
                resetTimer();
                return nextState;
            } else { return state; }
            break;
        case 'F':
            if (nextState == 'S'){
                resetTimer();
                return nextState;
            } else { return state; }
            break;
        case 'B':
            if (nextState == 'R' || nextState == 'W'){
                resetTimer();
                return nextState;
            } else { return state; }
            break;
        case 'W':
            if (nextState == 'R'){
                resetTimer();
                return nextState;
            } else { return state; }
            break;
        default:
            return state; 
            break;
    }
}

void Rest(){
    // Serial.println("Rest");
    myservo.write(posX);            // tells servo to go to position X
    digitalWrite(13,LOW);           // LED off
}

void Step(){
    // Serial.println("Step");
    if(time < 1000){
        myservo.write(posX);           // tell servo to go to position X
    }
    else if(time < 2000){
        myservo.write(posY);           // tell servo to go to position Y
    }
    else { resetTimer(); }
}

int Analog2Angle(int analogInput){
    return analogInput/(1023/180);
}

void Follow(){
    // Serial.println("Follow");
    int v = analogRead(A0);
    // Serial.println(Analog2Angle(v));
    myservo.write(Analog2Angle(v));
}

void Blink(){
    // Serial.println("Blink");
    if (time < 1000){
        digitalWrite(13,HIGH);
    }

    if (time < 2000){
        digitalWrite(13,LOW);
    }

    else {
        resetTimer();
    }
}

void Switch(){
    // Serial.println("Switch");
    int OnOff = digitalRead(2);

    if (OnOff == LOW) {
        digitalWrite(13,LOW);
    }
    else {
        digitalWrite(13,HIGH);
    }
}

void setup() {
  Serial.begin(9600);
  myservo.attach(3);
  digitalWrite(13,LOW);
  pinMode(2,INPUT);
  digitalWrite(2, HIGH);
}

char state = 'R';
void loop() {
    updateTimer();
    switch (state) {
        case 'R':
            Rest();
            break;
        case 'S':
            Step();
            break;
        case 'F':
            Follow();
            break;
        case 'B':
            Blink();
            break;
        case 'W':
            Switch();
            break;
        default:
            Serial.print("default: ");
            Serial.println(state);
            break;
    }
    state = updateState(state);
}
