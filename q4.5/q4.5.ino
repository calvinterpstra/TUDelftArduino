int motor_pin = 9;
int led_pin = 13;

void forward(int power)
{
    analogWrite(motor_pin, power);
}

void setup()
{
    Serial.begin(9600);
    pinMode(motor_pin, OUTPUT);
}

void loop()
{
    int i;
    for (i = 0; i <= 10; i++)
    {
        forward(i * 0.1 * 255);
        delay(500);
    }
    for (i = 9; i > 0; i--)
    {
        forward(i * 0.1 * 255);
        delay(500);
    }
}
