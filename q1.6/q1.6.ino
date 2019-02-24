#include <Servo.h>

Servo myservo;

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
int posX = 60;
int posY = 90;

char getNextState(){
    int incomingByte = 0;
    if (Serial.available() > 0) {
        incomingByte = Serial.read();
        if (incomingByte == 87 || incomingByte == 82 || incomingByte == 66 || incomingByte == 83 || incomingByte == 70){
            return char(incomingByte);
        }
    }
    else {
        return ;
    }
}

char updateState(state){
    nextState = getNextState();
    if (state == 'R'){
        if(){

        }
    }
}

void Rest(){
    Serial.println("Rest");
    myservo.write(posX);            // tells servo to go to position X
    digitalWrite(13,LOW);           // LED off
}

void Step(){
    Serial.println("Step");
    myservo.write(posX);           // tell servo to go to position X
    delay(1000);                   // waits 1000ms for the servo to reach the position
    myservo.write(posY);           // tell servo to go to position Y
    delay(1000);                   // waits 1000ms for the servo to reach the position
  }
}

void Follow(){
    Serial.println("Follow");
}

void Blink(){
    Serial.println("Blink");
}

void Switch(){
    Serial.println("Switch");
}

void setup() {
  Serial.begin(9600);
  myservo.attach(3);
  digitalWrite(13,LOW);
}

char state = 'R';
void loop() {
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
    state = getNextState();
    delay(100);
}
