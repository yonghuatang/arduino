#include <MPU6050.h>
#include <Wire.h>
#include <I2Cdev.h>

MPU6050 mpu;
float rawGyro[] = mpu.readRawGyro();
Vector normGyro = mpu.readNormalizeGyro();

void setup() {
    Serial.begin();
    delay(500);
}

void loop() {
    Serial.print("Xraw = "); Serial.println(rawGyro.XAxis);
    Serial.print("Yraw = "); Serial.println(rawGyro.YAxis);
    Serial.print("Zraw = "); Serial.println(rawGyro.ZAxis);
    delay(750);
}
