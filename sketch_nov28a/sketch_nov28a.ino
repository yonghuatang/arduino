#include <Servo.h>

Servo myservo;

void setup() {
    Serial.begin(9600);
    myservo.attach(10);
    myservo.write(0);
    delay(1500);
}

void loop() {
    rotate();
    delay(50);
}

void rotate() {
    for (int i=0; i<=180; ++i) {
        myservo.write(i);
        Serial.println(i);
        delay(50);
    }
    for (int i=180; i>=0; --i) {
        myservo.write(i);
        Serial.println(i);
        delay(50);
    }
}
