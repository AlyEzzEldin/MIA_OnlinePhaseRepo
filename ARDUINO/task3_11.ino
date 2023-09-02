#include <Wire.h>

const int BTN1 = 2;
const int BTN2 = 4;

void setup()
{
  Wire.begin();
  pinMode(BTN1,INPUT);
  pinMode(BTN2,INPUT);
}

void loop()
{
  int buttonState1 = digitalRead(BTN1);
  int buttonState2 = digitalRead(BTN2);

  Wire.beginTransmission(8);  
  Wire.write(buttonState1);
  Wire.write(buttonState2);
  Wire.endTransmission();

  delay(100);
}