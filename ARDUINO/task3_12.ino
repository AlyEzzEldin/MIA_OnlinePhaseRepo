#include <Wire.h>

const int ledPin = 3;  

void setup()
{
  pinMode(ledPin, OUTPUT);
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  Serial.println("Slave");
}

void loop()
{
  
}

void receiveEvent(int numBytes) //receiveEvent Fuction should take one parameter and it is number of bytes that the controller read
{
  if (numBytes <= 2)
  {
    int buttonState1 = Wire.read();
    int buttonState2 = Wire.read();

    if (buttonState1 == LOW&&buttonState2==LOW)
    {
      digitalWrite(ledPin, LOW);
      Serial.println(" ");
    }
    else if (buttonState1 == HIGH&&buttonState2==LOW)
    {
      analogWrite(ledPin, 127);
      Serial.println("Vector focused");
    }

    else if (buttonState1 == LOW&&buttonState2==HIGH)
    {
      analogWrite(ledPin, 192);  // Set LED intensity to 50% (0-255 range)
      Serial.println("Vector distracted");
    }
    else if(buttonState1 == HIGH&&buttonState2==HIGH)
    {
      digitalWrite(ledPin, HIGH);
      Serial.println("Glitch");
    }
  }
}