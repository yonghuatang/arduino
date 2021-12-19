// Suan Hui Pu - modified from Adafruit calibration example and combined with MPU-6050 short example by Arduino User JohnChi

#include<Wire.h>
const int MPU_addr=0x68;  // I2C address of the MPU-6050
int AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;  // raw sensor values
int AcXcal,AcYcal,AcZcal; // calibrated accelerometer values

// To calibrate the accelerometer, replace the zeros here with the minimum and maximum
// raw value read from the accelerometer (raw data ranges)
int AcXmin = 0;
int AcXmax = 10;
int AcYmin = 0;
int AcYmax = 10;
int AcZmin = -12600;
int AcZmax = 20500;

void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(115200);
}
void loop(){
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)     
  AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)

  // Calibration for accelerometer based on min and max values for each axis
  AcXcal = map(AcX, AcXmin, AcXmax, -1000, 1000);
  AcYcal = map(AcY, AcYmin, AcYmax, -1000, 1000);
  AcZcal = map(AcZ, AcZmin, AcZmax, -1000, 1000);
  
  Serial.print("AcX = "); Serial.print(AcX);
  Serial.print(" | AcY = "); Serial.print(AcY);
  Serial.print(" | AcZ = "); Serial.print(AcZ);
  Serial.print(" | AcXcal = "); Serial.print(AcXcal);
  Serial.print(" | AcYcal = "); Serial.print(AcYcal);
  Serial.print(" | AcZcal = "); Serial.print(AcZcal);
  Serial.print(" | Tmp = "); Serial.print(Tmp/340.00+36.53);  //equation for temperature in degrees C from datasheet
  Serial.print(" | GyX = "); Serial.print(GyX);
  Serial.print(" | GyY = "); Serial.print(GyY);
  Serial.print(" | GyZ = "); Serial.println(GyZ);
  delay(100);
}
