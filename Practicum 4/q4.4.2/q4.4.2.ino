int motor[] = {9, 10};
int pot_pin = 0;
int button_pin = 1;
int led_pin = 13;

void forward(int power)
{
  analogWrite(motor[0], power);
  analogWrite(motor[1], 0);
}

void backward(int power)
{
  analogWrite(motor[0], 0);
  analogWrite(motor[1], power);
}

void stop_motor()
{
  digitalWrite(motor[0], LOW);
  digitalWrite(motor[1], LOW);
}

void setup()
{
  Serial.begin(9600);

  int i;
  for (i = 0; i < 2; i++)
  {
    pinMode(motor[i], OUTPUT);
  }
}

void loop()
{
  int val = analogRead(pot_pin);
  int power = map(val, 0, 1023, 0, 255);
  Serial.println(power);

  if (digitalRead(button_pin))
  {
    forward(power);
  }
  else
  {
    backward(power);
  }
  delay(25);
}
