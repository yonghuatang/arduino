#include <Servo.h>

Servo myServo;

void setup() {
    myServo.attach(2);
    Serial.begin(9600);
}

void loop() {
    for (int i=0; i<=180; ++i) {
        myServo.write(i);
        Serial.print("Servo position: ");
        Serial.println(i);
        delay(50);
    }
    for (int i=180; i>=0; --i) {
        myServo.write(i);
        Serial.print("Servo position: ");
        Serial.println(i);
        delay(50);
    }
}
