// Modified from Adafruit stepper example

#include <AFMotor.h>

AF_Stepper motor(48, 2);  // create stepper motor object

void setup() {
    Serial.begin(9600);
    while (!Serial) {;}
    Serial.println("Stepper test!");
    motor.setSpeed(100);  // 100 rpm
    motor.step(10, FORWARD, SINGLE);
    motor.release();
    delay(1000);
}

void loop() {
    Serial.println("Single coil activation.");
    motor.step(12, FORWARD, SINGLE);
    delay(1000);
    motor.step(48, BACKWARD, SINGLE);
    delay(1000);
//     Serial.println("Double coil activation, higher torque!");
//     motor.step(48, FORWARD, DOUBLE);
//     delay(1000);
//     motor.step(48, BACKWARD, DOUBLE);
//     delay(1000);
//     Serial.println("Interleaved/Half-step activation, double resolution!");
//     motor.step(96, FORWARD, INTERLEAVE);
//     delay(1000);
//     motor.step(96, BACKWARD, INTERLEAVE);
//     delay(1000);
//     Serial.println("Microstep, smoother motion!");
//     motor.step(48, FORWARD, MICROSTEP);
//     delay(1000);
//     motor.step(48, BACKWARD, MICROSTEP);
//     delay(1000);
}
