int incomingByte = 0;
char outgoingByte = 0;

void setup() {
        Serial.begin(9600);
}

void loop() {
        if (Serial.available() > 0) {
                incomingByte = Serial.read() + 1;

                if (incomingByte > 98 && incomingByte < 122){
                  Serial.println(char(incomingByte));
                }
                else if (incomingByte == 11){}
                else {
                  Serial.println("Invalid input");
                }
        }
}
 
