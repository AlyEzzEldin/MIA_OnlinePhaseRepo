#define pinEncoderA 2
#define pinEncoderB 3

long counter = 0;


void setup() 
{
  pinMode(pinEncoderA,INPUT_PULLUP);
  pinMode(pinEncoderB,INPUT_PULLUP);

  attachInterrupt(pinEncoderA,ISR_pinEncoderA,CHANGE);
  attachInterrupt(pinEncoderB,ISR_pinEncoderB,CHANGE);

  Serial.begin(9600);
}

void loop() 
{
    Serial.print("Position : ");
    Serial.println(counter);
}


void ISR_pinEncoderA(void)
{
  if(digitalRead(pinEncoderA) != digitalRead(pinEncoderB))
  {
    counter ++;
  }
  else
  {
    counter --;
  }
}

void ISR_pinEncoderB(void)
{
  if(digitalRead(pinEncoderA) == digitalRead(pinEncoderB))
  {
    counter ++;
  }
  else
  {
    counter --;
  }
}
