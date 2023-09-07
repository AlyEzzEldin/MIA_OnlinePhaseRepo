#include <Wire.h>

#define MPU_ADD 0x68
#define PWR_MGMT 0x6B
#define ACC_REG 0x3B

void setup() {
Wire.beginTransmission(MPU_ADD);
Wire.write(PWR_MGMT);
Wire.write(0x00);
Wire.endTransmission();
}

void loop() {
Wire.begin();
Wire.beginTransmission(MPU_ADD);
Wire.write(ACC_REG);
Wire.endTransmission();

Wire.requestFrom(MPU_ADD,14);

int16_t accX = Wire.read() << 8 | Wire.read();
int16_t accY = Wire.read() << 8 | Wire.read();
int16_t accZ = Wire.read() << 8 | Wire.read();

int16_t temperature = Wire.read() << 8 | Wire.read();

int16_t gyrX = Wire.read() << 8 | Wire.read();
int16_t gyrY = Wire.read() << 8 | Wire.read();
int16_t gyrZ = Wire.read() << 8 | Wire.read();
}
