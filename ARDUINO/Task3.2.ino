#include <NewPing.h>

int trigPin1 = 2;   // Trigger pin for sensor 1 (0 degree)
int echoPin1 = 3;   // Echo pin for sensor 1  (0 degree)
int trigPin2 = 4;   // Trigger pin for sensor 2 (90 degree)
int echoPin2 = 5;   // Echo pin for sensor 2  (90 degree)
int trigPin3 = 6;   // Trigger pin for sensor 3 (180 degree)
int echoPin3 = 7;   // Echo pin for sensor 3  (180 degree)
int trigPin4 = 8;   // Trigger pin for sensor 4 (270 degree)
int echoPin4 = 9;   // Echo pin for sensor 4    (270 degree)

int maxRange = 800; // 8 meters

const float chamberWidth = 5.0; // in meters
const float chamberHeight = 6.0;

//(x, y) coordinates
float x = 0.0;
float y = 0.0;                                                                       

NewPing USS1(trigPin1, echoPin1, maxRange);
NewPing USS2(trigPin2, echoPin2, maxRange);
NewPing USS3(trigPin3, echoPin3, maxRange);
NewPing USS4(trigPin4, echoPin4, maxRange);

void setup() {                                                       
  Serial.begin(9600);
}

void loop() {
  int distance1 = USS1.ping_cm();  //0
  int distance2 = USS2.ping_cm();  //1
  int distance3 = USS3.ping_cm();  //5
  int distance4 = USS4.ping_cm();  //5

  x = chamberWidth-distance1;
  y = chamberHeight-distance2;

  Serial.print("Cookie Bot Position: ");
  Serial.print("X = ");
  Serial.print(x);
  Serial.print(" m, Y = ");
  Serial.print(y);
  Serial.println(" m");

  delay(1000);
}
