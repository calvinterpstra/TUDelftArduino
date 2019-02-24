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

void Rest(){
    Serial.println("Rest");
}

void Step(){
    Serial.println("Step");
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
