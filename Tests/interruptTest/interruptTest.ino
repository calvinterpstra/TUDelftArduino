const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink,  FALLING);
}

void loop() {
  digitalWrite(ledPin, state);
  if(state == LOW){
    Serial.println("0");
  } else {
    Serial.println("1");
  }
}

void blink() {
  state = !state;
} 
